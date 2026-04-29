local c_grammar = require "gen.c_grammar"

local allocated = {
  String      = "alloc::string",
  Object      = "alloc::object",
  Array       = "alloc::array",
  Dict        = "alloc::dict",
  StringArray = "alloc::string_array",
}

local raw = {
  Array       = "details::vec<object>",
  Dict        = "details::vec<std::pair<string, object>>",
  StringArray = "details::vec<string>",
}

local primitives = {
  Integer     = "std::int64_t",
  uint64_t    = "std::uint64_t",
  Float       = "double",
  Boolean     = "bool",
  Buffer      = "nvpp::buffer",
  Window      = "nvpp::window",
  Tabpage     = "nvpp::tabpage",
  HLGroupID   = "nvpp::hl_group_id",
  LuaRef      = "nvpp::lua_ref",

  String      = "string",
  Object      = "object",
  Array       = "array",
  Dict        = "dict",
  StringArray = "string_array",

  void        = "void",
}

---@alias ownership
---| "ref"
---| "owned"
---| "c"

---@type table<string, fun(_:any, _:ownership): string>
local containers

---@param ty string
---@param ownership ownership
---@return string
local function map_type(ty, ownership)
  do
    local primitive = primitives[ty]
    if primitive then
      if ownership == "owned" then
        return allocated[ty] or primitive
      end
      if ownership == "c" then
        return raw[ty] or primitive
      end
      return primitive
    end
  end

  if not c_grammar.typed_container:match(ty) then return ty end
  local con, args = unpack(c_grammar.typed_container:match(ty))
  -- TODO: change to
  -- return containers[con](args, ownership)
  local f = containers[con]
  if f then return f(args, ownership) end
  return ty
end

containers = {
  Dict = function(name, ownership)
    return (ownership ~= "ref" and "keysets::" or "keysets::builder::") .. name
  end,
  DictAs = function(_, ownership)
    return map_type("Dict", ownership)
  end,
  ArrayOf = function(inner, ownership)
    if ownership == "c" then return raw.Array end
    local inner = map_type(inner, ownership)
    local ty = ("array_of<%s>"):format(inner)
    return ownership == "ref" and ty or "alloc::" .. ty
  end,
  DictOf = function(inner, ownership)
    if ownership == "c" then return raw.Dict end
    local inner = map_type(inner, ownership)
    local ty = ("dict_of<%s>"):format(inner)
    return ownership == "ref" and ty or "alloc::" .. ty
  end,
  Union = function(_, ownership)
    return map_type("Object", ownership)
  end,
  Tuple = function(_, ownership)
    return map_type("Array", ownership)
  end,
  LuaRefOf = function() return "lua_ref" end,
  Enum = function(_, ownership)
    return map_type("String", ownership)
  end,
}

return map_type
