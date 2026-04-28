local c_grammar = require "gen.c_grammar"

local allocated = {
  String = "nvpp::alloc::string",
  Object = "nvpp::alloc::object",
  Array  = "nvpp::alloc::array",
  Dict   = "nvpp::alloc::dict",
}

local primitives = {
  Integer = "std::int64_t",
  uint64_t = "std::uint64_t",
  Float = "double",
  Boolean = "bool",
  Buffer = "nvpp::buffer",
  Window = "nvpp::window",
  Tabpage = "nvpp::tabpage",
  HLGroupId = "nvpp::hl_group_id",

  String = "nvpp::string",
  Object = "nvpp::object",
  Array = "nvpp::array",
  Dict = "nvpp::dict",

  void = "void",
}

---@alias ownership "ref" | "owned"

---@type table<string, fun(_:any, _:ownership): string>
local containers

---@param ty string
---@param ownership ownership
---@return string
local function map_type(ty, ownership)
  do
    local primitive = (ownership == "owned" and allocated[ty]) or primitives[ty]
    if primitive then return primitive end
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
  Dict = function(name, ownership) return (ownership == "owned" and "keysets::" or "keysets::builder::") .. name end,
  DictAs = function(_, ownership) return ownership == "ref" and "dict" or "alloc::dict" end,
  ArrayOf = function(inner, ownership)
    local inner = map_type(inner, ownership)
    local ty = ("array_of<%s>"):format(inner)
    return ownership == "ref" and ty or "alloc::" .. ty
  end,
  DictOf = function(inner, ownership)
    local inner = map_type(inner, ownership)
    local ty = ("dict_of<%s>"):format(inner)
    return ownership == "ref" and ty or "alloc::" .. ty
  end,
  Union = function(_, ownership)
    return ownership == "ref" and "object" or "alloc::object"
  end,
  Tuple = function(_, ownership)
    return ownership == "ref" and "array" or "alloc::array"
  end,
  -- Tuple = function(inner, ownership)
  --   if ownership == "ref" then return "array" end
  --   local fields = vim.iter(inner):map(function(x) return map_type(x, ownership) end):join ", "
  --   return ("std::tuple<%s>"):format(fields)
  -- end,
}

return map_type
