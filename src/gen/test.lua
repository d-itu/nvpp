local c_grammar = require 'gen.c_grammar'

local x = c_grammar.typed_container:match [[Tuple(Float, Float)]]
vim.print(x)

