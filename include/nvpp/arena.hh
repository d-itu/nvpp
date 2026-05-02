#pragma once

#include <cstdlib>

namespace nvpp {
struct arena;
struct consumed_blk;

template <typename>
struct arena_mem;

}

namespace nvpp::c {
extern "C" {
consumed_blk *arena_finish(arena *);
void arena_mem_free(consumed_blk *);
struct arena {
  char *cur_blk{};
  std::size_t pos{}, size{};
};
}
}

namespace nvpp {

template<>
struct arena_mem<void> {
  consumed_blk *ptr;

  void free() const noexcept {
    c::arena_mem_free(ptr);
  }
};

template <typename data_t>
struct arena_mem {
  arena_mem<void> mem;
  [[no_unique_address]] data_t data;
};

struct arena: c::arena {
  auto finish() noexcept {
    return arena_mem<void>{c::arena_finish(this)};
  }

  auto finish(auto data) noexcept {
    return arena_mem {
      .mem = finish(),
      .data = data,
    };
  }

  void free() noexcept {
    finish().free();
  }
};

}
