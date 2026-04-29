local c_grammar = require 'gen.c_grammar'

local map_type = require "gen.map_type"

local dir = "./deps/nvim/src/nvim/api"

---@param call_expr string
---@param has_err boolean
---@param return_void boolean
---@param has_arena boolean
---@return string
local function gen_body(call_expr, has_err, return_void, has_arena)
  local call_stmt = (return_void and "  %s;\n" or "  const auto ret = %s;\n"):format(call_expr)
  local release_arena = has_arena and return_void and "  arena.finish().free();\n" or ""
  local process_err = (has_err and {
    "  if (err.is_set()) {\n",
    "    return std::unexpected(err);\n",
    "  }\n",
  } or "")
  ---@type string
  local return_stmt
  if return_void then
    if has_err then
      return_stmt = "  return {};\n"
    else
      return_stmt = ""
    end
  else
    local result = "ret"
    if has_arena then
      result = ("arena.finish(%s)"):format(result)
    end
    return_stmt = ("  return %s;\n"):format(result)
  end
  return vim.iter {
    call_stmt,
    release_arena,
    process_err,
    return_stmt,
  }:flatten(1):join ""
end

---@param proto nvim.c_grammar.Proto
local function gen(proto)
  local f_name = proto.name:sub(6)
  local result_type = map_type(proto.return_type, "owned")
  local ret = result_type

  local err = ""
  local local_vars = {}
  local proto_params = {}
  local params = {}
  local args = {}
  local arena = ""

  for _, param in ipairs(proto.parameters) do
    local ty, name = unpack(param)
    if ty == "error" then
      err = "  auto err = error{};\n"
      table.insert(proto_params, "error *")
      table.insert(args, "&err")
      goto continue
    end
    if ty == "arena" then
      table.insert(proto_params, "arena *")
      table.insert(args, "&arena")
      arena = "  nvpp::arena arena{};\n"
      goto continue
    end
    if ty == "lstate" then
      table.insert(proto_params, "void *")
      table.insert(args, "nullptr")
      goto continue
    end
    if name == "channel_id" then
      table.insert(proto_params, "std::uint64_t")
      table.insert(args, "lua_internal_call")
      goto continue
    end
    local container = c_grammar.typed_container:match(ty)
    if container then
      local con, inner = unpack(container)
      if con == "Dict" then
        local dict_name = inner
        table.insert(local_vars, ("  keysets::%s %s_ = %s;\n"):format(dict_name, name, name))
        table.insert(proto_params, ("keysets::%s *"):format(dict_name))
        table.insert(params, ("keysets::builder::%s %s"):format(dict_name, name))
        table.insert(args, ("&%s_"):format(name))
        goto continue
      end
      -- if con == "Tuple" then
      --   table.insert(local_vars, ("  auto %s_ = array_from_tuple(%s);\n"):format(name, name))
      --   local fields = vim.iter(inner):join ", "
      --   table.insert(params, ("std::tuple<%s> %s"):format(fields, name))
      --   table.insert(args, ("array(%s_)"):format(name))
      -- end
    end
    table.insert(proto_params, map_type(ty, "c"))
    table.insert(params, ("%s %s"):format(map_type(ty, "ref"), name))
    table.insert(args, name)
    ::continue::
  end

  local has_err = #err ~= 0
  local has_arena = #arena ~= 0
  local return_void = result_type == "void"

  if has_arena and not return_void then
    ret = ("arena_mem<%s>"):format(ret)
  end
  if has_err then
    ret = ("std::expected<%s, error>"):format(ret)
  end

  local params = table.concat(params, ", ")
  local args = table.concat(args, ", ")
  local call_expr = ("static_cast<%s>(c::%s(%s))"):format(result_type, proto.name, args)
  local wrapper = vim.iter {
    ("inline auto %s(%s) noexcept -> %s {\n"):format(f_name, params, ret),
    err,
    local_vars,
    arena,
    gen_body(call_expr, has_err, return_void, has_arena),
    "}\n",
  }:flatten(1):join ""
  local proto = ("%s %s(%s);\n"):format(map_type(proto.return_type, "c"), proto.name, table.concat(proto_params, ", "))
  return wrapper, proto
end

local next_filename = vim.fs.dir(dir)
---@type string[]
local wrappers = {}
---@type string[]
local protos = {}
while true do
  local filename, ty = next_filename()
  if not filename then break end
  if ty ~= "file" then goto continue end
  local src = io.open(vim.fs.joinpath(dir, filename))
  assert(src)
  local src = src:read "*a"
  assert(src)
  c_grammar.grammar:match(src)
  vim.iter(c_grammar.grammar:match(src))
  ---@param x nvim.c_grammar.Proto
      :filter(function(x)
        return x[1] == "proto"
            and x.name:sub(1, 4) == "nvim"
            and x.deprecated_since == nil
      end)
      :map(gen)
      :each(function(wrapper, proto)
        table.insert(wrappers, wrapper)
        table.insert(protos, proto)
      end)
  ::continue::
end

io.stdout:write [[
#pragma once

#include <expected>

#include <nvpp/arena.hh>
#include <nvpp/keysets.hh>
#include <nvpp/types.hh>

namespace nvpp::c {
extern "C" {
]]

vim.iter(protos):each(function(x) io.stdout:write(x) end)

io.stdout:write [[
}
}

namespace nvpp::api {

constexpr auto internal_call_mask = ((uint64_t) 1 << (sizeof(uint64_t) * 8 - 1));
constexpr auto viml_internal_call = internal_call_mask;
constexpr auto lua_internal_call = viml_internal_call + 1;
]]
vim.iter(wrappers):each(function(x) io.stdout:write(x) end)
io.stdout:write "}"
