#pragma once

#include <expected>

#include <nvpp/arena.hh>
#include <nvpp/keysets.hh>
#include <nvpp/types.hh>

namespace nvpp::c {
extern "C" {
details::vec<object> nvim_get_autocmds(keysets::get_autocmds *, arena *, error *);
std::int64_t nvim_create_autocmd(std::uint64_t, object, keysets::create_autocmd *, arena *, error *);
void nvim_del_autocmd(std::int64_t, error *);
void nvim_clear_autocmds(keysets::clear_autocmds *, arena *, error *);
std::int64_t nvim_create_augroup(std::uint64_t, string, keysets::create_augroup *, error *);
void nvim_del_augroup_by_id(std::int64_t, error *);
void nvim_del_augroup_by_name(string, error *);
void nvim_exec_autocmds(object, keysets::exec_autocmds *, arena *, error *);
std::int64_t nvim_buf_line_count(nvpp::buffer, error *);
bool nvim_buf_attach(std::uint64_t, nvpp::buffer, bool, keysets::buf_attach *, error *);
bool nvim_buf_detach(std::uint64_t, nvpp::buffer, error *);
details::vec<object> nvim_buf_get_lines(std::uint64_t, nvpp::buffer, std::int64_t, std::int64_t, bool, arena *, void *, error *);
void nvim_buf_set_lines(std::uint64_t, nvpp::buffer, std::int64_t, std::int64_t, bool, details::vec<object>, arena *, error *);
void nvim_buf_set_text(std::uint64_t, nvpp::buffer, std::int64_t, std::int64_t, std::int64_t, std::int64_t, details::vec<object>, arena *, error *);
details::vec<object> nvim_buf_get_text(std::uint64_t, nvpp::buffer, std::int64_t, std::int64_t, std::int64_t, std::int64_t, keysets::empty *, arena *, void *, error *);
std::int64_t nvim_buf_get_offset(nvpp::buffer, std::int64_t, error *);
object nvim_buf_get_var(nvpp::buffer, string, arena *, error *);
std::int64_t nvim_buf_get_changedtick(nvpp::buffer, error *);
details::vec<object> nvim_buf_get_keymap(nvpp::buffer, string, arena *, error *);
void nvim_buf_set_keymap(std::uint64_t, nvpp::buffer, string, string, string, keysets::keymap *, error *);
void nvim_buf_del_keymap(std::uint64_t, nvpp::buffer, string, string, error *);
void nvim_buf_set_var(nvpp::buffer, string, object, error *);
void nvim_buf_del_var(nvpp::buffer, string, error *);
string nvim_buf_get_name(nvpp::buffer, error *);
void nvim_buf_set_name(nvpp::buffer, string, error *);
bool nvim_buf_is_loaded(nvpp::buffer);
void nvim_buf_delete(nvpp::buffer, keysets::buf_delete *, error *);
bool nvim_buf_is_valid(nvpp::buffer);
bool nvim_buf_del_mark(nvpp::buffer, string, error *);
bool nvim_buf_set_mark(nvpp::buffer, string, std::int64_t, std::int64_t, keysets::empty *, error *);
details::vec<object> nvim_buf_get_mark(nvpp::buffer, string, arena *, error *);
object nvim_buf_call(nvpp::buffer, nvpp::lua_ref, error *);
details::vec<std::pair<string, object>> nvim__buf_stats(nvpp::buffer, arena *, error *);
keysets::cmd nvim_parse_cmd(string, keysets::empty *, arena *, error *);
string nvim_cmd(std::uint64_t, keysets::cmd *, keysets::cmd_opts *, arena *, error *);
void nvim_create_user_command(std::uint64_t, string, object, keysets::user_command *, error *);
void nvim_del_user_command(string, error *);
void nvim_buf_create_user_command(std::uint64_t, nvpp::buffer, string, object, keysets::user_command *, error *);
void nvim_buf_del_user_command(nvpp::buffer, string, error *);
details::vec<std::pair<string, object>> nvim_get_commands(keysets::get_commands *, arena *, error *);
details::vec<std::pair<string, object>> nvim_buf_get_commands(nvpp::buffer, keysets::get_commands *, arena *, error *);
void nvim_error_event(std::uint64_t, std::int64_t, string);
void nvim_ui_term_event(std::uint64_t, string, object, error *);
std::int64_t nvim_create_namespace(string);
details::vec<std::pair<string, object>> nvim_get_namespaces(arena *);
details::vec<object> nvim_buf_get_extmark_by_id(nvpp::buffer, std::int64_t, std::int64_t, keysets::get_extmark *, arena *, error *);
details::vec<object> nvim_buf_get_extmarks(nvpp::buffer, std::int64_t, object, object, keysets::get_extmarks *, arena *, error *);
std::int64_t nvim_buf_set_extmark(nvpp::buffer, std::int64_t, std::int64_t, std::int64_t, keysets::set_extmark *, error *);
bool nvim_buf_del_extmark(nvpp::buffer, std::int64_t, std::int64_t, error *);
void nvim_buf_clear_namespace(nvpp::buffer, std::int64_t, std::int64_t, std::int64_t, error *);
void nvim_set_decoration_provider(std::int64_t, keysets::set_decoration_provider *, error *);
string nvim__buf_debug_extmarks(nvpp::buffer, bool, bool, error *);
void nvim__ns_set(std::int64_t, keysets::ns_opts *, error *);
keysets::ns_opts nvim__ns_get(std::int64_t, arena *, error *);
object nvim_get_option_value(string, keysets::option *, error *);
void nvim_set_option_value(std::uint64_t, string, object, keysets::option *, error *);
details::vec<std::pair<string, object>> nvim_get_all_options_info(arena *, error *);
details::vec<std::pair<string, object>> nvim_get_option_info2(string, keysets::option *, arena *, error *);
details::vec<object> nvim_tabpage_list_wins(nvpp::tabpage, arena *, error *);
object nvim_tabpage_get_var(nvpp::tabpage, string, arena *, error *);
void nvim_tabpage_set_var(nvpp::tabpage, string, object, error *);
void nvim_tabpage_del_var(nvpp::tabpage, string, error *);
nvpp::window nvim_tabpage_get_win(nvpp::tabpage, error *);
void nvim_tabpage_set_win(nvpp::tabpage, nvpp::window, error *);
std::int64_t nvim_tabpage_get_number(nvpp::tabpage, error *);
bool nvim_tabpage_is_valid(nvpp::tabpage);
nvpp::tabpage nvim_open_tabpage(nvpp::buffer, bool, keysets::tabpage_config *, error *);
void nvim_ui_attach(std::uint64_t, std::int64_t, std::int64_t, details::vec<std::pair<string, object>>, error *);
void nvim_ui_set_focus(std::uint64_t, bool, error *);
void nvim_ui_detach(std::uint64_t, error *);
void nvim_ui_try_resize(std::uint64_t, std::int64_t, std::int64_t, error *);
void nvim_ui_set_option(std::uint64_t, string, object, error *);
void nvim_ui_try_resize_grid(std::uint64_t, std::int64_t, std::int64_t, std::int64_t, error *);
void nvim_ui_pum_set_height(std::uint64_t, std::int64_t, error *);
void nvim_ui_pum_set_bounds(std::uint64_t, double, double, double, double, error *);
void nvim_ui_send(std::uint64_t, string, error *);
std::int64_t nvim_get_hl_id_by_name(string);
details::vec<std::pair<string, object>> nvim_get_hl(std::int64_t, keysets::get_highlight *, arena *, error *);
void nvim_set_hl(std::uint64_t, std::int64_t, string, keysets::highlight *, error *);
std::int64_t nvim_get_hl_ns(keysets::get_ns *, error *);
void nvim_set_hl_ns(std::int64_t, error *);
void nvim_set_hl_ns_fast(std::int64_t, error *);
void nvim_feedkeys(string, string, bool);
std::int64_t nvim_input(std::uint64_t, string);
void nvim_input_mouse(string, string, string, std::int64_t, std::int64_t, std::int64_t, error *);
string nvim_replace_termcodes(string, bool, bool, bool);
object nvim_exec_lua(string, details::vec<object>, arena *, error *);
object nvim__exec_lua_fast(string, details::vec<object>, arena *, error *);
std::int64_t nvim_strwidth(string, error *);
details::vec<object> nvim_list_runtime_paths(arena *, error *);
details::vec<object> nvim__runtime_inspect(arena *);
details::vec<object> nvim_get_runtime_file(string, bool, arena *, error *);
string nvim__get_lib_dir();
details::vec<object> nvim__get_runtime(details::vec<object>, bool, keysets::runtime *, arena *, error *);
void nvim_set_current_dir(string, error *);
string nvim_get_current_line(arena *, error *);
void nvim_set_current_line(string, arena *, error *);
void nvim_del_current_line(arena *, error *);
object nvim_get_var(string, arena *, error *);
void nvim_set_var(string, object, error *);
void nvim_del_var(string, error *);
object nvim_get_vvar(string, arena *, error *);
void nvim_set_vvar(string, object, error *);
object nvim_echo(details::vec<object>, bool, keysets::echo_opts *, error *);
details::vec<object> nvim_list_bufs(arena *);
nvpp::buffer nvim_get_current_buf();
void nvim_set_current_buf(nvpp::buffer, error *);
details::vec<object> nvim_list_wins(arena *);
nvpp::window nvim_get_current_win();
void nvim_set_current_win(nvpp::window, error *);
nvpp::buffer nvim_create_buf(bool, bool, error *);
std::int64_t nvim_open_term(nvpp::buffer, keysets::open_term *, error *);
void nvim_chan_send(std::int64_t, string, error *);
details::vec<object> nvim_list_tabpages(arena *);
nvpp::tabpage nvim_get_current_tabpage();
void nvim_set_current_tabpage(nvpp::tabpage, error *);
bool nvim_paste(std::uint64_t, string, bool, std::int64_t, arena *, error *);
void nvim_put(details::vec<object>, string, bool, bool, arena *, error *);
std::int64_t nvim_get_color_by_name(string);
details::vec<std::pair<string, object>> nvim_get_color_map(arena *);
details::vec<std::pair<string, object>> nvim_get_context(keysets::context *, arena *, error *);
object nvim_load_context(details::vec<std::pair<string, object>>, error *);
details::vec<std::pair<string, object>> nvim_get_mode(arena *);
details::vec<object> nvim_get_keymap(string, arena *);
void nvim_set_keymap(std::uint64_t, string, string, string, keysets::keymap *, error *);
void nvim_del_keymap(std::uint64_t, string, string, error *);
details::vec<object> nvim_get_api_info(std::uint64_t, arena *);
void nvim_set_client_info(std::uint64_t, string, details::vec<std::pair<string, object>>, string, details::vec<std::pair<string, object>>, details::vec<std::pair<string, object>>, arena *, error *);
void nvim__chan_set_detach(std::uint64_t, bool, error *);
details::vec<std::pair<string, object>> nvim_get_chan_info(std::uint64_t, std::int64_t, arena *, error *);
details::vec<object> nvim_list_chans(arena *);
object nvim__id(object, arena *);
details::vec<object> nvim__id_array(details::vec<object>, arena *);
details::vec<std::pair<string, object>> nvim__id_dict(details::vec<std::pair<string, object>>, arena *);
double nvim__id_float(double);
details::vec<std::pair<string, object>> nvim__stats(arena *);
details::vec<object> nvim_list_uis(arena *);
details::vec<object> nvim_get_proc_children(std::int64_t, arena *, error *);
object nvim_get_proc(std::int64_t, arena *, error *);
void nvim_select_popupmenu_item(std::int64_t, bool, bool, keysets::empty *, error *);
details::vec<object> nvim__inspect_cell(std::int64_t, std::int64_t, std::int64_t, arena *, error *);
void nvim__screenshot(string);
void nvim__invalidate_glyph_cache();
object nvim__unpack(string, arena *, error *);
bool nvim_del_mark(string, error *);
details::vec<object> nvim_get_mark(string, keysets::empty *, arena *, error *);
details::vec<std::pair<string, object>> nvim_eval_statusline(string, keysets::eval_statusline *, arena *, error *);
details::vec<std::pair<string, object>> nvim__complete_set(std::int64_t, keysets::complete_set *, arena *, error *);
void nvim__redraw(keysets::redraw *, error *);
details::vec<std::pair<string, object>> nvim_exec2(std::uint64_t, string, keysets::exec_opts *, error *);
void nvim_command(string, error *);
object nvim_eval(string, arena *, error *);
object nvim_call_function(string, details::vec<object>, arena *, error *);
object nvim_call_dict_function(object, string, details::vec<object>, arena *, error *);
details::vec<std::pair<string, object>> nvim_parse_expression(string, string, bool, arena *, error *);
nvpp::window nvim_open_win(nvpp::buffer, bool, keysets::win_config *, error *);
void nvim_win_set_config(nvpp::window, keysets::win_config *, error *);
keysets::win_config nvim_win_get_config(nvpp::window, arena *, error *);
nvpp::buffer nvim_win_get_buf(nvpp::window, error *);
void nvim_win_set_buf(nvpp::window, nvpp::buffer, error *);
details::vec<object> nvim_win_get_cursor(nvpp::window, arena *, error *);
void nvim_win_set_cursor(nvpp::window, details::vec<object>, error *);
std::int64_t nvim_win_get_height(nvpp::window, error *);
void nvim_win_set_height(nvpp::window, std::int64_t, error *);
std::int64_t nvim_win_get_width(nvpp::window, error *);
void nvim_win_set_width(nvpp::window, std::int64_t, error *);
object nvim_win_get_var(nvpp::window, string, arena *, error *);
void nvim_win_set_var(nvpp::window, string, object, error *);
void nvim_win_del_var(nvpp::window, string, error *);
details::vec<object> nvim_win_get_position(nvpp::window, arena *, error *);
nvpp::tabpage nvim_win_get_tabpage(nvpp::window, error *);
std::int64_t nvim_win_get_number(nvpp::window, error *);
bool nvim_win_is_valid(nvpp::window);
void nvim_win_hide(nvpp::window, error *);
void nvim_win_close(nvpp::window, bool, error *);
object nvim_win_call(nvpp::window, nvpp::lua_ref, error *);
void nvim_win_set_hl_ns(nvpp::window, std::int64_t, error *);
details::vec<std::pair<string, object>> nvim_win_text_height(nvpp::window, keysets::win_text_height *, arena *, error *);
}
}

namespace nvpp::api {

constexpr auto internal_call_mask = ((uint64_t) 1 << (sizeof(uint64_t) * 8 - 1));
constexpr auto viml_internal_call = internal_call_mask;
constexpr auto lua_internal_call = viml_internal_call + 1;
inline auto get_autocmds(keysets::builder::get_autocmds opts) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::dict>>, error> {
  auto err = error{};
  keysets::get_autocmds opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_get_autocmds(&opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto create_autocmd(object event, keysets::builder::create_autocmd opts) noexcept -> std::expected<arena_mem<std::int64_t>, error> {
  auto err = error{};
  keysets::create_autocmd opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<std::int64_t>(c::nvim_create_autocmd(lua_internal_call, event, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto del_autocmd(std::int64_t id) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_autocmd(id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto clear_autocmds(keysets::builder::clear_autocmds opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::clear_autocmds opts_ = opts;
  nvpp::arena arena{};
  static_cast<void>(c::nvim_clear_autocmds(&opts_, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto create_augroup(string name, keysets::builder::create_augroup opts) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  keysets::create_augroup opts_ = opts;
  const auto ret = static_cast<std::int64_t>(c::nvim_create_augroup(lua_internal_call, name, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto del_augroup_by_id(std::int64_t id) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_augroup_by_id(id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto del_augroup_by_name(string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_augroup_by_name(name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto exec_autocmds(object event, keysets::builder::exec_autocmds opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::exec_autocmds opts_ = opts;
  nvpp::arena arena{};
  static_cast<void>(c::nvim_exec_autocmds(event, &opts_, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_line_count(nvpp::buffer buffer) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_buf_line_count(buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_attach(nvpp::buffer buffer, bool send_buffer, keysets::builder::buf_attach opts) noexcept -> std::expected<bool, error> {
  auto err = error{};
  keysets::buf_attach opts_ = opts;
  const auto ret = static_cast<bool>(c::nvim_buf_attach(lua_internal_call, buffer, send_buffer, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_detach(nvpp::buffer buffer) noexcept -> std::expected<bool, error> {
  auto err = error{};
  const auto ret = static_cast<bool>(c::nvim_buf_detach(lua_internal_call, buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_get_lines(nvpp::buffer buffer, std::int64_t start, std::int64_t end, bool strict_indexing) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::string>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::string>>(c::nvim_buf_get_lines(lua_internal_call, buffer, start, end, strict_indexing, &arena, nullptr, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_set_lines(nvpp::buffer buffer, std::int64_t start, std::int64_t end, bool strict_indexing, array_of<string> replacement) noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_buf_set_lines(lua_internal_call, buffer, start, end, strict_indexing, replacement, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_set_text(nvpp::buffer buffer, std::int64_t start_row, std::int64_t start_col, std::int64_t end_row, std::int64_t end_col, array_of<string> replacement) noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_buf_set_text(lua_internal_call, buffer, start_row, start_col, end_row, end_col, replacement, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_get_text(nvpp::buffer buffer, std::int64_t start_row, std::int64_t start_col, std::int64_t end_row, std::int64_t end_col, keysets::builder::empty opts) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::string>>, error> {
  auto err = error{};
  keysets::empty opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::string>>(c::nvim_buf_get_text(lua_internal_call, buffer, start_row, start_col, end_row, end_col, &opts_, &arena, nullptr, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_get_offset(nvpp::buffer buffer, std::int64_t index) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_buf_get_offset(buffer, index, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_get_var(nvpp::buffer buffer, string name) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_buf_get_var(buffer, name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_get_changedtick(nvpp::buffer buffer) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_buf_get_changedtick(buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_get_keymap(nvpp::buffer buffer, string mode) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::dict>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_buf_get_keymap(buffer, mode, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_set_keymap(nvpp::buffer buffer, string mode, string lhs, string rhs, keysets::builder::keymap opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::keymap opts_ = opts;
  static_cast<void>(c::nvim_buf_set_keymap(lua_internal_call, buffer, mode, lhs, rhs, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_del_keymap(nvpp::buffer buffer, string mode, string lhs) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_del_keymap(lua_internal_call, buffer, mode, lhs, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_set_var(nvpp::buffer buffer, string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_set_var(buffer, name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_del_var(nvpp::buffer buffer, string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_del_var(buffer, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_get_name(nvpp::buffer buffer) noexcept -> std::expected<alloc::string, error> {
  auto err = error{};
  const auto ret = static_cast<alloc::string>(c::nvim_buf_get_name(buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_set_name(nvpp::buffer buffer, string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_set_name(buffer, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_is_loaded(nvpp::buffer buffer) noexcept -> bool {
  const auto ret = static_cast<bool>(c::nvim_buf_is_loaded(buffer));
  return ret;
}
inline auto buf_delete(nvpp::buffer buffer, keysets::builder::buf_delete opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::buf_delete opts_ = opts;
  static_cast<void>(c::nvim_buf_delete(buffer, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_is_valid(nvpp::buffer buffer) noexcept -> bool {
  const auto ret = static_cast<bool>(c::nvim_buf_is_valid(buffer));
  return ret;
}
inline auto buf_del_mark(nvpp::buffer buffer, string name) noexcept -> std::expected<bool, error> {
  auto err = error{};
  const auto ret = static_cast<bool>(c::nvim_buf_del_mark(buffer, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_set_mark(nvpp::buffer buffer, string name, std::int64_t line, std::int64_t col, keysets::builder::empty opts) noexcept -> std::expected<bool, error> {
  auto err = error{};
  keysets::empty opts_ = opts;
  const auto ret = static_cast<bool>(c::nvim_buf_set_mark(buffer, name, line, col, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_get_mark(nvpp::buffer buffer, string name) noexcept -> std::expected<arena_mem<alloc::array_of<std::int64_t>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<std::int64_t>>(c::nvim_buf_get_mark(buffer, name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_call(nvpp::buffer buffer, nvpp::lua_ref fun) noexcept -> std::expected<alloc::object, error> {
  auto err = error{};
  const auto ret = static_cast<alloc::object>(c::nvim_buf_call(buffer, fun, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto _buf_stats(nvpp::buffer buffer) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim__buf_stats(buffer, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto parse_cmd(string str, keysets::builder::empty opts) noexcept -> std::expected<arena_mem<keysets::cmd>, error> {
  auto err = error{};
  keysets::empty opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<keysets::cmd>(c::nvim_parse_cmd(str, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto cmd(keysets::builder::cmd cmd, keysets::builder::cmd_opts opts) noexcept -> std::expected<arena_mem<alloc::string>, error> {
  auto err = error{};
  keysets::cmd cmd_ = cmd;
  keysets::cmd_opts opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::string>(c::nvim_cmd(lua_internal_call, &cmd_, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto create_user_command(string name, object command, keysets::builder::user_command opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::user_command opts_ = opts;
  static_cast<void>(c::nvim_create_user_command(lua_internal_call, name, command, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto del_user_command(string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_user_command(name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_create_user_command(nvpp::buffer buffer, string name, object command, keysets::builder::user_command opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::user_command opts_ = opts;
  static_cast<void>(c::nvim_buf_create_user_command(lua_internal_call, buffer, name, command, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto buf_del_user_command(nvpp::buffer buffer, string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_del_user_command(buffer, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_commands(keysets::builder::get_commands opts) noexcept -> std::expected<arena_mem<alloc::dict_of<alloc::dict>>, error> {
  auto err = error{};
  keysets::get_commands opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict_of<alloc::dict>>(c::nvim_get_commands(&opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_get_commands(nvpp::buffer buffer, keysets::builder::get_commands opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::get_commands opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_buf_get_commands(buffer, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto error_event(std::int64_t type, string msg) noexcept -> void {
  static_cast<void>(c::nvim_error_event(lua_internal_call, type, msg));
}
inline auto ui_term_event(string event, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_term_event(lua_internal_call, event, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto create_namespace(string name) noexcept -> std::int64_t {
  const auto ret = static_cast<std::int64_t>(c::nvim_create_namespace(name));
  return ret;
}
inline auto get_namespaces() noexcept -> arena_mem<alloc::dict_of<std::int64_t>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict_of<std::int64_t>>(c::nvim_get_namespaces(&arena));
  return arena.finish(ret);
}
inline auto buf_get_extmark_by_id(nvpp::buffer buffer, std::int64_t ns_id, std::int64_t id, keysets::builder::get_extmark opts) noexcept -> std::expected<arena_mem<alloc::array>, error> {
  auto err = error{};
  keysets::get_extmark opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim_buf_get_extmark_by_id(buffer, ns_id, id, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_get_extmarks(nvpp::buffer buffer, std::int64_t ns_id, object start, object end, keysets::builder::get_extmarks opts) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::dict>>, error> {
  auto err = error{};
  keysets::get_extmarks opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_buf_get_extmarks(buffer, ns_id, start, end, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto buf_set_extmark(nvpp::buffer buffer, std::int64_t ns_id, std::int64_t line, std::int64_t col, keysets::builder::set_extmark opts) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  keysets::set_extmark opts_ = opts;
  const auto ret = static_cast<std::int64_t>(c::nvim_buf_set_extmark(buffer, ns_id, line, col, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_del_extmark(nvpp::buffer buffer, std::int64_t ns_id, std::int64_t id) noexcept -> std::expected<bool, error> {
  auto err = error{};
  const auto ret = static_cast<bool>(c::nvim_buf_del_extmark(buffer, ns_id, id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto buf_clear_namespace(nvpp::buffer buffer, std::int64_t ns_id, std::int64_t line_start, std::int64_t line_end) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_buf_clear_namespace(buffer, ns_id, line_start, line_end, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto set_decoration_provider(std::int64_t ns_id, keysets::builder::set_decoration_provider opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::set_decoration_provider opts_ = opts;
  static_cast<void>(c::nvim_set_decoration_provider(ns_id, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto _buf_debug_extmarks(nvpp::buffer buffer, bool keys, bool dot) noexcept -> std::expected<alloc::string, error> {
  auto err = error{};
  const auto ret = static_cast<alloc::string>(c::nvim__buf_debug_extmarks(buffer, keys, dot, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto _ns_set(std::int64_t ns_id, keysets::builder::ns_opts opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::ns_opts opts_ = opts;
  static_cast<void>(c::nvim__ns_set(ns_id, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto _ns_get(std::int64_t ns_id) noexcept -> std::expected<arena_mem<keysets::ns_opts>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<keysets::ns_opts>(c::nvim__ns_get(ns_id, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto get_option_value(string name, keysets::builder::option opts) noexcept -> std::expected<alloc::object, error> {
  auto err = error{};
  keysets::option opts_ = opts;
  const auto ret = static_cast<alloc::object>(c::nvim_get_option_value(name, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto set_option_value(string name, object value, keysets::builder::option opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::option opts_ = opts;
  static_cast<void>(c::nvim_set_option_value(lua_internal_call, name, value, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_all_options_info() noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_all_options_info(&arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto get_option_info2(string name, keysets::builder::option opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::option opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_option_info2(name, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto tabpage_list_wins(nvpp::tabpage tabpage) noexcept -> std::expected<arena_mem<alloc::array_of<nvpp::window>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<nvpp::window>>(c::nvim_tabpage_list_wins(tabpage, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto tabpage_get_var(nvpp::tabpage tabpage, string name) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_tabpage_get_var(tabpage, name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto tabpage_set_var(nvpp::tabpage tabpage, string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_tabpage_set_var(tabpage, name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto tabpage_del_var(nvpp::tabpage tabpage, string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_tabpage_del_var(tabpage, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto tabpage_get_win(nvpp::tabpage tabpage) noexcept -> std::expected<nvpp::window, error> {
  auto err = error{};
  const auto ret = static_cast<nvpp::window>(c::nvim_tabpage_get_win(tabpage, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto tabpage_set_win(nvpp::tabpage tabpage, nvpp::window win) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_tabpage_set_win(tabpage, win, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto tabpage_get_number(nvpp::tabpage tabpage) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_tabpage_get_number(tabpage, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto tabpage_is_valid(nvpp::tabpage tabpage) noexcept -> bool {
  const auto ret = static_cast<bool>(c::nvim_tabpage_is_valid(tabpage));
  return ret;
}
inline auto open_tabpage(nvpp::buffer buffer, bool enter, keysets::builder::tabpage_config config) noexcept -> std::expected<nvpp::tabpage, error> {
  auto err = error{};
  keysets::tabpage_config config_ = config;
  const auto ret = static_cast<nvpp::tabpage>(c::nvim_open_tabpage(buffer, enter, &config_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto ui_attach(std::int64_t width, std::int64_t height, dict options) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_attach(lua_internal_call, width, height, options, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_set_focus(bool gained) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_set_focus(lua_internal_call, gained, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_detach() noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_detach(lua_internal_call, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_try_resize(std::int64_t width, std::int64_t height) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_try_resize(lua_internal_call, width, height, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_set_option(string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_set_option(lua_internal_call, name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_try_resize_grid(std::int64_t grid, std::int64_t width, std::int64_t height) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_try_resize_grid(lua_internal_call, grid, width, height, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_pum_set_height(std::int64_t height) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_pum_set_height(lua_internal_call, height, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_pum_set_bounds(double width, double height, double row, double col) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_pum_set_bounds(lua_internal_call, width, height, row, col, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto ui_send(string content) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_ui_send(lua_internal_call, content, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_hl_id_by_name(string name) noexcept -> std::int64_t {
  const auto ret = static_cast<std::int64_t>(c::nvim_get_hl_id_by_name(name));
  return ret;
}
inline auto get_hl(std::int64_t ns_id, keysets::builder::get_highlight opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::get_highlight opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_hl(ns_id, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto set_hl(std::int64_t ns_id, string name, keysets::builder::highlight val) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::highlight val_ = val;
  static_cast<void>(c::nvim_set_hl(lua_internal_call, ns_id, name, &val_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_hl_ns(keysets::builder::get_ns opts) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  keysets::get_ns opts_ = opts;
  const auto ret = static_cast<std::int64_t>(c::nvim_get_hl_ns(&opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto set_hl_ns(std::int64_t ns_id) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_hl_ns(ns_id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto set_hl_ns_fast(std::int64_t ns_id) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_hl_ns_fast(ns_id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto feedkeys(string keys, string mode, bool escape_ks) noexcept -> void {
  static_cast<void>(c::nvim_feedkeys(keys, mode, escape_ks));
}
inline auto input(string keys) noexcept -> std::int64_t {
  const auto ret = static_cast<std::int64_t>(c::nvim_input(lua_internal_call, keys));
  return ret;
}
inline auto input_mouse(string button, string action, string modifier, std::int64_t grid, std::int64_t row, std::int64_t col) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_input_mouse(button, action, modifier, grid, row, col, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto replace_termcodes(string str, bool from_part, bool do_lt, bool special) noexcept -> alloc::string {
  const auto ret = static_cast<alloc::string>(c::nvim_replace_termcodes(str, from_part, do_lt, special));
  return ret;
}
inline auto exec_lua(string code, array args) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_exec_lua(code, args, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _exec_lua_fast(string code, array args) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim__exec_lua_fast(code, args, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto strwidth(string text) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_strwidth(text, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto list_runtime_paths() noexcept -> std::expected<arena_mem<alloc::array_of<alloc::string>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::string>>(c::nvim_list_runtime_paths(&arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _runtime_inspect() noexcept -> arena_mem<alloc::array> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim__runtime_inspect(&arena));
  return arena.finish(ret);
}
inline auto get_runtime_file(string name, bool all) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::string>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::string>>(c::nvim_get_runtime_file(name, all, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _get_lib_dir() noexcept -> alloc::string {
  const auto ret = static_cast<alloc::string>(c::nvim__get_lib_dir());
  return ret;
}
inline auto _get_runtime(array_of<string> pat, bool all, keysets::builder::runtime opts) noexcept -> std::expected<arena_mem<alloc::array_of<alloc::string>>, error> {
  auto err = error{};
  keysets::runtime opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::string>>(c::nvim__get_runtime(pat, all, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto set_current_dir(string dir) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_current_dir(dir, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_current_line() noexcept -> std::expected<arena_mem<alloc::string>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::string>(c::nvim_get_current_line(&arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto set_current_line(string line) noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_set_current_line(line, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto del_current_line() noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_del_current_line(&arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_var(string name) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_get_var(name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto set_var(string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_var(name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto del_var(string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_var(name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_vvar(string name) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_get_vvar(name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto set_vvar(string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_vvar(name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto echo(array_of<array> chunks, bool history, keysets::builder::echo_opts opts) noexcept -> std::expected<alloc::object, error> {
  auto err = error{};
  keysets::echo_opts opts_ = opts;
  const auto ret = static_cast<alloc::object>(c::nvim_echo(chunks, history, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto list_bufs() noexcept -> arena_mem<alloc::array_of<nvpp::buffer>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<nvpp::buffer>>(c::nvim_list_bufs(&arena));
  return arena.finish(ret);
}
inline auto get_current_buf() noexcept -> nvpp::buffer {
  const auto ret = static_cast<nvpp::buffer>(c::nvim_get_current_buf());
  return ret;
}
inline auto set_current_buf(nvpp::buffer buffer) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_current_buf(buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto list_wins() noexcept -> arena_mem<alloc::array_of<nvpp::window>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<nvpp::window>>(c::nvim_list_wins(&arena));
  return arena.finish(ret);
}
inline auto get_current_win() noexcept -> nvpp::window {
  const auto ret = static_cast<nvpp::window>(c::nvim_get_current_win());
  return ret;
}
inline auto set_current_win(nvpp::window window) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_current_win(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto create_buf(bool listed, bool scratch) noexcept -> std::expected<nvpp::buffer, error> {
  auto err = error{};
  const auto ret = static_cast<nvpp::buffer>(c::nvim_create_buf(listed, scratch, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto open_term(nvpp::buffer buffer, keysets::builder::open_term opts) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  keysets::open_term opts_ = opts;
  const auto ret = static_cast<std::int64_t>(c::nvim_open_term(buffer, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto chan_send(std::int64_t chan, string data) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_chan_send(chan, data, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto list_tabpages() noexcept -> arena_mem<alloc::array_of<nvpp::tabpage>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<nvpp::tabpage>>(c::nvim_list_tabpages(&arena));
  return arena.finish(ret);
}
inline auto get_current_tabpage() noexcept -> nvpp::tabpage {
  const auto ret = static_cast<nvpp::tabpage>(c::nvim_get_current_tabpage());
  return ret;
}
inline auto set_current_tabpage(nvpp::tabpage tabpage) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_set_current_tabpage(tabpage, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto paste(string data, bool crlf, std::int64_t phase) noexcept -> std::expected<arena_mem<bool>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<bool>(c::nvim_paste(lua_internal_call, data, crlf, phase, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto put(array_of<string> lines, string type, bool after, bool follow) noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_put(lines, type, after, follow, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_color_by_name(string name) noexcept -> std::int64_t {
  const auto ret = static_cast<std::int64_t>(c::nvim_get_color_by_name(name));
  return ret;
}
inline auto get_color_map() noexcept -> arena_mem<alloc::dict_of<std::int64_t>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict_of<std::int64_t>>(c::nvim_get_color_map(&arena));
  return arena.finish(ret);
}
inline auto get_context(keysets::builder::context opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::context opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_context(&opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto load_context(dict dict) noexcept -> std::expected<alloc::object, error> {
  auto err = error{};
  const auto ret = static_cast<alloc::object>(c::nvim_load_context(dict, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto get_mode() noexcept -> arena_mem<alloc::dict> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_mode(&arena));
  return arena.finish(ret);
}
inline auto get_keymap(string mode) noexcept -> arena_mem<alloc::array_of<alloc::dict>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_get_keymap(mode, &arena));
  return arena.finish(ret);
}
inline auto set_keymap(string mode, string lhs, string rhs, keysets::builder::keymap opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::keymap opts_ = opts;
  static_cast<void>(c::nvim_set_keymap(lua_internal_call, mode, lhs, rhs, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto del_keymap(string mode, string lhs) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_del_keymap(lua_internal_call, mode, lhs, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_api_info() noexcept -> arena_mem<alloc::array_of<alloc::object>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::object>>(c::nvim_get_api_info(lua_internal_call, &arena));
  return arena.finish(ret);
}
inline auto set_client_info(string name, dict version, string type, dict methods, dict attributes) noexcept -> std::expected<void, error> {
  auto err = error{};
  nvpp::arena arena{};
  static_cast<void>(c::nvim_set_client_info(lua_internal_call, name, version, type, methods, attributes, &arena, &err));
  arena.finish().free();
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto _chan_set_detach(bool detach) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim__chan_set_detach(lua_internal_call, detach, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto get_chan_info(std::int64_t chan) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_get_chan_info(lua_internal_call, chan, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto list_chans() noexcept -> arena_mem<alloc::array_of<alloc::dict>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_list_chans(&arena));
  return arena.finish(ret);
}
inline auto _id(object obj) noexcept -> arena_mem<alloc::object> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim__id(obj, &arena));
  return arena.finish(ret);
}
inline auto _id_array(array arr) noexcept -> arena_mem<alloc::array> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim__id_array(arr, &arena));
  return arena.finish(ret);
}
inline auto _id_dict(dict dct) noexcept -> arena_mem<alloc::dict> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim__id_dict(dct, &arena));
  return arena.finish(ret);
}
inline auto _id_float(double flt) noexcept -> double {
  const auto ret = static_cast<double>(c::nvim__id_float(flt));
  return ret;
}
inline auto _stats() noexcept -> arena_mem<alloc::dict> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim__stats(&arena));
  return arena.finish(ret);
}
inline auto list_uis() noexcept -> arena_mem<alloc::array_of<alloc::dict>> {
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<alloc::dict>>(c::nvim_list_uis(&arena));
  return arena.finish(ret);
}
inline auto get_proc_children(std::int64_t pid) noexcept -> std::expected<arena_mem<alloc::array>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim_get_proc_children(pid, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto get_proc(std::int64_t pid) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_get_proc(pid, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto select_popupmenu_item(std::int64_t item, bool insert, bool finish, keysets::builder::empty opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::empty opts_ = opts;
  static_cast<void>(c::nvim_select_popupmenu_item(item, insert, finish, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto _inspect_cell(std::int64_t grid, std::int64_t row, std::int64_t col) noexcept -> std::expected<arena_mem<alloc::array>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim__inspect_cell(grid, row, col, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _screenshot(string path) noexcept -> void {
  static_cast<void>(c::nvim__screenshot(path));
}
inline auto _invalidate_glyph_cache() noexcept -> void {
  static_cast<void>(c::nvim__invalidate_glyph_cache());
}
inline auto _unpack(string str) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim__unpack(str, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto del_mark(string name) noexcept -> std::expected<bool, error> {
  auto err = error{};
  const auto ret = static_cast<bool>(c::nvim_del_mark(name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto get_mark(string name, keysets::builder::empty opts) noexcept -> std::expected<arena_mem<alloc::array>, error> {
  auto err = error{};
  keysets::empty opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array>(c::nvim_get_mark(name, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto eval_statusline(string str, keysets::builder::eval_statusline opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::eval_statusline opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_eval_statusline(str, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _complete_set(std::int64_t index, keysets::builder::complete_set opts) noexcept -> std::expected<arena_mem<alloc::dict_of<double>>, error> {
  auto err = error{};
  keysets::complete_set opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict_of<double>>(c::nvim__complete_set(index, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto _redraw(keysets::builder::redraw opts) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::redraw opts_ = opts;
  static_cast<void>(c::nvim__redraw(&opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto exec2(string src, keysets::builder::exec_opts opts) noexcept -> std::expected<alloc::dict, error> {
  auto err = error{};
  keysets::exec_opts opts_ = opts;
  const auto ret = static_cast<alloc::dict>(c::nvim_exec2(lua_internal_call, src, &opts_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto command(string command) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_command(command, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto eval(string expr) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_eval(expr, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto call_function(string fn, array args) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_call_function(fn, args, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto call_dict_function(object dict, string fn, array args) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_call_dict_function(dict, fn, args, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto parse_expression(string expr, string flags, bool highlight) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_parse_expression(expr, flags, highlight, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto open_win(nvpp::buffer buffer, bool enter, keysets::builder::win_config config) noexcept -> std::expected<nvpp::window, error> {
  auto err = error{};
  keysets::win_config config_ = config;
  const auto ret = static_cast<nvpp::window>(c::nvim_open_win(buffer, enter, &config_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_set_config(nvpp::window window, keysets::builder::win_config config) noexcept -> std::expected<void, error> {
  auto err = error{};
  keysets::win_config config_ = config;
  static_cast<void>(c::nvim_win_set_config(window, &config_, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_config(nvpp::window window) noexcept -> std::expected<arena_mem<keysets::win_config>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<keysets::win_config>(c::nvim_win_get_config(window, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto win_get_buf(nvpp::window window) noexcept -> std::expected<nvpp::buffer, error> {
  auto err = error{};
  const auto ret = static_cast<nvpp::buffer>(c::nvim_win_get_buf(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_set_buf(nvpp::window window, nvpp::buffer buffer) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_buf(window, buffer, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_cursor(nvpp::window window) noexcept -> std::expected<arena_mem<alloc::array_of<std::int64_t>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<std::int64_t>>(c::nvim_win_get_cursor(window, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto win_set_cursor(nvpp::window window, array_of<std::int64_t> pos) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_cursor(window, pos, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_height(nvpp::window window) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_win_get_height(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_set_height(nvpp::window window, std::int64_t height) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_height(window, height, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_width(nvpp::window window) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_win_get_width(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_set_width(nvpp::window window, std::int64_t width) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_width(window, width, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_var(nvpp::window window, string name) noexcept -> std::expected<arena_mem<alloc::object>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::object>(c::nvim_win_get_var(window, name, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto win_set_var(nvpp::window window, string name, object value) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_var(window, name, value, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_del_var(nvpp::window window, string name) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_del_var(window, name, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_get_position(nvpp::window window) noexcept -> std::expected<arena_mem<alloc::array_of<std::int64_t>>, error> {
  auto err = error{};
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::array_of<std::int64_t>>(c::nvim_win_get_position(window, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
inline auto win_get_tabpage(nvpp::window window) noexcept -> std::expected<nvpp::tabpage, error> {
  auto err = error{};
  const auto ret = static_cast<nvpp::tabpage>(c::nvim_win_get_tabpage(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_get_number(nvpp::window window) noexcept -> std::expected<std::int64_t, error> {
  auto err = error{};
  const auto ret = static_cast<std::int64_t>(c::nvim_win_get_number(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_is_valid(nvpp::window window) noexcept -> bool {
  const auto ret = static_cast<bool>(c::nvim_win_is_valid(window));
  return ret;
}
inline auto win_hide(nvpp::window window) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_hide(window, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_close(nvpp::window window, bool force) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_close(window, force, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_call(nvpp::window window, nvpp::lua_ref fun) noexcept -> std::expected<alloc::object, error> {
  auto err = error{};
  const auto ret = static_cast<alloc::object>(c::nvim_win_call(window, fun, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return ret;
}
inline auto win_set_hl_ns(nvpp::window window, std::int64_t ns_id) noexcept -> std::expected<void, error> {
  auto err = error{};
  static_cast<void>(c::nvim_win_set_hl_ns(window, ns_id, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return {};
}
inline auto win_text_height(nvpp::window window, keysets::builder::win_text_height opts) noexcept -> std::expected<arena_mem<alloc::dict>, error> {
  auto err = error{};
  keysets::win_text_height opts_ = opts;
  nvpp::arena arena{};
  const auto ret = static_cast<alloc::dict>(c::nvim_win_text_height(window, &opts_, &arena, &err));
  if (err.is_set()) {
    return std::unexpected(err);
  }
  return arena.finish(ret);
}
}