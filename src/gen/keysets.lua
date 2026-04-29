local c_grammar = require 'gen.c_grammar'
local hashy = require 'gen.hashy'

local map_type = require "gen.map_type"

local src = io.open "./deps/nvim/src/nvim/api/keysets_defs.h"
assert(src)
local src = src:read "*a"
local src = c_grammar.grammar:match(src)

---@param fields nvim.c_grammar.Keyset.Field[]
---@param name string
---@param map table<string, nvim.c_grammar.Keyset.Field>
---@param order string[]
local function gen_key_dict(fields, name, map, order)
  ---@type string[]
  local builder_members = {}
  ---@type string[]
  local members = {}

  vim.iter(fields)
      :skip(1)
  ---@param field nvim.c_grammar.Keyset.Field
      :each(function(field)
        table.insert(builder_members, ("  std::optional<%s> %s;\n"):format(map_type(field.type, "ref"), field.name))
        table.insert(members, ("  %s m_%s;\n"):format(map_type(field.type, "c"), field.name))
      end)

  ---@type string[]
  local getters = {}
  ---@type string[]
  local builder_args = {}

  vim.iter(order)
      :enumerate()
  ---@param index number
  ---@param key string
      :each(function(index, key)
        local field = map[key]
        local type = map_type(field.type, "ref")
        table.insert(builder_args, ([[
    if (%s.has_value()) {
      ret.m_%s = *%s;
      ret.m_mask |= std::uint64_t{1} << %d;
    }
]]):format(field.name, field.name, field.name, index))

        local getter_name = field.name
        if getter_name == name then getter_name = getter_name .. "_" end
        table.insert(getters, ([[
  std::optional<%s> %s() const noexcept {
    if (m_mask & std::uint64_t{1} << %d) {
      return m_%s;
    }
    return {};
  }
]]):format(type, getter_name, index, field.name))
      end)

  local builder = ([[
struct %s {
%s
  constexpr operator keysets::%s() const noexcept {
    keysets::%s ret{};
%s    return ret;
  }
};
]]):format(name, table.concat(builder_members), name, name, table.concat(builder_args))

  local definition = ([[
struct %s {
  uint64_t m_mask;
%s%s};
]]):format(name, table.concat(members), table.concat(getters))

  return builder, definition
end

local builders = {}
local definitions = {}

---@param fields table<string, nvim.c_grammar.Keyset.Field>
---@param ownership ownership
local function gen_members(fields, ownership)
  local members = {}
  for _, field in pairs(fields) do
    local type = map_type(field.type, ownership)
    table.insert(members, ("  %s %s;\n"):format(type, field.name))
  end
  return table.concat(members)
end

for _, x in ipairs(src) do
  if not x.keyset_name or not x.fields then goto continue end
  if x.fields[1].name ~= 'is_set__' .. x.keyset_name .. '_' then
    table.insert(builders, ([[
struct %s {
%s  constexpr operator keysets::%s() const noexcept {
    return {
      %s
    };
  }
};
]]):format(
      x.keyset_name,
      gen_members(x.fields, "ref"),
      x.keyset_name,
      vim.iter(x.fields)
      ---@param field nvim.c_grammar.Keyset.Field
      :map(function(field)
        return (".%s = %s,"):format(field.name, field.name)
      end)
      :join ""
    ))
    table.insert(definitions, ("struct %s {\n%s};"):format(x.keyset_name, gen_members(x.fields, "c")))
    goto continue
  end
  local keys = {}
  local fields = {}
  vim.iter(x.fields):skip(1):each(function(field)
    local key = field.dict_key or field.name
    table.insert(keys, key)
    fields[key] = field
  end)
  local order = hashy.hashy_hash(x.keyset_name, keys, function(idx) return idx end)
  local builder, view = gen_key_dict(x.fields, x.keyset_name, fields, order)
  table.insert(builders, builder)
  table.insert(definitions, view)
  ::continue::
end

io.stdout:write [[
#pragma once

#include <optional>
#include <nvpp/types.hh>

namespace nvpp::keysets {
extern "C" {
]]
vim.iter(definitions):each(function(x) io.stdout:write(x) end)
io.stdout:write "}\n}\n\n"

io.stdout:write "namespace nvpp::keysets::builder {\n"
vim.iter(builders):each(function(x) io.stdout:write(x) end)
io.stdout:write "}"
