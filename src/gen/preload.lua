local ffi = require "ffi"
ffi.cdef [[void *signal(int signum, void *handler);]]
local SIGINT = 2
local SIG_DFL = ffi.cast("void *", 0)
ffi.C.signal(SIGINT, SIG_DFL)

package.path = './deps/neovim-0.12.1/src/?.lua;./src/?.lua;' .. package.path
require(arg[1])
