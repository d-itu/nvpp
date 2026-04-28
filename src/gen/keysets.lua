local c_grammar = require 'gen.c_grammar'
local hashy = require 'gen.hashy'

local map_type = require "gen.map_type"

local src = io.open "./deps/neovim-0.12.1/src/nvim/api/keysets_defs.h"
assert(src)
local src = src:read "*a"
local src = c_grammar.grammar:match(src)

---@param name string
---@param fields table<string, nvim.c_grammar.Keyset.Field>
---@param order string[]
local function gen(name, fields, order)
  local members = vim.iter(order)
      ---@param key string
      :map(function(key)
        local field = fields[key]
        return ("  std::optional<%s> %s;\n"):format(map_type(field.type, "ref"), field.name)
      end)
      :totable()
  local build = vim.iter(order)
      :enumerate()
      ---@param index integer
      ---@param key string
      :map(function(index, key)
        local field = fields[key]
        return ([[
    if (%s.has_value()) {
      ret.%s = *%s;
      ret.is_set__%s_ |= OptionalKeys{1} << %d;
    }
]]):format(field.name, field.name, field.name, name, index)
      end)
      :totable()

  local getters = vim.iter(order)
      :enumerate()
      ---@param index integer
      ---@param key string
      :map(function(index, key)
        local field = fields[key]
        local ty = map_type(field.type, "ref")
        local getter_name = field.name
        if getter_name == name then getter_name = getter_name .. "_" end
        return ([[
  std::optional<%s> %s() const noexcept {
    if (is_set__%s_ & OptionalKeys{1} << %d) {
      return %s{static_cast<const Dict(%s) &>(*this).%s};
    }
    return {};
  }
]]):format(ty, getter_name, name, index, ty, name, field.name)
      end)
      :totable()

  local builder = {
    ("struct %s {\n"):format(name),
    members,
    ("  [[gnu::always_inline]] operator Dict(%s)() const noexcept {\n"):format(name),
    ("    auto ret = KeyDict_%s{};\n"):format(name),
    build,
    "    return ret;\n",
    "  }\n",
    "};\n",
  }
  local view = {
    ("struct %s: Dict(%s) {\n"):format(name, name),
    getters,
    "};\n",
  }
  return vim.iter(builder):flatten(1):join "",
      vim.iter(view):flatten(1):join ""
end

local builders = {}
local views = {}

for _, x in ipairs(src) do
  if not x.keyset_name or not x.fields then goto continue end
  if x.fields[1].name ~= 'is_set__' .. x.keyset_name .. '_' then
    local alias = ("using %s = Dict(%s);\n"):format(x.keyset_name, x.keyset_name)
    table.insert(views, alias)
    table.insert(builders, alias)
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
  local builder, view = gen(x.keyset_name, fields, order)
  table.insert(builders, builder)
  table.insert(views, view)
  ::continue::
end

io.stdout:write [[#pragma once
#include <optional>
#include <nvpp/types.hh>
namespace nvpp::keysets::builder {
]]
vim.iter(builders):each(function(x) io.stdout:write(x) end)
io.stdout:write "}\n"

io.stdout:write "namespace nvpp::keysets {\n"
vim.iter(views):each(function(x) io.stdout:write(x) end)
io.stdout:write "}"
