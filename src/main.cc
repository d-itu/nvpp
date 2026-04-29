#include <nvpp/lua.hh>
#include <nvpp/api.hh>

#define nvpp_array(...) nvpp::array(nvpp::make_array(__VA_ARGS__))

// constexpr auto arr = nvpp::array_of<int>(nvpp::make_array(1));

void err(std::string_view msg) {
  nvpp::api::echo(nvpp::make_array(nvpp_array(msg)), false, {.err = true}).value();
}
void echo(std::string_view msg) {
  nvpp::api::echo(nvpp::make_array(nvpp_array(msg)), false, {}).value();
}

static void setup(nvpp::lua l) try {
  nvpp::api::set_option_value("number", true, {}).value();
  nvpp::api::set_keymap("n", "<Left>", "", {
    .callback = l.def<[]{
      echo("hello");
    }>(),
  }).value();
} catch(std::bad_expected_access<nvpp::error> const &e) {
  err(e.error().msg);
}

extern "C" int luaopen_nvpp(nvpp::lua l) {
  return l.push(nvpp::lua_c_func<setup>);
}

// static_assert(nvpp::object{true}.get<bool>() == true);
// static_assert(nvpp::object{1}.get_unchecked<int>() == 1);
//
// constexpr auto xs = std::array<nvpp::object, 3>{1, 2, 3};
// constexpr auto arr = nvpp::array(xs);
// constexpr auto tpl = arr.to_tuple_unchecked<int, int>();
// static_assert(std::get<1>(tpl) == 2);
