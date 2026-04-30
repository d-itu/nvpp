#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <string_view>

namespace nvpp {
enum struct error_type {
  none = -1,
  exception,
  validation,
};

struct error {
  error_type type{error_type::none};
  const char *msg{};

  constexpr auto is_set() const noexcept {
    return type != error_type::none;
  }
};

struct string {
  const char *data{};
  std::size_t size{};

  constexpr string() noexcept = default;
  constexpr string(std::string_view x) noexcept: data{x.data()}, size{x.size()} {}
  template <std::size_t n>
  constexpr string(const char (&s)[n]) noexcept: data{s}, size{n} {}
};

using integer = std::int64_t;
enum lua_ref: std::uint64_t;

using handle_t = int;
enum buffer: handle_t;
enum window: handle_t;
enum tabpage: handle_t;
enum hl_group_id: std::int64_t;

namespace details {
template <typename item_t>
struct vec {
  std::size_t size;
  std::size_t capacity{std::numeric_limits<size_t>::max()};
  const item_t *items;
};
}

struct object;

struct string_array: details::vec<string> {
  constexpr string_array(details::vec<string> x) noexcept: vec(x) {}
};

template <typename t>
struct array_of: details::vec<object> {
  constexpr array_of(details::vec<object> x) noexcept: vec(x) {}

  constexpr array_of(std::span<const object> span) noexcept: vec{.size = span.size(), .items = span.data()} {}

  template <typename u>
  constexpr array_of(array_of<u> o) noexcept: vec{static_cast<vec>(o)} {}
};
using array = array_of<object>;

template <typename t>
struct dict_of: details::vec<std::pair<string, object>> {
  constexpr dict_of(details::vec<std::pair<string, object>> x) noexcept: vec(x) {}
};
using dict = dict_of<object>;

constexpr class nil_t {} nil;

extern "C" enum struct object_type {
  nil,
  boolean,
  integer,
  floating,
  string,
  array,
  dict,
  lua_ref,
  buffer,
  window,
  tabpage,
};
union object_data {
  [[no_unique_address]] nil_t nil{};
  bool boolean;
  std::int64_t integer;
  double floating;
  nvpp::string string;
  nvpp::array array;
  nvpp::dict dict;
  nvpp::lua_ref lua_ref;
};

struct object {
  object_type type;
  object_data data;

  constexpr object() noexcept = default;

  constexpr object(nil_t) noexcept: type{object_type::nil} {}

  constexpr object(std::same_as<bool> auto value) noexcept: type{object_type::boolean}, data{.boolean = value} {}

  constexpr object(std::integral auto value) noexcept
    requires (not std::is_same_v<decltype(value), bool>)
  : type{object_type::integer}, data{.integer = value} {}

  constexpr object(double value) noexcept: type{object_type::floating}, data{.floating = value} {}

  constexpr object(string s) noexcept
  : type{object_type::string}, data{.string = s} {}

  constexpr object(std::string_view s) noexcept
  : type{object_type::string}, data{.string = string{s}} {}

  template <std::size_t n>
  constexpr object(const char (&s)[n]) noexcept
  : type{object_type::string}, data{.string = string{s}} {}

  template <typename t>
  constexpr object(array_of<t> value) noexcept: type{object_type::array}, data{.array = value} {}

  template <typename t>
  constexpr object(dict_of<t> value) noexcept: type{object_type::dict}, data{.dict = value} {}

  constexpr object(lua_ref value) noexcept: type{object_type::lua_ref}, data{.lua_ref = value} {}

  constexpr object(buffer value) noexcept: type{object_type::buffer}, data{.integer = value} {}

  constexpr object(window value) noexcept: type{object_type::window}, data{.integer = value} {}

  constexpr object(tabpage value) noexcept: type{object_type::tabpage}, data{.integer = value} {}
};

}

namespace nvpp::alloc {
struct object;
struct string: nvpp::string {};

struct string_array: nvpp::string_array {
  constexpr string_array(nvpp::string_array x) noexcept: nvpp::string_array{x} {}
};

template <typename t>
struct array_of: nvpp::array_of<t> {
  constexpr array_of(nvpp::array_of<t> x) noexcept: nvpp::array_of<t>{x} {}
};
using array = array_of<object>;

template <typename t>
struct dict_of: nvpp::dict_of<t> {
  constexpr dict_of(nvpp::dict_of<t> x) noexcept: nvpp::dict_of<t>{x} {}
};
using dict = dict_of<object>;

struct object: nvpp::object {};
}
