#pragma once

#define restrict __restrict__
#define new new_
extern "C" {
#include <nvim/api/options.h>
#include <nvim/api/vim.h>
#include <nvim/types_defs.h>
#include <nvim/macros_defs.h>
}
#undef restrict

