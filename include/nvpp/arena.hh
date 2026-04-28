#pragma once

#include <nvpp/c.hh>

namespace nvpp {

struct arena_mem {
  ArenaMem ptr;
  void free() const noexcept {
    arena_mem_free(this->ptr);
  }
};

template <typename data_t>
struct arena_allocated {
  arena_mem memory;
  [[no_unique_address]] data_t data;

  void free() const noexcept {
    memory.free();
  }
};

struct arena: Arena {
  auto finish() noexcept {
    return arena_mem{arena_finish(static_cast<Arena *>(this))};
  }
  auto finish(auto data) noexcept {
    return arena_allocated{
      .memory = finish(),
      .data = data,
    };
  }
};

}
