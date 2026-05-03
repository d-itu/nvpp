# Nvpp - Neovim++

Nvpp provides modern C++ bindings to neovim api, allowing users to write neovim plugins and configs in C++.

Nvpp is a header-only library which contains api wrappers generated from neovim source code. Nvpp does **NOT** use neovim's RPC feature, avoiding cost of IO and serialization. Your code is compiled into shared libraries and then directly loaded by neovim's LuaJIT runtime, either with LuaJIT `ffi` or as a Lua C module.

> [!WARNING]
> Nvpp uses undocumented neovim internal APIs, where compatibility may not be guaranteed.
>
> This project is in its early stage, where many features are still WIP.

## Requirements
- C++ compilers supporting C++23 standard (GNU `g++` and LLVM `clang++` are tested).
- Neovim (nvpp is now tested under v0.12)

## Use Nvpp in Your Project

Nvpp supports build systems such as CMake and Meson. You can also manually install header files in your system.
Generated headers with builder support are distributed in branches with name *\<tag\>*`-dist`, while `master` branch contains code-generation scripts.

### CMake
Use `FetchContent` module:
```cmake
include(FetchContent)

FetchContent_Declare(nvpp
  GIT_REPOSITORY https://github.com/d-itu/nvpp.git
  GIT_TAG        master-dist
)
FetchContent_MakeAvailable(nvpp)

add_library(my-plugin SHARED main.cpp)
target_link_libraries(my-plugin
  PRIVATE nvpp
)
```

### Meson
Use `subproject` and [wrap dependency system](https://mesonbuild.com/Wrap-dependency-system-manual.html):

`subprojects/nvpp.wrap`
```ini
[wrap-git]
url = https://github.com/d-itu/nvpp.git
revision = master-dist
depth = 1
```

`meson.build`
```meson
nvpp_proj = subproject('nvpp')
nvpp_dep = nvpp_proj.get_variable('nvpp_dep')

shared_library(
  'my-plugin',
  'main.cpp',
  dependencies: nvpp_dep,
)
```

## Usage
LuaJIT `ffi` can call any C functions in Lua.
```lua
local ffi = require "ffi"

ffi.cdef [[void setup();]]

local plugin = ffi.load("path/to/your/shared/lib/libmy-plugin.so")
plugin.setup()
```

However, if you want to add callbacks in API calls or work more seamlessly with Lua, you may want to acquire a Lua context pointer in a Lua C module.

In your `init.lua`:

```lua
package.cpath = "path/to/your/shared/lib/lib?.so;" .. package.cpath
local plugin = require "my-plugin"
```

In your C++ code:
```C++
#include <nvpp/lua.hh>
#include <nvpp/api.hh>

static void setup() {
  nvpp::api::set_option_value("number", true, {}).value();
}

extern "C" int luaopen_my_plugin(nvpp::lua l) {
  return l.push(nvpp::lua_c_func<setup>);
}
```

## Features
- [x] Low-level C API interaction.
- [x] C++ style type system.
- [x] Zero-overhead (no additional memory allocation or copy) API wrappers.
- [ ] C++ templates converting C++ callbacks to `LuaCFunction`.
- [ ] RAII-style resource management.
- [ ] Access to neovim Lua modules.
- [ ] Re-export Lua global `vim` namespace.