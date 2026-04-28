#pragma once

#include <cstdint> // IWYU pragma: export
#include <string_view>
#include <span>
#include <tuple>
#include <optional>
#include <limits>

#include <nvpp/arena.hh>

namespace nvpp {

template <ObjectType>
struct type_from_enum;

template <ObjectType t>
using type_from_enum_t = type_from_enum<t>::type;

template <typename t>
struct enum_from_type;

template <typename t>
constexpr ObjectType enum_from_type_v = enum_from_type<t>::value;

constexpr struct {} nil;
using nil_t = decltype(nil);
struct string: String {
  constexpr string(String x) noexcept: String{x} {}
  constexpr string(std::string_view sv) noexcept: String {
    .data = const_cast<char *>(sv.data()),
    .size = sv.size(),
  } {}
  constexpr string(const char *s) noexcept: string{std::string_view(s)} {}
};

enum lua_ref: LuaRef {};
enum buffer: Buffer {};
enum window: Window {};
enum tabpage: Tabpage {};
enum hl_group_id: HLGroupID {};

template <typename t>
t get_unchecked_impl(auto) noexcept;
template <>
constexpr nil_t get_unchecked_impl<nil_t>(Object) noexcept { return nil; }
template <>
constexpr bool get_unchecked_impl<bool>(Object o) noexcept { return o.data.boolean; }
template <std::integral integer>
constexpr integer get_unchecked(Object o) noexcept requires (not std::is_same_v<integer, bool>) { return o.data.integer; }
template<>
constexpr double get_unchecked_impl<double>(Object o) noexcept { return o.data.floating; }
template<>
constexpr string get_unchecked_impl<string>(Object o) noexcept { return o.data.string; }
template<>
constexpr lua_ref get_unchecked_impl<lua_ref>(Object o) noexcept { return lua_ref(o.data.integer); }
template<>
constexpr buffer get_unchecked_impl<buffer>(Object o) noexcept { return buffer(o.data.integer); }
template<>
constexpr window get_unchecked_impl<window>(Object o) noexcept { return window(o.data.integer); }
template<>
constexpr tabpage get_unchecked_impl<tabpage>(Object o) noexcept { return tabpage(o.data.integer); }

template <typename t>
constexpr std::optional<t> get_unchecked(Object o) noexcept {
  return get_unchecked_impl<t>(o);
}
template <ObjectType t>
constexpr type_from_enum_t<t> get_unchecked(Object o) noexcept {
  return get_unchecked_impl<type_from_enum_t<t>>(o);
}
template <typename t>
constexpr std::optional<t> get(Object o) noexcept {
  if (o.type != enum_from_type_v<t>) {
    return {};
  }
  return get_unchecked_impl<t>(o);
}
template <ObjectType t>
constexpr std::optional<type_from_enum_t<t>> get(Object o) noexcept {
  if (o.type != t) {
    return {};
  }
  return get_unchecked_impl<t>(o);
}

struct _ {
struct object;

template <typename t>
struct array_of {
  size_t size;
  size_t capacity;
  const object *items;

  template <typename u>
  constexpr array_of(array_of<u> arr) noexcept: size{arr.size}, capacity{arr.capacity}, items{(object *) arr.items} {}

  constexpr array_of(Array arr) noexcept: size{arr.size}, capacity{arr.capacity}, items{(object *) arr.items} {}

  constexpr array_of(size_t size, size_t capacity, const object *items) noexcept:
    size{size}, capacity{capacity}, items{items} {}

  constexpr array_of(const std::span<object> &arr) noexcept: array_of{
    arr.size(),
    std::numeric_limits<size_t>::max(),
    arr.data(),
  } {}

  template <std::size_t n>
  constexpr array_of(const std::array<object, n> &arr) noexcept: array_of{
    n,
    std::numeric_limits<size_t>::max(),
    arr.data(),
  } {}

  constexpr operator Array() const noexcept {
    return {.size = size, .capacity = capacity, .items = (Object *) items};
  }

  template <std::size_t begin, typename t0, typename ...ts>
  constexpr auto to_tuple_unchecked() const noexcept {
    decltype(auto) x0 = *(object const*)(items + begin);
    return std::tuple_cat(std::make_tuple(x0.template get_unchecked<t0>()), to_tuple_unchecked<begin + 1, ts...>());
  }
  template <std::size_t begin=0>
  constexpr auto to_tuple_unchecked() const noexcept {
    return std::tuple_cat();
  }
  template <typename ...ts>
  constexpr auto to_tuple_unchecked() const noexcept {
    return to_tuple_unchecked<0, ts...>();
  }
};

// template <typename t>
// struct array_of: Array {
//   constexpr array_of(Array x) noexcept: Array{x} {}
//   constexpr array_of(std::span<object> span) noexcept: Array{
//     .size = span.size(),
//     .items = static_cast<Object *>(span.data()),
//   } {}
//   template <std::size_t n>
//   constexpr array_of(const std::array<object, n> &arr) noexcept: Array{
//     .size = n,
//     // .items = static_cast<Object *>(arr.data()),
//     .items = (Object *) arr.data(),
//   } {}
//   constexpr operator std::span<object>() noexcept {
//     return {static_cast<object *>(items), size};
//   }
//   // constexpr auto begin() const noexcept {
//   //   return std::span{items, size}.begin();
//   // }
//   // constexpr auto end() const noexcept {
//   //   return std::span{items, size}.end();
//   // }
//   // template <std::size_t begin, typename t0, typename ...ts>
//   // constexpr auto to_tuple_unchecked() const noexcept {
//   //   decltype(auto) x0 = *(object const*)(items + begin);
//   //   return std::tuple_cat(std::make_tuple(x0.get<t0>()), to_tuple_unchecked<begin + 1, ts...>());
//   // }
//   // template <std::size_t begin=0>
//   // constexpr auto to_tuple_unchecked() const noexcept {
//   //   return std::tuple_cat();
//   // }
//   // template <typename ...ts>
//   // constexpr auto to_tuple_unchecked() const noexcept {
//   //   return to_tuple_unchecked<0, ts...>();
//   // }
// };
template <typename t>
struct dict_of: Dict {
  constexpr dict_of(Dict x) noexcept: Dict{x} {}
};

struct object: Object {
  constexpr object(Object x) noexcept: Object{x} {}

  template <typename t>
  constexpr auto get_unchecked() const noexcept {
    return nvpp::get_unchecked<t>(*this);
  }
  template <ObjectType t>
  constexpr auto get_unchecked() const noexcept {
    return nvpp::get_unchecked<t>(*this);
  }
  template <typename t>
  constexpr auto get() const noexcept {
    return nvpp::get<t>(*this);
  }
  template <ObjectType t>
  constexpr auto get() const noexcept {
    return nvpp::get<t>(*this);
  }

  constexpr object(nil_t) noexcept: Object {
    .type = kObjectTypeNil,
    .data = {},
  } {}

  constexpr object(std::same_as<bool> auto value) noexcept: Object {
    .type = kObjectTypeBoolean,
    .data = { .boolean = value },
  } {}

  constexpr object(std::integral auto value) noexcept
    requires (not std::is_same_v<decltype(value), bool>)
  : Object {
    .type = kObjectTypeInteger,
    .data = { .integer = value },
  } {}

  constexpr object(double value) noexcept: Object {
    .type = kObjectTypeFloat,
    .data = { .floating = value },
  } {}

  constexpr object(auto &&value) noexcept
    requires requires { string{std::forward<decltype(value)>(value)}; }
  : Object {
    .type = kObjectTypeString,
    .data = { .string = string{std::forward<decltype(value)>(value)} },
  } {}

  template <typename t>
  constexpr object(array_of<t> value) noexcept: Object {
    .type = kObjectTypeArray,
    .data = { .array = value },
  } {}

  template <typename t>
  constexpr object(dict_of<t> value) noexcept: Object {
    .type = kObjectTypeDict,
    .data = { .dict = value },
  } {}

  constexpr object(lua_ref value) noexcept: Object {
    .type = kObjectTypeLuaRef,
    .data = { .integer = value },
  } {}

  constexpr object(buffer value) noexcept: Object {
    .type = kObjectTypeBuffer,
    .data = { .integer = value },
  } {}

  constexpr object(window value) noexcept: Object {
    .type = kObjectTypeWindow,
    .data = { .integer = value },
  } {}

  constexpr object(tabpage value) noexcept: Object {
    .type = kObjectTypeTabpage,
    .data = { .integer = value },
  } {}
};
};

using object = _::object;
template <typename t>
using array_of = _::array_of<t>;
using array = array_of<object>;
template <typename t>
using dict_of = _::dict_of<t>;
using dict = dict_of<object>;
struct error: Error {};

template<>
constexpr array get_unchecked_impl<array>(Object o) noexcept { return o.data.array; }
template<>
constexpr dict get_unchecked_impl<dict>(Object o) noexcept { return o.data.dict; }

#define nvpp_partial(en, ty) \
template <> struct type_from_enum<en> { using type = ty; }; \
template <> struct enum_from_type<ty> { constexpr static auto value = en; } \
//

nvpp_partial(kObjectTypeNil, nil_t);
nvpp_partial(kObjectTypeBoolean, bool);
template <> struct type_from_enum<kObjectTypeInteger> {
  using type = std::int64_t;
};
template <std::integral t> struct enum_from_type<t> {
  constexpr static auto value = kObjectTypeInteger;
};
nvpp_partial(kObjectTypeFloat, double);
nvpp_partial(kObjectTypeString, string);
template <> struct enum_from_type<std::string_view> {
  constexpr static auto value = kObjectTypeString;
};
nvpp_partial(kObjectTypeArray, array);
nvpp_partial(kObjectTypeDict, dict);
nvpp_partial(kObjectTypeLuaRef, lua_ref);
nvpp_partial(kObjectTypeBuffer, buffer);
nvpp_partial(kObjectTypeWindow, window);
nvpp_partial(kObjectTypeTabpage, tabpage);

#undef nvpp_partial

namespace details {
template <std::size_t ...indices>
constexpr auto tuple_help(std::integer_sequence<std::size_t, indices...> seq, auto tpl) {
  return std::array<object, seq.size()>{std::get<indices>(tpl)...};
}
}

template <typename ...ts>
constexpr auto array_from_tuple(std::tuple<ts...> tpl) {
  return details::tuple_help(std::make_integer_sequence<std::size_t, sizeof...(ts)>(), tpl);
}

template <typename ...ts>
constexpr auto make_array(ts ...xs) {
  return std::array<object, sizeof...(ts)>{xs...};
}

}

namespace nvpp::alloc {
  struct string: nvpp::string {
    void free(this string self) {
      xfree(self.data);
    }
  };

struct _ {
  struct object : nvpp::object {
    void free(this object self) {
      switch (self.type) {
      case kObjectTypeString:
        xfree(self.data.string.data);
        break;
      case kObjectTypeArray:
        xfree(self.data.array.items);
        break;
      case kObjectTypeDict:
        xfree(self.data.dict.items);
        break;
      default:
        break;
      }
    }
  };

  template <typename t>
  struct array_of: nvpp::array_of<t> {
    void free(this array_of<t> self) {
      for (object item: self) {
        // TODO
        std::ignore = item;
      }
      xfree(self.items);
    }
  };
  using array = array_of<object>;

  template <typename t>
  struct dict_of: nvpp::dict {
    void free(this dict_of self) {
      xfree(self.items);
    }
  };
};

using object = _::object;
template <typename t>
using array_of = _::array_of<t>;
using array = array_of<object>;
template <typename t>
using dict_of = _::dict_of<t>;
using dict = dict_of<object>;
}

