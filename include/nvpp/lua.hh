#include <type_traits>

#include <lua.hpp>

#include <nvpp/types.hh>


namespace nvpp {

namespace details {
template <auto f>
struct lua_c_func;
}
template <auto f>
constexpr auto lua_c_func = details::lua_c_func<f>::value;

extern "C" LuaRef nlua_ref_global(void*, int);

struct lua {
  void *l;

  template <bool is_noexcept>
  int push(int(*f)(lua) noexcept(is_noexcept)) const noexcept {
    lua_pushcclosure((lua_State *) l, std::bit_cast<lua_CFunction>(f), 0);
    return 1;
  }

  inline auto pop_lua_ref() const noexcept {
    return nvpp::lua_ref{nlua_ref_global(l, -1)};
  }

  template <auto f>
  auto def() const noexcept {
    push(lua_c_func<f>);
    return pop_lua_ref();
  }
};

template <typename... args>
std::tuple<args...> parse_arg(lua) = delete;

template <>
inline std::tuple<lua> parse_arg<lua>(lua l) { return l; }

template <>
inline std::tuple<> parse_arg<>(lua) { return {}; }

namespace details {

template <typename f>
struct lua_c_func_helper;

template <typename ret, bool is_noexcept, typename... args>
struct lua_c_func_helper<ret(*)(args...) noexcept(is_noexcept)> {
  template <ret(*f)(args...) noexcept(is_noexcept)>
    requires (std::is_same_v<ret, void>)
  static int operator()(lua l) {
    std::apply(f, parse_arg<args...>(l));
    return 0;
  }

  template <ret(*f)(args...) noexcept(is_noexcept)>
    requires (not std::is_same_v<ret, void>)
  static int operator()(lua l) {
    return l.push(std::apply(f, parse_arg<args...>(l)));
  }
};

static_assert(std::is_function_v<void()>);

template <typename lambda, typename ret, bool is_noexcept, typename... args>
struct lua_c_func_helper<ret(lambda::*)(args...) const noexcept(is_noexcept)> {
  template <lambda f>
    requires (std::is_same_v<ret, void>)
  static int operator()(lua l) noexcept(is_noexcept) {
    std::apply(f, parse_arg<args...>(l));
    return 0;
  }

  template <lambda f>
    requires (not std::is_same_v<ret, void>)
  static int operator()(lua l) noexcept(is_noexcept) {
    return l.push(std::apply(f, parse_arg<args...>(l)));
  }
};

template <auto f>
requires std::is_function_v<std::remove_pointer_t<decltype(f)>>
struct lua_c_func<f> {
  static constexpr auto value = details::lua_c_func_helper<decltype(f)>::template operator()<f>;
};

template <auto f>
requires std::is_class_v<decltype(f)>
struct lua_c_func<f> {
  static constexpr auto value = details::lua_c_func_helper<decltype(&decltype(f)::operator())>::template operator()<f>;
};

}

// void f();
// constexpr auto f_lua = lua_c_func<f>;
// constexpr auto g_lua = lua_c_func<[]{}>;
//
// void ff();
// void ff(int);
// constexpr auto ff_lua = lua_c_func<static_cast<void(*)()>(ff)>;
}
