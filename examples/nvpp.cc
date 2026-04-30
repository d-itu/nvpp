#include <nvpp/lua.hh>
#include <nvpp/api.hh>
#include <nvpp/macros.hh>

void err(std::string_view msg) {
  nvpp::api::echo(nvpp_array(nvpp_array(msg)), false, {.err = true}).value();
}
void echo(std::string_view msg) {
  nvpp::api::echo(nvpp_array(nvpp_array(msg)), false, {}).value();
}

constexpr struct {} unwrap;
template <typename t, typename e>
constexpr auto operator|(std::expected<t, e> x, decltype(unwrap)) {
  if (x.has_value()) { return *x; }
  throw x.error();
}

static void setup(nvpp::lua l) try {
  nvpp::api::set_option_value("number", true, {}) | unwrap;
  nvpp::api::set_keymap("n", "<Left>", "", {
    .callback = l.def<[]{
      echo("hello");
    }>(),
  }) | unwrap;
} catch(nvpp::error e) {
  err(e.msg);
}

extern "C" int luaopen_nvpp(nvpp::lua l) {
  return l.push(nvpp::lua_c_func<setup>);
}
