#pragma once

#include <optional>
#include <nvpp/types.hh>

namespace nvpp::keysets {
extern "C" {
struct empty {
  uint64_t m_mask;
};
struct context {
  uint64_t m_mask;
  details::vec<object> m_types;
  std::optional<array_of<string>> types() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_types;
    }
    return {};
  }
};
struct set_decoration_provider {
  uint64_t m_mask;
  lua_ref m_on_start;
  lua_ref m_on_buf;
  lua_ref m_on_win;
  lua_ref m_on_line;
  lua_ref m_on_range;
  lua_ref m_on_end;
  lua_ref m__on_hl_def;
  lua_ref m__on_spell_nav;
  lua_ref m__on_conceal_line;
  std::optional<lua_ref> on_buf() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_on_buf;
    }
    return {};
  }
  std::optional<lua_ref> on_end() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_on_end;
    }
    return {};
  }
  std::optional<lua_ref> on_win() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_on_win;
    }
    return {};
  }
  std::optional<lua_ref> on_line() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_on_line;
    }
    return {};
  }
  std::optional<lua_ref> on_range() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_on_range;
    }
    return {};
  }
  std::optional<lua_ref> on_start() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_on_start;
    }
    return {};
  }
  std::optional<lua_ref> _on_hl_def() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m__on_hl_def;
    }
    return {};
  }
  std::optional<lua_ref> _on_spell_nav() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m__on_spell_nav;
    }
    return {};
  }
  std::optional<lua_ref> _on_conceal_line() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m__on_conceal_line;
    }
    return {};
  }
};
struct set_extmark {
  uint64_t m_mask;
  std::int64_t m_id;
  std::int64_t m_end_line;
  std::int64_t m_end_row;
  std::int64_t m_end_col;
  object m_hl_group;
  details::vec<object> m_virt_text;
  string m_virt_text_pos;
  std::int64_t m_virt_text_win_col;
  bool m_virt_text_hide;
  bool m_virt_text_repeat_linebreak;
  bool m_hl_eol;
  string m_hl_mode;
  bool m_invalidate;
  bool m_ephemeral;
  std::int64_t m_priority;
  bool m_right_gravity;
  bool m_end_right_gravity;
  details::vec<object> m_virt_lines;
  bool m_virt_lines_above;
  bool m_virt_lines_leftcol;
  string m_virt_lines_overflow;
  bool m_strict;
  string m_sign_text;
  nvpp::hl_group_id m_sign_hl_group;
  nvpp::hl_group_id m_number_hl_group;
  nvpp::hl_group_id m_line_hl_group;
  nvpp::hl_group_id m_cursorline_hl_group;
  string m_conceal;
  string m_conceal_lines;
  bool m_spell;
  bool m_ui_watched;
  bool m_undo_restore;
  string m_url;
  bool m_scoped;
  std::int64_t m__subpriority;
  std::optional<std::int64_t> id() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_id;
    }
    return {};
  }
  std::optional<string> url() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_url;
    }
    return {};
  }
  std::optional<bool> spell() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_spell;
    }
    return {};
  }
  std::optional<bool> scoped() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_scoped;
    }
    return {};
  }
  std::optional<bool> hl_eol() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_hl_eol;
    }
    return {};
  }
  std::optional<bool> strict() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_strict;
    }
    return {};
  }
  std::optional<std::int64_t> end_col() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_end_col;
    }
    return {};
  }
  std::optional<string> conceal() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_conceal;
    }
    return {};
  }
  std::optional<string> hl_mode() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_hl_mode;
    }
    return {};
  }
  std::optional<std::int64_t> end_row() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_end_row;
    }
    return {};
  }
  std::optional<std::int64_t> end_line() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_end_line;
    }
    return {};
  }
  std::optional<object> hl_group() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_hl_group;
    }
    return {};
  }
  std::optional<std::int64_t> priority() const noexcept {
    if (m_mask & std::uint64_t{1} << 13) {
      return m_priority;
    }
    return {};
  }
  std::optional<bool> ephemeral() const noexcept {
    if (m_mask & std::uint64_t{1} << 14) {
      return m_ephemeral;
    }
    return {};
  }
  std::optional<string> sign_text() const noexcept {
    if (m_mask & std::uint64_t{1} << 15) {
      return m_sign_text;
    }
    return {};
  }
  std::optional<array> virt_text() const noexcept {
    if (m_mask & std::uint64_t{1} << 16) {
      return m_virt_text;
    }
    return {};
  }
  std::optional<bool> invalidate() const noexcept {
    if (m_mask & std::uint64_t{1} << 17) {
      return m_invalidate;
    }
    return {};
  }
  std::optional<bool> ui_watched() const noexcept {
    if (m_mask & std::uint64_t{1} << 18) {
      return m_ui_watched;
    }
    return {};
  }
  std::optional<array> virt_lines() const noexcept {
    if (m_mask & std::uint64_t{1} << 19) {
      return m_virt_lines;
    }
    return {};
  }
  std::optional<std::int64_t> _subpriority() const noexcept {
    if (m_mask & std::uint64_t{1} << 20) {
      return m__subpriority;
    }
    return {};
  }
  std::optional<bool> undo_restore() const noexcept {
    if (m_mask & std::uint64_t{1} << 21) {
      return m_undo_restore;
    }
    return {};
  }
  std::optional<string> conceal_lines() const noexcept {
    if (m_mask & std::uint64_t{1} << 22) {
      return m_conceal_lines;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> line_hl_group() const noexcept {
    if (m_mask & std::uint64_t{1} << 23) {
      return m_line_hl_group;
    }
    return {};
  }
  std::optional<bool> right_gravity() const noexcept {
    if (m_mask & std::uint64_t{1} << 24) {
      return m_right_gravity;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> sign_hl_group() const noexcept {
    if (m_mask & std::uint64_t{1} << 25) {
      return m_sign_hl_group;
    }
    return {};
  }
  std::optional<string> virt_text_pos() const noexcept {
    if (m_mask & std::uint64_t{1} << 26) {
      return m_virt_text_pos;
    }
    return {};
  }
  std::optional<bool> virt_text_hide() const noexcept {
    if (m_mask & std::uint64_t{1} << 27) {
      return m_virt_text_hide;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> number_hl_group() const noexcept {
    if (m_mask & std::uint64_t{1} << 28) {
      return m_number_hl_group;
    }
    return {};
  }
  std::optional<bool> virt_lines_above() const noexcept {
    if (m_mask & std::uint64_t{1} << 29) {
      return m_virt_lines_above;
    }
    return {};
  }
  std::optional<bool> end_right_gravity() const noexcept {
    if (m_mask & std::uint64_t{1} << 30) {
      return m_end_right_gravity;
    }
    return {};
  }
  std::optional<std::int64_t> virt_text_win_col() const noexcept {
    if (m_mask & std::uint64_t{1} << 31) {
      return m_virt_text_win_col;
    }
    return {};
  }
  std::optional<bool> virt_lines_leftcol() const noexcept {
    if (m_mask & std::uint64_t{1} << 32) {
      return m_virt_lines_leftcol;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> cursorline_hl_group() const noexcept {
    if (m_mask & std::uint64_t{1} << 33) {
      return m_cursorline_hl_group;
    }
    return {};
  }
  std::optional<string> virt_lines_overflow() const noexcept {
    if (m_mask & std::uint64_t{1} << 34) {
      return m_virt_lines_overflow;
    }
    return {};
  }
  std::optional<bool> virt_text_repeat_linebreak() const noexcept {
    if (m_mask & std::uint64_t{1} << 35) {
      return m_virt_text_repeat_linebreak;
    }
    return {};
  }
};
struct get_extmark {
  uint64_t m_mask;
  bool m_details;
  bool m_hl_name;
  std::optional<bool> details() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_details;
    }
    return {};
  }
  std::optional<bool> hl_name() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_hl_name;
    }
    return {};
  }
};
struct get_extmarks {
  uint64_t m_mask;
  std::int64_t m_limit;
  bool m_details;
  bool m_hl_name;
  bool m_overlap;
  string m_type;
  std::optional<string> type() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_type;
    }
    return {};
  }
  std::optional<std::int64_t> limit() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_limit;
    }
    return {};
  }
  std::optional<bool> details() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_details;
    }
    return {};
  }
  std::optional<bool> hl_name() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_hl_name;
    }
    return {};
  }
  std::optional<bool> overlap() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_overlap;
    }
    return {};
  }
};
struct keymap {
  uint64_t m_mask;
  bool m_noremap;
  bool m_nowait;
  bool m_silent;
  bool m_script;
  bool m_expr;
  bool m_unique;
  nvpp::lua_ref m_callback;
  string m_desc;
  bool m_replace_keycodes;
  std::optional<string> desc() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_desc;
    }
    return {};
  }
  std::optional<bool> expr() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_expr;
    }
    return {};
  }
  std::optional<bool> script() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_script;
    }
    return {};
  }
  std::optional<bool> silent() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_silent;
    }
    return {};
  }
  std::optional<bool> unique() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_unique;
    }
    return {};
  }
  std::optional<bool> nowait() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_nowait;
    }
    return {};
  }
  std::optional<bool> noremap() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_noremap;
    }
    return {};
  }
  std::optional<nvpp::lua_ref> callback() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_callback;
    }
    return {};
  }
  std::optional<bool> replace_keycodes() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_replace_keycodes;
    }
    return {};
  }
};
struct get_commands {
  bool builtin;
};struct user_command {
  uint64_t m_mask;
  object m_addr;
  bool m_bang;
  bool m_bar;
  object m_complete;
  object m_count;
  object m_desc;
  bool m_force;
  bool m_keepscript;
  object m_nargs;
  object m_preview;
  object m_range;
  bool m_register_;
  std::optional<bool> bar() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_bar;
    }
    return {};
  }
  std::optional<object> addr() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_addr;
    }
    return {};
  }
  std::optional<bool> bang() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_bang;
    }
    return {};
  }
  std::optional<object> desc() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_desc;
    }
    return {};
  }
  std::optional<object> count() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_count;
    }
    return {};
  }
  std::optional<bool> force() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_force;
    }
    return {};
  }
  std::optional<object> nargs() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_nargs;
    }
    return {};
  }
  std::optional<object> range() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_range;
    }
    return {};
  }
  std::optional<object> preview() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_preview;
    }
    return {};
  }
  std::optional<object> complete() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_complete;
    }
    return {};
  }
  std::optional<bool> register_() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_register_;
    }
    return {};
  }
  std::optional<bool> keepscript() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_keepscript;
    }
    return {};
  }
};
struct win_config {
  uint64_t m_mask;
  bool m_external;
  bool m_fixed;
  bool m_focusable;
  object m_footer;
  string m_footer_pos;
  bool m_hide;
  std::int64_t m_height;
  bool m_mouse;
  string m_relative;
  double m_row;
  string m_style;
  bool m_noautocmd;
  bool m_vertical;
  nvpp::window m_win;
  std::int64_t m_width;
  std::int64_t m_zindex;
  string m_anchor;
  object m_border;
  details::vec<object> m_bufpos;
  double m_col;
  string m_split;
  object m_title;
  string m_title_pos;
  std::int64_t m__cmdline_offset;
  std::optional<double> col() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_col;
    }
    return {};
  }
  std::optional<double> row() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_row;
    }
    return {};
  }
  std::optional<nvpp::window> win() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_win;
    }
    return {};
  }
  std::optional<bool> hide() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_hide;
    }
    return {};
  }
  std::optional<std::int64_t> width() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_width;
    }
    return {};
  }
  std::optional<string> split() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_split;
    }
    return {};
  }
  std::optional<object> title() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_title;
    }
    return {};
  }
  std::optional<bool> mouse() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_mouse;
    }
    return {};
  }
  std::optional<bool> fixed() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_fixed;
    }
    return {};
  }
  std::optional<string> style() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_style;
    }
    return {};
  }
  std::optional<string> anchor() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_anchor;
    }
    return {};
  }
  std::optional<array_of<std::int64_t>> bufpos() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_bufpos;
    }
    return {};
  }
  std::optional<std::int64_t> height() const noexcept {
    if (m_mask & std::uint64_t{1} << 13) {
      return m_height;
    }
    return {};
  }
  std::optional<std::int64_t> zindex() const noexcept {
    if (m_mask & std::uint64_t{1} << 14) {
      return m_zindex;
    }
    return {};
  }
  std::optional<object> footer() const noexcept {
    if (m_mask & std::uint64_t{1} << 15) {
      return m_footer;
    }
    return {};
  }
  std::optional<object> border() const noexcept {
    if (m_mask & std::uint64_t{1} << 16) {
      return m_border;
    }
    return {};
  }
  std::optional<bool> external() const noexcept {
    if (m_mask & std::uint64_t{1} << 17) {
      return m_external;
    }
    return {};
  }
  std::optional<string> relative() const noexcept {
    if (m_mask & std::uint64_t{1} << 18) {
      return m_relative;
    }
    return {};
  }
  std::optional<bool> vertical() const noexcept {
    if (m_mask & std::uint64_t{1} << 19) {
      return m_vertical;
    }
    return {};
  }
  std::optional<bool> focusable() const noexcept {
    if (m_mask & std::uint64_t{1} << 20) {
      return m_focusable;
    }
    return {};
  }
  std::optional<bool> noautocmd() const noexcept {
    if (m_mask & std::uint64_t{1} << 21) {
      return m_noautocmd;
    }
    return {};
  }
  std::optional<string> title_pos() const noexcept {
    if (m_mask & std::uint64_t{1} << 22) {
      return m_title_pos;
    }
    return {};
  }
  std::optional<string> footer_pos() const noexcept {
    if (m_mask & std::uint64_t{1} << 23) {
      return m_footer_pos;
    }
    return {};
  }
  std::optional<std::int64_t> _cmdline_offset() const noexcept {
    if (m_mask & std::uint64_t{1} << 24) {
      return m__cmdline_offset;
    }
    return {};
  }
};
struct tabpage_config {
  uint64_t m_mask;
  std::int64_t m_after;
  std::optional<std::int64_t> after() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_after;
    }
    return {};
  }
};
struct runtime {
  bool is_lua;
  bool do_source;
};struct eval_statusline {
  uint64_t m_mask;
  nvpp::window m_winid;
  std::int64_t m_maxwidth;
  string m_fillchar;
  bool m_highlights;
  bool m_use_winbar;
  bool m_use_tabline;
  std::int64_t m_use_statuscol_lnum;
  std::optional<nvpp::window> winid() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_winid;
    }
    return {};
  }
  std::optional<string> fillchar() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_fillchar;
    }
    return {};
  }
  std::optional<std::int64_t> maxwidth() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_maxwidth;
    }
    return {};
  }
  std::optional<bool> highlights() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_highlights;
    }
    return {};
  }
  std::optional<bool> use_winbar() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_use_winbar;
    }
    return {};
  }
  std::optional<bool> use_tabline() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_use_tabline;
    }
    return {};
  }
  std::optional<std::int64_t> use_statuscol_lnum() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_use_statuscol_lnum;
    }
    return {};
  }
};
struct option {
  uint64_t m_mask;
  string m_scope;
  nvpp::window m_win;
  nvpp::buffer m_buf;
  string m_filetype;
  std::optional<nvpp::buffer> buf() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_buf;
    }
    return {};
  }
  std::optional<nvpp::window> win() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_win;
    }
    return {};
  }
  std::optional<string> scope() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_scope;
    }
    return {};
  }
  std::optional<string> filetype() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_filetype;
    }
    return {};
  }
};
struct highlight {
  uint64_t m_mask;
  bool m_altfont;
  bool m_blink;
  bool m_bold;
  bool m_conceal;
  bool m_dim;
  bool m_italic;
  bool m_nocombine;
  bool m_overline;
  bool m_reverse;
  bool m_standout;
  bool m_strikethrough;
  bool m_undercurl;
  bool m_underdashed;
  bool m_underdotted;
  bool m_underdouble;
  bool m_underline;
  bool m_default_;
  details::vec<std::pair<string, object>> m_cterm;
  object m_foreground;
  object m_fg;
  object m_background;
  object m_bg;
  object m_ctermfg;
  object m_ctermbg;
  object m_special;
  object m_sp;
  nvpp::hl_group_id m_link;
  nvpp::hl_group_id m_global_link;
  bool m_fallback;
  std::int64_t m_blend;
  bool m_fg_indexed;
  bool m_bg_indexed;
  bool m_force;
  bool m_update;
  string m_url;
  std::optional<object> bg() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_bg;
    }
    return {};
  }
  std::optional<object> fg() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_fg;
    }
    return {};
  }
  std::optional<object> sp() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_sp;
    }
    return {};
  }
  std::optional<bool> dim() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_dim;
    }
    return {};
  }
  std::optional<string> url() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_url;
    }
    return {};
  }
  std::optional<bool> bold() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_bold;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> link() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_link;
    }
    return {};
  }
  std::optional<std::int64_t> blend() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_blend;
    }
    return {};
  }
  std::optional<bool> force() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_force;
    }
    return {};
  }
  std::optional<bool> blink() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_blink;
    }
    return {};
  }
  std::optional<dict> cterm() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_cterm;
    }
    return {};
  }
  std::optional<bool> italic() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_italic;
    }
    return {};
  }
  std::optional<bool> update() const noexcept {
    if (m_mask & std::uint64_t{1} << 13) {
      return m_update;
    }
    return {};
  }
  std::optional<bool> reverse() const noexcept {
    if (m_mask & std::uint64_t{1} << 14) {
      return m_reverse;
    }
    return {};
  }
  std::optional<bool> default_() const noexcept {
    if (m_mask & std::uint64_t{1} << 15) {
      return m_default_;
    }
    return {};
  }
  std::optional<bool> altfont() const noexcept {
    if (m_mask & std::uint64_t{1} << 16) {
      return m_altfont;
    }
    return {};
  }
  std::optional<bool> conceal() const noexcept {
    if (m_mask & std::uint64_t{1} << 17) {
      return m_conceal;
    }
    return {};
  }
  std::optional<object> special() const noexcept {
    if (m_mask & std::uint64_t{1} << 18) {
      return m_special;
    }
    return {};
  }
  std::optional<object> ctermfg() const noexcept {
    if (m_mask & std::uint64_t{1} << 19) {
      return m_ctermfg;
    }
    return {};
  }
  std::optional<object> ctermbg() const noexcept {
    if (m_mask & std::uint64_t{1} << 20) {
      return m_ctermbg;
    }
    return {};
  }
  std::optional<bool> fallback() const noexcept {
    if (m_mask & std::uint64_t{1} << 21) {
      return m_fallback;
    }
    return {};
  }
  std::optional<bool> overline() const noexcept {
    if (m_mask & std::uint64_t{1} << 22) {
      return m_overline;
    }
    return {};
  }
  std::optional<bool> standout() const noexcept {
    if (m_mask & std::uint64_t{1} << 23) {
      return m_standout;
    }
    return {};
  }
  std::optional<bool> nocombine() const noexcept {
    if (m_mask & std::uint64_t{1} << 24) {
      return m_nocombine;
    }
    return {};
  }
  std::optional<bool> undercurl() const noexcept {
    if (m_mask & std::uint64_t{1} << 25) {
      return m_undercurl;
    }
    return {};
  }
  std::optional<bool> underline() const noexcept {
    if (m_mask & std::uint64_t{1} << 26) {
      return m_underline;
    }
    return {};
  }
  std::optional<object> background() const noexcept {
    if (m_mask & std::uint64_t{1} << 27) {
      return m_background;
    }
    return {};
  }
  std::optional<bool> bg_indexed() const noexcept {
    if (m_mask & std::uint64_t{1} << 28) {
      return m_bg_indexed;
    }
    return {};
  }
  std::optional<object> foreground() const noexcept {
    if (m_mask & std::uint64_t{1} << 29) {
      return m_foreground;
    }
    return {};
  }
  std::optional<bool> fg_indexed() const noexcept {
    if (m_mask & std::uint64_t{1} << 30) {
      return m_fg_indexed;
    }
    return {};
  }
  std::optional<nvpp::hl_group_id> global_link() const noexcept {
    if (m_mask & std::uint64_t{1} << 31) {
      return m_global_link;
    }
    return {};
  }
  std::optional<bool> underdashed() const noexcept {
    if (m_mask & std::uint64_t{1} << 32) {
      return m_underdashed;
    }
    return {};
  }
  std::optional<bool> underdotted() const noexcept {
    if (m_mask & std::uint64_t{1} << 33) {
      return m_underdotted;
    }
    return {};
  }
  std::optional<bool> underdouble() const noexcept {
    if (m_mask & std::uint64_t{1} << 34) {
      return m_underdouble;
    }
    return {};
  }
  std::optional<bool> strikethrough() const noexcept {
    if (m_mask & std::uint64_t{1} << 35) {
      return m_strikethrough;
    }
    return {};
  }
};
struct highlight_cterm {
  bool bold;
  bool standout;
  bool strikethrough;
  bool underline;
  bool undercurl;
  bool underdouble;
  bool underdotted;
  bool underdashed;
  bool italic;
  bool reverse;
  bool altfont;
  bool dim;
  bool blink;
  bool conceal;
  bool overline;
  bool nocombine;
};struct get_highlight {
  uint64_t m_mask;
  std::int64_t m_id;
  string m_name;
  bool m_link;
  bool m_create;
  std::optional<std::int64_t> id() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_id;
    }
    return {};
  }
  std::optional<bool> link() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_link;
    }
    return {};
  }
  std::optional<string> name() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_name;
    }
    return {};
  }
  std::optional<bool> create() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_create;
    }
    return {};
  }
};
struct get_ns {
  uint64_t m_mask;
  nvpp::window m_winid;
  std::optional<nvpp::window> winid() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_winid;
    }
    return {};
  }
};
struct win_text_height {
  uint64_t m_mask;
  std::int64_t m_start_row;
  std::int64_t m_end_row;
  std::int64_t m_start_vcol;
  std::int64_t m_end_vcol;
  std::int64_t m_max_height;
  std::optional<std::int64_t> end_row() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_end_row;
    }
    return {};
  }
  std::optional<std::int64_t> end_vcol() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_end_vcol;
    }
    return {};
  }
  std::optional<std::int64_t> start_row() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_start_row;
    }
    return {};
  }
  std::optional<std::int64_t> max_height() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_max_height;
    }
    return {};
  }
  std::optional<std::int64_t> start_vcol() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_start_vcol;
    }
    return {};
  }
};
struct clear_autocmds {
  uint64_t m_mask;
  nvpp::buffer m_buffer;
  object m_event;
  object m_group;
  object m_pattern;
  std::optional<object> event() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_event;
    }
    return {};
  }
  std::optional<object> group() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_group;
    }
    return {};
  }
  std::optional<nvpp::buffer> buffer() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_buffer;
    }
    return {};
  }
  std::optional<object> pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_pattern;
    }
    return {};
  }
};
struct create_autocmd {
  uint64_t m_mask;
  nvpp::buffer m_buffer;
  object m_callback;
  string m_command;
  string m_desc;
  object m_group;
  bool m_nested;
  bool m_once;
  object m_pattern;
  std::optional<string> desc() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_desc;
    }
    return {};
  }
  std::optional<bool> once() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_once;
    }
    return {};
  }
  std::optional<object> group() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_group;
    }
    return {};
  }
  std::optional<nvpp::buffer> buffer() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_buffer;
    }
    return {};
  }
  std::optional<bool> nested() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_nested;
    }
    return {};
  }
  std::optional<string> command() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_command;
    }
    return {};
  }
  std::optional<object> pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_pattern;
    }
    return {};
  }
  std::optional<object> callback() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_callback;
    }
    return {};
  }
};
struct exec_autocmds {
  uint64_t m_mask;
  nvpp::buffer m_buffer;
  object m_group;
  bool m_modeline;
  object m_pattern;
  object m_data;
  std::optional<object> data() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_data;
    }
    return {};
  }
  std::optional<object> group() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_group;
    }
    return {};
  }
  std::optional<nvpp::buffer> buffer() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_buffer;
    }
    return {};
  }
  std::optional<object> pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_pattern;
    }
    return {};
  }
  std::optional<bool> modeline() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_modeline;
    }
    return {};
  }
};
struct get_autocmds {
  uint64_t m_mask;
  object m_event;
  object m_group;
  object m_pattern;
  object m_buffer;
  std::int64_t m_id;
  std::optional<std::int64_t> id() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_id;
    }
    return {};
  }
  std::optional<object> event() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_event;
    }
    return {};
  }
  std::optional<object> group() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_group;
    }
    return {};
  }
  std::optional<object> buffer() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_buffer;
    }
    return {};
  }
  std::optional<object> pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_pattern;
    }
    return {};
  }
};
struct create_augroup {
  uint64_t m_mask;
  bool m_clear;
  std::optional<bool> clear() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_clear;
    }
    return {};
  }
};
struct cmd {
  uint64_t m_mask;
  string m_cmd;
  details::vec<object> m_range;
  std::int64_t m_count;
  string m_reg;
  bool m_bang;
  details::vec<object> m_args;
  details::vec<std::pair<string, object>> m_magic;
  details::vec<std::pair<string, object>> m_mods;
  object m_nargs;
  string m_addr;
  string m_nextcmd;
  std::optional<string> cmd_() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_cmd;
    }
    return {};
  }
  std::optional<string> reg() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_reg;
    }
    return {};
  }
  std::optional<bool> bang() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_bang;
    }
    return {};
  }
  std::optional<string> addr() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_addr;
    }
    return {};
  }
  std::optional<dict> mods() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_mods;
    }
    return {};
  }
  std::optional<array_of<string>> args() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_args;
    }
    return {};
  }
  std::optional<std::int64_t> count() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_count;
    }
    return {};
  }
  std::optional<dict> magic() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_magic;
    }
    return {};
  }
  std::optional<object> nargs() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_nargs;
    }
    return {};
  }
  std::optional<array_of<std::int64_t>> range() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_range;
    }
    return {};
  }
  std::optional<string> nextcmd() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_nextcmd;
    }
    return {};
  }
};
struct cmd_magic {
  uint64_t m_mask;
  bool m_file;
  bool m_bar;
  std::optional<bool> bar() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_bar;
    }
    return {};
  }
  std::optional<bool> file() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_file;
    }
    return {};
  }
};
struct cmd_mods {
  uint64_t m_mask;
  bool m_silent;
  bool m_emsg_silent;
  bool m_unsilent;
  details::vec<std::pair<string, object>> m_filter;
  bool m_sandbox;
  bool m_noautocmd;
  bool m_browse;
  bool m_confirm;
  bool m_hide;
  bool m_horizontal;
  bool m_keepalt;
  bool m_keepjumps;
  bool m_keepmarks;
  bool m_keeppatterns;
  bool m_lockmarks;
  bool m_noswapfile;
  std::int64_t m_tab;
  std::int64_t m_verbose;
  bool m_vertical;
  string m_split;
  std::optional<std::int64_t> tab() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_tab;
    }
    return {};
  }
  std::optional<bool> hide() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_hide;
    }
    return {};
  }
  std::optional<string> split() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_split;
    }
    return {};
  }
  std::optional<bool> browse() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_browse;
    }
    return {};
  }
  std::optional<dict> filter() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_filter;
    }
    return {};
  }
  std::optional<bool> silent() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_silent;
    }
    return {};
  }
  std::optional<bool> confirm() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_confirm;
    }
    return {};
  }
  std::optional<bool> keepalt() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_keepalt;
    }
    return {};
  }
  std::optional<bool> sandbox() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_sandbox;
    }
    return {};
  }
  std::optional<std::int64_t> verbose() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_verbose;
    }
    return {};
  }
  std::optional<bool> unsilent() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_unsilent;
    }
    return {};
  }
  std::optional<bool> vertical() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_vertical;
    }
    return {};
  }
  std::optional<bool> keepjumps() const noexcept {
    if (m_mask & std::uint64_t{1} << 13) {
      return m_keepjumps;
    }
    return {};
  }
  std::optional<bool> keepmarks() const noexcept {
    if (m_mask & std::uint64_t{1} << 14) {
      return m_keepmarks;
    }
    return {};
  }
  std::optional<bool> lockmarks() const noexcept {
    if (m_mask & std::uint64_t{1} << 15) {
      return m_lockmarks;
    }
    return {};
  }
  std::optional<bool> noautocmd() const noexcept {
    if (m_mask & std::uint64_t{1} << 16) {
      return m_noautocmd;
    }
    return {};
  }
  std::optional<bool> horizontal() const noexcept {
    if (m_mask & std::uint64_t{1} << 17) {
      return m_horizontal;
    }
    return {};
  }
  std::optional<bool> noswapfile() const noexcept {
    if (m_mask & std::uint64_t{1} << 18) {
      return m_noswapfile;
    }
    return {};
  }
  std::optional<bool> emsg_silent() const noexcept {
    if (m_mask & std::uint64_t{1} << 19) {
      return m_emsg_silent;
    }
    return {};
  }
  std::optional<bool> keeppatterns() const noexcept {
    if (m_mask & std::uint64_t{1} << 20) {
      return m_keeppatterns;
    }
    return {};
  }
};
struct cmd_mods_filter {
  uint64_t m_mask;
  string m_pattern;
  bool m_force;
  std::optional<bool> force() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_force;
    }
    return {};
  }
  std::optional<string> pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_pattern;
    }
    return {};
  }
};
struct cmd_opts {
  bool output;
};struct echo_opts {
  uint64_t m_mask;
  bool m_err;
  bool m_verbose;
  string m_kind;
  object m_id;
  string m_title;
  string m_status;
  std::int64_t m_percent;
  string m_source;
  details::vec<std::pair<string, object>> m_data;
  std::optional<object> id() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_id;
    }
    return {};
  }
  std::optional<bool> err() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_err;
    }
    return {};
  }
  std::optional<dict_of<object>> data() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_data;
    }
    return {};
  }
  std::optional<string> kind() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_kind;
    }
    return {};
  }
  std::optional<string> title() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_title;
    }
    return {};
  }
  std::optional<string> source() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_source;
    }
    return {};
  }
  std::optional<string> status() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_status;
    }
    return {};
  }
  std::optional<std::int64_t> percent() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_percent;
    }
    return {};
  }
  std::optional<bool> verbose() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_verbose;
    }
    return {};
  }
};
struct exec_opts {
  bool output;
};struct buf_attach {
  uint64_t m_mask;
  lua_ref m_on_lines;
  lua_ref m_on_bytes;
  lua_ref m_on_changedtick;
  lua_ref m_on_detach;
  lua_ref m_on_reload;
  bool m_utf_sizes;
  bool m_preview;
  std::optional<bool> preview() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_preview;
    }
    return {};
  }
  std::optional<lua_ref> on_bytes() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_on_bytes;
    }
    return {};
  }
  std::optional<lua_ref> on_lines() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_on_lines;
    }
    return {};
  }
  std::optional<bool> utf_sizes() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_utf_sizes;
    }
    return {};
  }
  std::optional<lua_ref> on_detach() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_on_detach;
    }
    return {};
  }
  std::optional<lua_ref> on_reload() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_on_reload;
    }
    return {};
  }
  std::optional<lua_ref> on_changedtick() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_on_changedtick;
    }
    return {};
  }
};
struct buf_delete {
  uint64_t m_mask;
  bool m_force;
  bool m_unload;
  std::optional<bool> force() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_force;
    }
    return {};
  }
  std::optional<bool> unload() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_unload;
    }
    return {};
  }
};
struct open_term {
  uint64_t m_mask;
  lua_ref m_on_input;
  bool m_force_crlf;
  std::optional<lua_ref> on_input() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_on_input;
    }
    return {};
  }
  std::optional<bool> force_crlf() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_force_crlf;
    }
    return {};
  }
};
struct complete_set {
  uint64_t m_mask;
  string m_info;
  std::optional<string> info() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_info;
    }
    return {};
  }
};
struct xdl_diff {
  uint64_t m_mask;
  lua_ref m_on_hunk;
  string m_result_type;
  string m_algorithm;
  std::int64_t m_ctxlen;
  std::int64_t m_interhunkctxlen;
  object m_linematch;
  bool m_ignore_whitespace;
  bool m_ignore_whitespace_change;
  bool m_ignore_whitespace_change_at_eol;
  bool m_ignore_cr_at_eol;
  bool m_ignore_blank_lines;
  bool m_indent_heuristic;
  std::optional<std::int64_t> ctxlen() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_ctxlen;
    }
    return {};
  }
  std::optional<lua_ref> on_hunk() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_on_hunk;
    }
    return {};
  }
  std::optional<string> algorithm() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_algorithm;
    }
    return {};
  }
  std::optional<object> linematch() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_linematch;
    }
    return {};
  }
  std::optional<string> result_type() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_result_type;
    }
    return {};
  }
  std::optional<std::int64_t> interhunkctxlen() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_interhunkctxlen;
    }
    return {};
  }
  std::optional<bool> ignore_cr_at_eol() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_ignore_cr_at_eol;
    }
    return {};
  }
  std::optional<bool> indent_heuristic() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_indent_heuristic;
    }
    return {};
  }
  std::optional<bool> ignore_whitespace() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_ignore_whitespace;
    }
    return {};
  }
  std::optional<bool> ignore_blank_lines() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_ignore_blank_lines;
    }
    return {};
  }
  std::optional<bool> ignore_whitespace_change() const noexcept {
    if (m_mask & std::uint64_t{1} << 11) {
      return m_ignore_whitespace_change;
    }
    return {};
  }
  std::optional<bool> ignore_whitespace_change_at_eol() const noexcept {
    if (m_mask & std::uint64_t{1} << 12) {
      return m_ignore_whitespace_change_at_eol;
    }
    return {};
  }
};
struct redraw {
  uint64_t m_mask;
  bool m_flush;
  bool m_cursor;
  bool m_valid;
  bool m_statuscolumn;
  bool m_statusline;
  bool m_tabline;
  bool m_winbar;
  details::vec<object> m_range;
  nvpp::window m_win;
  nvpp::buffer m_buf;
  std::optional<nvpp::buffer> buf() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_buf;
    }
    return {};
  }
  std::optional<nvpp::window> win() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_win;
    }
    return {};
  }
  std::optional<bool> flush() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_flush;
    }
    return {};
  }
  std::optional<array> range() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_range;
    }
    return {};
  }
  std::optional<bool> valid() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_valid;
    }
    return {};
  }
  std::optional<bool> cursor() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_cursor;
    }
    return {};
  }
  std::optional<bool> winbar() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_winbar;
    }
    return {};
  }
  std::optional<bool> tabline() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_tabline;
    }
    return {};
  }
  std::optional<bool> statusline() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_statusline;
    }
    return {};
  }
  std::optional<bool> statuscolumn() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_statuscolumn;
    }
    return {};
  }
};
struct ns_opts {
  uint64_t m_mask;
  details::vec<object> m_wins;
  std::optional<array> wins() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_wins;
    }
    return {};
  }
};
struct _shada_search_pat {
  uint64_t m_mask;
  bool m_magic;
  bool m_smartcase;
  bool m_has_line_offset;
  bool m_place_cursor_at_end;
  bool m_is_last_used;
  bool m_is_substitute_pattern;
  bool m_highlighted;
  bool m_search_backward;
  std::int64_t m_offset;
  string m_pat;
  std::optional<bool> search_backward() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_search_backward;
    }
    return {};
  }
  std::optional<bool> smartcase() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_smartcase;
    }
    return {};
  }
  std::optional<bool> place_cursor_at_end() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_place_cursor_at_end;
    }
    return {};
  }
  std::optional<bool> highlighted() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_highlighted;
    }
    return {};
  }
  std::optional<bool> has_line_offset() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_has_line_offset;
    }
    return {};
  }
  std::optional<bool> magic() const noexcept {
    if (m_mask & std::uint64_t{1} << 6) {
      return m_magic;
    }
    return {};
  }
  std::optional<std::int64_t> offset() const noexcept {
    if (m_mask & std::uint64_t{1} << 7) {
      return m_offset;
    }
    return {};
  }
  std::optional<string> pat() const noexcept {
    if (m_mask & std::uint64_t{1} << 8) {
      return m_pat;
    }
    return {};
  }
  std::optional<bool> is_substitute_pattern() const noexcept {
    if (m_mask & std::uint64_t{1} << 9) {
      return m_is_substitute_pattern;
    }
    return {};
  }
  std::optional<bool> is_last_used() const noexcept {
    if (m_mask & std::uint64_t{1} << 10) {
      return m_is_last_used;
    }
    return {};
  }
};
struct _shada_mark {
  uint64_t m_mask;
  std::int64_t m_n;
  std::int64_t m_l;
  std::int64_t m_c;
  string m_f;
  std::optional<std::int64_t> c() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_c;
    }
    return {};
  }
  std::optional<string> f() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_f;
    }
    return {};
  }
  std::optional<std::int64_t> l() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_l;
    }
    return {};
  }
  std::optional<std::int64_t> n() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_n;
    }
    return {};
  }
};
struct _shada_register {
  uint64_t m_mask;
  details::vec<string> m_rc;
  bool m_ru;
  std::int64_t m_rt;
  std::int64_t m_n;
  std::int64_t m_rw;
  std::optional<std::int64_t> n() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_n;
    }
    return {};
  }
  std::optional<string_array> rc() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_rc;
    }
    return {};
  }
  std::optional<std::int64_t> rt() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_rt;
    }
    return {};
  }
  std::optional<bool> ru() const noexcept {
    if (m_mask & std::uint64_t{1} << 4) {
      return m_ru;
    }
    return {};
  }
  std::optional<std::int64_t> rw() const noexcept {
    if (m_mask & std::uint64_t{1} << 5) {
      return m_rw;
    }
    return {};
  }
};
struct _shada_buflist_item {
  uint64_t m_mask;
  std::int64_t m_l;
  std::int64_t m_c;
  string m_f;
  std::optional<std::int64_t> c() const noexcept {
    if (m_mask & std::uint64_t{1} << 1) {
      return m_c;
    }
    return {};
  }
  std::optional<string> f() const noexcept {
    if (m_mask & std::uint64_t{1} << 2) {
      return m_f;
    }
    return {};
  }
  std::optional<std::int64_t> l() const noexcept {
    if (m_mask & std::uint64_t{1} << 3) {
      return m_l;
    }
    return {};
  }
};
}
}

namespace nvpp::keysets::builder {
struct empty {

  constexpr operator keysets::empty() const noexcept {
    keysets::empty ret{};
    return ret;
  }
};
struct context {
  std::optional<array_of<string>> types;

  constexpr operator keysets::context() const noexcept {
    keysets::context ret{};
    if (types.has_value()) {
      ret.m_types = *types;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct set_decoration_provider {
  std::optional<lua_ref> on_start;
  std::optional<lua_ref> on_buf;
  std::optional<lua_ref> on_win;
  std::optional<lua_ref> on_line;
  std::optional<lua_ref> on_range;
  std::optional<lua_ref> on_end;
  std::optional<lua_ref> _on_hl_def;
  std::optional<lua_ref> _on_spell_nav;
  std::optional<lua_ref> _on_conceal_line;

  constexpr operator keysets::set_decoration_provider() const noexcept {
    keysets::set_decoration_provider ret{};
    if (on_buf.has_value()) {
      ret.m_on_buf = *on_buf;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (on_end.has_value()) {
      ret.m_on_end = *on_end;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (on_win.has_value()) {
      ret.m_on_win = *on_win;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (on_line.has_value()) {
      ret.m_on_line = *on_line;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (on_range.has_value()) {
      ret.m_on_range = *on_range;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (on_start.has_value()) {
      ret.m_on_start = *on_start;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (_on_hl_def.has_value()) {
      ret.m__on_hl_def = *_on_hl_def;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (_on_spell_nav.has_value()) {
      ret.m__on_spell_nav = *_on_spell_nav;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (_on_conceal_line.has_value()) {
      ret.m__on_conceal_line = *_on_conceal_line;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    return ret;
  }
};
struct set_extmark {
  std::optional<std::int64_t> id;
  std::optional<std::int64_t> end_line;
  std::optional<std::int64_t> end_row;
  std::optional<std::int64_t> end_col;
  std::optional<object> hl_group;
  std::optional<array> virt_text;
  std::optional<string> virt_text_pos;
  std::optional<std::int64_t> virt_text_win_col;
  std::optional<bool> virt_text_hide;
  std::optional<bool> virt_text_repeat_linebreak;
  std::optional<bool> hl_eol;
  std::optional<string> hl_mode;
  std::optional<bool> invalidate;
  std::optional<bool> ephemeral;
  std::optional<std::int64_t> priority;
  std::optional<bool> right_gravity;
  std::optional<bool> end_right_gravity;
  std::optional<array> virt_lines;
  std::optional<bool> virt_lines_above;
  std::optional<bool> virt_lines_leftcol;
  std::optional<string> virt_lines_overflow;
  std::optional<bool> strict;
  std::optional<string> sign_text;
  std::optional<nvpp::hl_group_id> sign_hl_group;
  std::optional<nvpp::hl_group_id> number_hl_group;
  std::optional<nvpp::hl_group_id> line_hl_group;
  std::optional<nvpp::hl_group_id> cursorline_hl_group;
  std::optional<string> conceal;
  std::optional<string> conceal_lines;
  std::optional<bool> spell;
  std::optional<bool> ui_watched;
  std::optional<bool> undo_restore;
  std::optional<string> url;
  std::optional<bool> scoped;
  std::optional<std::int64_t> _subpriority;

  constexpr operator keysets::set_extmark() const noexcept {
    keysets::set_extmark ret{};
    if (id.has_value()) {
      ret.m_id = *id;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (url.has_value()) {
      ret.m_url = *url;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (spell.has_value()) {
      ret.m_spell = *spell;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (scoped.has_value()) {
      ret.m_scoped = *scoped;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (hl_eol.has_value()) {
      ret.m_hl_eol = *hl_eol;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (strict.has_value()) {
      ret.m_strict = *strict;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (end_col.has_value()) {
      ret.m_end_col = *end_col;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (conceal.has_value()) {
      ret.m_conceal = *conceal;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (hl_mode.has_value()) {
      ret.m_hl_mode = *hl_mode;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (end_row.has_value()) {
      ret.m_end_row = *end_row;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (end_line.has_value()) {
      ret.m_end_line = *end_line;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (hl_group.has_value()) {
      ret.m_hl_group = *hl_group;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    if (priority.has_value()) {
      ret.m_priority = *priority;
      ret.m_mask |= std::uint64_t{1} << 13;
    }
    if (ephemeral.has_value()) {
      ret.m_ephemeral = *ephemeral;
      ret.m_mask |= std::uint64_t{1} << 14;
    }
    if (sign_text.has_value()) {
      ret.m_sign_text = *sign_text;
      ret.m_mask |= std::uint64_t{1} << 15;
    }
    if (virt_text.has_value()) {
      ret.m_virt_text = *virt_text;
      ret.m_mask |= std::uint64_t{1} << 16;
    }
    if (invalidate.has_value()) {
      ret.m_invalidate = *invalidate;
      ret.m_mask |= std::uint64_t{1} << 17;
    }
    if (ui_watched.has_value()) {
      ret.m_ui_watched = *ui_watched;
      ret.m_mask |= std::uint64_t{1} << 18;
    }
    if (virt_lines.has_value()) {
      ret.m_virt_lines = *virt_lines;
      ret.m_mask |= std::uint64_t{1} << 19;
    }
    if (_subpriority.has_value()) {
      ret.m__subpriority = *_subpriority;
      ret.m_mask |= std::uint64_t{1} << 20;
    }
    if (undo_restore.has_value()) {
      ret.m_undo_restore = *undo_restore;
      ret.m_mask |= std::uint64_t{1} << 21;
    }
    if (conceal_lines.has_value()) {
      ret.m_conceal_lines = *conceal_lines;
      ret.m_mask |= std::uint64_t{1} << 22;
    }
    if (line_hl_group.has_value()) {
      ret.m_line_hl_group = *line_hl_group;
      ret.m_mask |= std::uint64_t{1} << 23;
    }
    if (right_gravity.has_value()) {
      ret.m_right_gravity = *right_gravity;
      ret.m_mask |= std::uint64_t{1} << 24;
    }
    if (sign_hl_group.has_value()) {
      ret.m_sign_hl_group = *sign_hl_group;
      ret.m_mask |= std::uint64_t{1} << 25;
    }
    if (virt_text_pos.has_value()) {
      ret.m_virt_text_pos = *virt_text_pos;
      ret.m_mask |= std::uint64_t{1} << 26;
    }
    if (virt_text_hide.has_value()) {
      ret.m_virt_text_hide = *virt_text_hide;
      ret.m_mask |= std::uint64_t{1} << 27;
    }
    if (number_hl_group.has_value()) {
      ret.m_number_hl_group = *number_hl_group;
      ret.m_mask |= std::uint64_t{1} << 28;
    }
    if (virt_lines_above.has_value()) {
      ret.m_virt_lines_above = *virt_lines_above;
      ret.m_mask |= std::uint64_t{1} << 29;
    }
    if (end_right_gravity.has_value()) {
      ret.m_end_right_gravity = *end_right_gravity;
      ret.m_mask |= std::uint64_t{1} << 30;
    }
    if (virt_text_win_col.has_value()) {
      ret.m_virt_text_win_col = *virt_text_win_col;
      ret.m_mask |= std::uint64_t{1} << 31;
    }
    if (virt_lines_leftcol.has_value()) {
      ret.m_virt_lines_leftcol = *virt_lines_leftcol;
      ret.m_mask |= std::uint64_t{1} << 32;
    }
    if (cursorline_hl_group.has_value()) {
      ret.m_cursorline_hl_group = *cursorline_hl_group;
      ret.m_mask |= std::uint64_t{1} << 33;
    }
    if (virt_lines_overflow.has_value()) {
      ret.m_virt_lines_overflow = *virt_lines_overflow;
      ret.m_mask |= std::uint64_t{1} << 34;
    }
    if (virt_text_repeat_linebreak.has_value()) {
      ret.m_virt_text_repeat_linebreak = *virt_text_repeat_linebreak;
      ret.m_mask |= std::uint64_t{1} << 35;
    }
    return ret;
  }
};
struct get_extmark {
  std::optional<bool> details;
  std::optional<bool> hl_name;

  constexpr operator keysets::get_extmark() const noexcept {
    keysets::get_extmark ret{};
    if (details.has_value()) {
      ret.m_details = *details;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (hl_name.has_value()) {
      ret.m_hl_name = *hl_name;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    return ret;
  }
};
struct get_extmarks {
  std::optional<std::int64_t> limit;
  std::optional<bool> details;
  std::optional<bool> hl_name;
  std::optional<bool> overlap;
  std::optional<string> type;

  constexpr operator keysets::get_extmarks() const noexcept {
    keysets::get_extmarks ret{};
    if (type.has_value()) {
      ret.m_type = *type;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (limit.has_value()) {
      ret.m_limit = *limit;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (details.has_value()) {
      ret.m_details = *details;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (hl_name.has_value()) {
      ret.m_hl_name = *hl_name;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (overlap.has_value()) {
      ret.m_overlap = *overlap;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    return ret;
  }
};
struct keymap {
  std::optional<bool> noremap;
  std::optional<bool> nowait;
  std::optional<bool> silent;
  std::optional<bool> script;
  std::optional<bool> expr;
  std::optional<bool> unique;
  std::optional<nvpp::lua_ref> callback;
  std::optional<string> desc;
  std::optional<bool> replace_keycodes;

  constexpr operator keysets::keymap() const noexcept {
    keysets::keymap ret{};
    if (desc.has_value()) {
      ret.m_desc = *desc;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (expr.has_value()) {
      ret.m_expr = *expr;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (script.has_value()) {
      ret.m_script = *script;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (silent.has_value()) {
      ret.m_silent = *silent;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (unique.has_value()) {
      ret.m_unique = *unique;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (nowait.has_value()) {
      ret.m_nowait = *nowait;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (noremap.has_value()) {
      ret.m_noremap = *noremap;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (callback.has_value()) {
      ret.m_callback = *callback;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (replace_keycodes.has_value()) {
      ret.m_replace_keycodes = *replace_keycodes;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    return ret;
  }
};
struct get_commands {
  bool builtin;
  constexpr operator keysets::get_commands() const noexcept {
    return {
      .builtin = builtin,
    };
  }
};
struct user_command {
  std::optional<object> addr;
  std::optional<bool> bang;
  std::optional<bool> bar;
  std::optional<object> complete;
  std::optional<object> count;
  std::optional<object> desc;
  std::optional<bool> force;
  std::optional<bool> keepscript;
  std::optional<object> nargs;
  std::optional<object> preview;
  std::optional<object> range;
  std::optional<bool> register_;

  constexpr operator keysets::user_command() const noexcept {
    keysets::user_command ret{};
    if (bar.has_value()) {
      ret.m_bar = *bar;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (addr.has_value()) {
      ret.m_addr = *addr;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (bang.has_value()) {
      ret.m_bang = *bang;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (desc.has_value()) {
      ret.m_desc = *desc;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (count.has_value()) {
      ret.m_count = *count;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (force.has_value()) {
      ret.m_force = *force;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (nargs.has_value()) {
      ret.m_nargs = *nargs;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (range.has_value()) {
      ret.m_range = *range;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (preview.has_value()) {
      ret.m_preview = *preview;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (complete.has_value()) {
      ret.m_complete = *complete;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (register_.has_value()) {
      ret.m_register_ = *register_;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (keepscript.has_value()) {
      ret.m_keepscript = *keepscript;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    return ret;
  }
};
struct win_config {
  std::optional<bool> external;
  std::optional<bool> fixed;
  std::optional<bool> focusable;
  std::optional<object> footer;
  std::optional<string> footer_pos;
  std::optional<bool> hide;
  std::optional<std::int64_t> height;
  std::optional<bool> mouse;
  std::optional<string> relative;
  std::optional<double> row;
  std::optional<string> style;
  std::optional<bool> noautocmd;
  std::optional<bool> vertical;
  std::optional<nvpp::window> win;
  std::optional<std::int64_t> width;
  std::optional<std::int64_t> zindex;
  std::optional<string> anchor;
  std::optional<object> border;
  std::optional<array_of<std::int64_t>> bufpos;
  std::optional<double> col;
  std::optional<string> split;
  std::optional<object> title;
  std::optional<string> title_pos;
  std::optional<std::int64_t> _cmdline_offset;

  constexpr operator keysets::win_config() const noexcept {
    keysets::win_config ret{};
    if (col.has_value()) {
      ret.m_col = *col;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (row.has_value()) {
      ret.m_row = *row;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (win.has_value()) {
      ret.m_win = *win;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (hide.has_value()) {
      ret.m_hide = *hide;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (width.has_value()) {
      ret.m_width = *width;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (split.has_value()) {
      ret.m_split = *split;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (title.has_value()) {
      ret.m_title = *title;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (mouse.has_value()) {
      ret.m_mouse = *mouse;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (fixed.has_value()) {
      ret.m_fixed = *fixed;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (style.has_value()) {
      ret.m_style = *style;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (anchor.has_value()) {
      ret.m_anchor = *anchor;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (bufpos.has_value()) {
      ret.m_bufpos = *bufpos;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    if (height.has_value()) {
      ret.m_height = *height;
      ret.m_mask |= std::uint64_t{1} << 13;
    }
    if (zindex.has_value()) {
      ret.m_zindex = *zindex;
      ret.m_mask |= std::uint64_t{1} << 14;
    }
    if (footer.has_value()) {
      ret.m_footer = *footer;
      ret.m_mask |= std::uint64_t{1} << 15;
    }
    if (border.has_value()) {
      ret.m_border = *border;
      ret.m_mask |= std::uint64_t{1} << 16;
    }
    if (external.has_value()) {
      ret.m_external = *external;
      ret.m_mask |= std::uint64_t{1} << 17;
    }
    if (relative.has_value()) {
      ret.m_relative = *relative;
      ret.m_mask |= std::uint64_t{1} << 18;
    }
    if (vertical.has_value()) {
      ret.m_vertical = *vertical;
      ret.m_mask |= std::uint64_t{1} << 19;
    }
    if (focusable.has_value()) {
      ret.m_focusable = *focusable;
      ret.m_mask |= std::uint64_t{1} << 20;
    }
    if (noautocmd.has_value()) {
      ret.m_noautocmd = *noautocmd;
      ret.m_mask |= std::uint64_t{1} << 21;
    }
    if (title_pos.has_value()) {
      ret.m_title_pos = *title_pos;
      ret.m_mask |= std::uint64_t{1} << 22;
    }
    if (footer_pos.has_value()) {
      ret.m_footer_pos = *footer_pos;
      ret.m_mask |= std::uint64_t{1} << 23;
    }
    if (_cmdline_offset.has_value()) {
      ret.m__cmdline_offset = *_cmdline_offset;
      ret.m_mask |= std::uint64_t{1} << 24;
    }
    return ret;
  }
};
struct tabpage_config {
  std::optional<std::int64_t> after;

  constexpr operator keysets::tabpage_config() const noexcept {
    keysets::tabpage_config ret{};
    if (after.has_value()) {
      ret.m_after = *after;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct runtime {
  bool is_lua;
  bool do_source;
  constexpr operator keysets::runtime() const noexcept {
    return {
      .is_lua = is_lua,.do_source = do_source,
    };
  }
};
struct eval_statusline {
  std::optional<nvpp::window> winid;
  std::optional<std::int64_t> maxwidth;
  std::optional<string> fillchar;
  std::optional<bool> highlights;
  std::optional<bool> use_winbar;
  std::optional<bool> use_tabline;
  std::optional<std::int64_t> use_statuscol_lnum;

  constexpr operator keysets::eval_statusline() const noexcept {
    keysets::eval_statusline ret{};
    if (winid.has_value()) {
      ret.m_winid = *winid;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (fillchar.has_value()) {
      ret.m_fillchar = *fillchar;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (maxwidth.has_value()) {
      ret.m_maxwidth = *maxwidth;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (highlights.has_value()) {
      ret.m_highlights = *highlights;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (use_winbar.has_value()) {
      ret.m_use_winbar = *use_winbar;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (use_tabline.has_value()) {
      ret.m_use_tabline = *use_tabline;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (use_statuscol_lnum.has_value()) {
      ret.m_use_statuscol_lnum = *use_statuscol_lnum;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    return ret;
  }
};
struct option {
  std::optional<string> scope;
  std::optional<nvpp::window> win;
  std::optional<nvpp::buffer> buf;
  std::optional<string> filetype;

  constexpr operator keysets::option() const noexcept {
    keysets::option ret{};
    if (buf.has_value()) {
      ret.m_buf = *buf;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (win.has_value()) {
      ret.m_win = *win;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (scope.has_value()) {
      ret.m_scope = *scope;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (filetype.has_value()) {
      ret.m_filetype = *filetype;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    return ret;
  }
};
struct highlight {
  std::optional<bool> altfont;
  std::optional<bool> blink;
  std::optional<bool> bold;
  std::optional<bool> conceal;
  std::optional<bool> dim;
  std::optional<bool> italic;
  std::optional<bool> nocombine;
  std::optional<bool> overline;
  std::optional<bool> reverse;
  std::optional<bool> standout;
  std::optional<bool> strikethrough;
  std::optional<bool> undercurl;
  std::optional<bool> underdashed;
  std::optional<bool> underdotted;
  std::optional<bool> underdouble;
  std::optional<bool> underline;
  std::optional<bool> default_;
  std::optional<dict> cterm;
  std::optional<object> foreground;
  std::optional<object> fg;
  std::optional<object> background;
  std::optional<object> bg;
  std::optional<object> ctermfg;
  std::optional<object> ctermbg;
  std::optional<object> special;
  std::optional<object> sp;
  std::optional<nvpp::hl_group_id> link;
  std::optional<nvpp::hl_group_id> global_link;
  std::optional<bool> fallback;
  std::optional<std::int64_t> blend;
  std::optional<bool> fg_indexed;
  std::optional<bool> bg_indexed;
  std::optional<bool> force;
  std::optional<bool> update;
  std::optional<string> url;

  constexpr operator keysets::highlight() const noexcept {
    keysets::highlight ret{};
    if (bg.has_value()) {
      ret.m_bg = *bg;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (fg.has_value()) {
      ret.m_fg = *fg;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (sp.has_value()) {
      ret.m_sp = *sp;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (dim.has_value()) {
      ret.m_dim = *dim;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (url.has_value()) {
      ret.m_url = *url;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (bold.has_value()) {
      ret.m_bold = *bold;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (link.has_value()) {
      ret.m_link = *link;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (blend.has_value()) {
      ret.m_blend = *blend;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (force.has_value()) {
      ret.m_force = *force;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (blink.has_value()) {
      ret.m_blink = *blink;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (cterm.has_value()) {
      ret.m_cterm = *cterm;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (italic.has_value()) {
      ret.m_italic = *italic;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    if (update.has_value()) {
      ret.m_update = *update;
      ret.m_mask |= std::uint64_t{1} << 13;
    }
    if (reverse.has_value()) {
      ret.m_reverse = *reverse;
      ret.m_mask |= std::uint64_t{1} << 14;
    }
    if (default_.has_value()) {
      ret.m_default_ = *default_;
      ret.m_mask |= std::uint64_t{1} << 15;
    }
    if (altfont.has_value()) {
      ret.m_altfont = *altfont;
      ret.m_mask |= std::uint64_t{1} << 16;
    }
    if (conceal.has_value()) {
      ret.m_conceal = *conceal;
      ret.m_mask |= std::uint64_t{1} << 17;
    }
    if (special.has_value()) {
      ret.m_special = *special;
      ret.m_mask |= std::uint64_t{1} << 18;
    }
    if (ctermfg.has_value()) {
      ret.m_ctermfg = *ctermfg;
      ret.m_mask |= std::uint64_t{1} << 19;
    }
    if (ctermbg.has_value()) {
      ret.m_ctermbg = *ctermbg;
      ret.m_mask |= std::uint64_t{1} << 20;
    }
    if (fallback.has_value()) {
      ret.m_fallback = *fallback;
      ret.m_mask |= std::uint64_t{1} << 21;
    }
    if (overline.has_value()) {
      ret.m_overline = *overline;
      ret.m_mask |= std::uint64_t{1} << 22;
    }
    if (standout.has_value()) {
      ret.m_standout = *standout;
      ret.m_mask |= std::uint64_t{1} << 23;
    }
    if (nocombine.has_value()) {
      ret.m_nocombine = *nocombine;
      ret.m_mask |= std::uint64_t{1} << 24;
    }
    if (undercurl.has_value()) {
      ret.m_undercurl = *undercurl;
      ret.m_mask |= std::uint64_t{1} << 25;
    }
    if (underline.has_value()) {
      ret.m_underline = *underline;
      ret.m_mask |= std::uint64_t{1} << 26;
    }
    if (background.has_value()) {
      ret.m_background = *background;
      ret.m_mask |= std::uint64_t{1} << 27;
    }
    if (bg_indexed.has_value()) {
      ret.m_bg_indexed = *bg_indexed;
      ret.m_mask |= std::uint64_t{1} << 28;
    }
    if (foreground.has_value()) {
      ret.m_foreground = *foreground;
      ret.m_mask |= std::uint64_t{1} << 29;
    }
    if (fg_indexed.has_value()) {
      ret.m_fg_indexed = *fg_indexed;
      ret.m_mask |= std::uint64_t{1} << 30;
    }
    if (global_link.has_value()) {
      ret.m_global_link = *global_link;
      ret.m_mask |= std::uint64_t{1} << 31;
    }
    if (underdashed.has_value()) {
      ret.m_underdashed = *underdashed;
      ret.m_mask |= std::uint64_t{1} << 32;
    }
    if (underdotted.has_value()) {
      ret.m_underdotted = *underdotted;
      ret.m_mask |= std::uint64_t{1} << 33;
    }
    if (underdouble.has_value()) {
      ret.m_underdouble = *underdouble;
      ret.m_mask |= std::uint64_t{1} << 34;
    }
    if (strikethrough.has_value()) {
      ret.m_strikethrough = *strikethrough;
      ret.m_mask |= std::uint64_t{1} << 35;
    }
    return ret;
  }
};
struct highlight_cterm {
  bool bold;
  bool standout;
  bool strikethrough;
  bool underline;
  bool undercurl;
  bool underdouble;
  bool underdotted;
  bool underdashed;
  bool italic;
  bool reverse;
  bool altfont;
  bool dim;
  bool blink;
  bool conceal;
  bool overline;
  bool nocombine;
  constexpr operator keysets::highlight_cterm() const noexcept {
    return {
      .bold = bold,.standout = standout,.strikethrough = strikethrough,.underline = underline,.undercurl = undercurl,.underdouble = underdouble,.underdotted = underdotted,.underdashed = underdashed,.italic = italic,.reverse = reverse,.altfont = altfont,.dim = dim,.blink = blink,.conceal = conceal,.overline = overline,.nocombine = nocombine,
    };
  }
};
struct get_highlight {
  std::optional<std::int64_t> id;
  std::optional<string> name;
  std::optional<bool> link;
  std::optional<bool> create;

  constexpr operator keysets::get_highlight() const noexcept {
    keysets::get_highlight ret{};
    if (id.has_value()) {
      ret.m_id = *id;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (link.has_value()) {
      ret.m_link = *link;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (name.has_value()) {
      ret.m_name = *name;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (create.has_value()) {
      ret.m_create = *create;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    return ret;
  }
};
struct get_ns {
  std::optional<nvpp::window> winid;

  constexpr operator keysets::get_ns() const noexcept {
    keysets::get_ns ret{};
    if (winid.has_value()) {
      ret.m_winid = *winid;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct win_text_height {
  std::optional<std::int64_t> start_row;
  std::optional<std::int64_t> end_row;
  std::optional<std::int64_t> start_vcol;
  std::optional<std::int64_t> end_vcol;
  std::optional<std::int64_t> max_height;

  constexpr operator keysets::win_text_height() const noexcept {
    keysets::win_text_height ret{};
    if (end_row.has_value()) {
      ret.m_end_row = *end_row;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (end_vcol.has_value()) {
      ret.m_end_vcol = *end_vcol;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (start_row.has_value()) {
      ret.m_start_row = *start_row;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (max_height.has_value()) {
      ret.m_max_height = *max_height;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (start_vcol.has_value()) {
      ret.m_start_vcol = *start_vcol;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    return ret;
  }
};
struct clear_autocmds {
  std::optional<nvpp::buffer> buffer;
  std::optional<object> event;
  std::optional<object> group;
  std::optional<object> pattern;

  constexpr operator keysets::clear_autocmds() const noexcept {
    keysets::clear_autocmds ret{};
    if (event.has_value()) {
      ret.m_event = *event;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (group.has_value()) {
      ret.m_group = *group;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (buffer.has_value()) {
      ret.m_buffer = *buffer;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (pattern.has_value()) {
      ret.m_pattern = *pattern;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    return ret;
  }
};
struct create_autocmd {
  std::optional<nvpp::buffer> buffer;
  std::optional<object> callback;
  std::optional<string> command;
  std::optional<string> desc;
  std::optional<object> group;
  std::optional<bool> nested;
  std::optional<bool> once;
  std::optional<object> pattern;

  constexpr operator keysets::create_autocmd() const noexcept {
    keysets::create_autocmd ret{};
    if (desc.has_value()) {
      ret.m_desc = *desc;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (once.has_value()) {
      ret.m_once = *once;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (group.has_value()) {
      ret.m_group = *group;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (buffer.has_value()) {
      ret.m_buffer = *buffer;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (nested.has_value()) {
      ret.m_nested = *nested;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (command.has_value()) {
      ret.m_command = *command;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (pattern.has_value()) {
      ret.m_pattern = *pattern;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (callback.has_value()) {
      ret.m_callback = *callback;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    return ret;
  }
};
struct exec_autocmds {
  std::optional<nvpp::buffer> buffer;
  std::optional<object> group;
  std::optional<bool> modeline;
  std::optional<object> pattern;
  std::optional<object> data;

  constexpr operator keysets::exec_autocmds() const noexcept {
    keysets::exec_autocmds ret{};
    if (data.has_value()) {
      ret.m_data = *data;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (group.has_value()) {
      ret.m_group = *group;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (buffer.has_value()) {
      ret.m_buffer = *buffer;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (pattern.has_value()) {
      ret.m_pattern = *pattern;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (modeline.has_value()) {
      ret.m_modeline = *modeline;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    return ret;
  }
};
struct get_autocmds {
  std::optional<object> event;
  std::optional<object> group;
  std::optional<object> pattern;
  std::optional<object> buffer;
  std::optional<std::int64_t> id;

  constexpr operator keysets::get_autocmds() const noexcept {
    keysets::get_autocmds ret{};
    if (id.has_value()) {
      ret.m_id = *id;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (event.has_value()) {
      ret.m_event = *event;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (group.has_value()) {
      ret.m_group = *group;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (buffer.has_value()) {
      ret.m_buffer = *buffer;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (pattern.has_value()) {
      ret.m_pattern = *pattern;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    return ret;
  }
};
struct create_augroup {
  std::optional<bool> clear;

  constexpr operator keysets::create_augroup() const noexcept {
    keysets::create_augroup ret{};
    if (clear.has_value()) {
      ret.m_clear = *clear;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct cmd {
  std::optional<string> cmd;
  std::optional<array_of<std::int64_t>> range;
  std::optional<std::int64_t> count;
  std::optional<string> reg;
  std::optional<bool> bang;
  std::optional<array_of<string>> args;
  std::optional<dict> magic;
  std::optional<dict> mods;
  std::optional<object> nargs;
  std::optional<string> addr;
  std::optional<string> nextcmd;

  constexpr operator keysets::cmd() const noexcept {
    keysets::cmd ret{};
    if (cmd.has_value()) {
      ret.m_cmd = *cmd;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (reg.has_value()) {
      ret.m_reg = *reg;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (bang.has_value()) {
      ret.m_bang = *bang;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (addr.has_value()) {
      ret.m_addr = *addr;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (mods.has_value()) {
      ret.m_mods = *mods;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (args.has_value()) {
      ret.m_args = *args;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (count.has_value()) {
      ret.m_count = *count;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (magic.has_value()) {
      ret.m_magic = *magic;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (nargs.has_value()) {
      ret.m_nargs = *nargs;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (range.has_value()) {
      ret.m_range = *range;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (nextcmd.has_value()) {
      ret.m_nextcmd = *nextcmd;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    return ret;
  }
};
struct cmd_magic {
  std::optional<bool> file;
  std::optional<bool> bar;

  constexpr operator keysets::cmd_magic() const noexcept {
    keysets::cmd_magic ret{};
    if (bar.has_value()) {
      ret.m_bar = *bar;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (file.has_value()) {
      ret.m_file = *file;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    return ret;
  }
};
struct cmd_mods {
  std::optional<bool> silent;
  std::optional<bool> emsg_silent;
  std::optional<bool> unsilent;
  std::optional<dict> filter;
  std::optional<bool> sandbox;
  std::optional<bool> noautocmd;
  std::optional<bool> browse;
  std::optional<bool> confirm;
  std::optional<bool> hide;
  std::optional<bool> horizontal;
  std::optional<bool> keepalt;
  std::optional<bool> keepjumps;
  std::optional<bool> keepmarks;
  std::optional<bool> keeppatterns;
  std::optional<bool> lockmarks;
  std::optional<bool> noswapfile;
  std::optional<std::int64_t> tab;
  std::optional<std::int64_t> verbose;
  std::optional<bool> vertical;
  std::optional<string> split;

  constexpr operator keysets::cmd_mods() const noexcept {
    keysets::cmd_mods ret{};
    if (tab.has_value()) {
      ret.m_tab = *tab;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (hide.has_value()) {
      ret.m_hide = *hide;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (split.has_value()) {
      ret.m_split = *split;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (browse.has_value()) {
      ret.m_browse = *browse;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (filter.has_value()) {
      ret.m_filter = *filter;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (silent.has_value()) {
      ret.m_silent = *silent;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (confirm.has_value()) {
      ret.m_confirm = *confirm;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (keepalt.has_value()) {
      ret.m_keepalt = *keepalt;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (sandbox.has_value()) {
      ret.m_sandbox = *sandbox;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (verbose.has_value()) {
      ret.m_verbose = *verbose;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (unsilent.has_value()) {
      ret.m_unsilent = *unsilent;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (vertical.has_value()) {
      ret.m_vertical = *vertical;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    if (keepjumps.has_value()) {
      ret.m_keepjumps = *keepjumps;
      ret.m_mask |= std::uint64_t{1} << 13;
    }
    if (keepmarks.has_value()) {
      ret.m_keepmarks = *keepmarks;
      ret.m_mask |= std::uint64_t{1} << 14;
    }
    if (lockmarks.has_value()) {
      ret.m_lockmarks = *lockmarks;
      ret.m_mask |= std::uint64_t{1} << 15;
    }
    if (noautocmd.has_value()) {
      ret.m_noautocmd = *noautocmd;
      ret.m_mask |= std::uint64_t{1} << 16;
    }
    if (horizontal.has_value()) {
      ret.m_horizontal = *horizontal;
      ret.m_mask |= std::uint64_t{1} << 17;
    }
    if (noswapfile.has_value()) {
      ret.m_noswapfile = *noswapfile;
      ret.m_mask |= std::uint64_t{1} << 18;
    }
    if (emsg_silent.has_value()) {
      ret.m_emsg_silent = *emsg_silent;
      ret.m_mask |= std::uint64_t{1} << 19;
    }
    if (keeppatterns.has_value()) {
      ret.m_keeppatterns = *keeppatterns;
      ret.m_mask |= std::uint64_t{1} << 20;
    }
    return ret;
  }
};
struct cmd_mods_filter {
  std::optional<string> pattern;
  std::optional<bool> force;

  constexpr operator keysets::cmd_mods_filter() const noexcept {
    keysets::cmd_mods_filter ret{};
    if (force.has_value()) {
      ret.m_force = *force;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (pattern.has_value()) {
      ret.m_pattern = *pattern;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    return ret;
  }
};
struct cmd_opts {
  bool output;
  constexpr operator keysets::cmd_opts() const noexcept {
    return {
      .output = output,
    };
  }
};
struct echo_opts {
  std::optional<bool> err;
  std::optional<bool> verbose;
  std::optional<string> kind;
  std::optional<object> id;
  std::optional<string> title;
  std::optional<string> status;
  std::optional<std::int64_t> percent;
  std::optional<string> source;
  std::optional<dict_of<object>> data;

  constexpr operator keysets::echo_opts() const noexcept {
    keysets::echo_opts ret{};
    if (id.has_value()) {
      ret.m_id = *id;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (err.has_value()) {
      ret.m_err = *err;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (data.has_value()) {
      ret.m_data = *data;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (kind.has_value()) {
      ret.m_kind = *kind;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (title.has_value()) {
      ret.m_title = *title;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (source.has_value()) {
      ret.m_source = *source;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (status.has_value()) {
      ret.m_status = *status;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (percent.has_value()) {
      ret.m_percent = *percent;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (verbose.has_value()) {
      ret.m_verbose = *verbose;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    return ret;
  }
};
struct exec_opts {
  bool output;
  constexpr operator keysets::exec_opts() const noexcept {
    return {
      .output = output,
    };
  }
};
struct buf_attach {
  std::optional<lua_ref> on_lines;
  std::optional<lua_ref> on_bytes;
  std::optional<lua_ref> on_changedtick;
  std::optional<lua_ref> on_detach;
  std::optional<lua_ref> on_reload;
  std::optional<bool> utf_sizes;
  std::optional<bool> preview;

  constexpr operator keysets::buf_attach() const noexcept {
    keysets::buf_attach ret{};
    if (preview.has_value()) {
      ret.m_preview = *preview;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (on_bytes.has_value()) {
      ret.m_on_bytes = *on_bytes;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (on_lines.has_value()) {
      ret.m_on_lines = *on_lines;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (utf_sizes.has_value()) {
      ret.m_utf_sizes = *utf_sizes;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (on_detach.has_value()) {
      ret.m_on_detach = *on_detach;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (on_reload.has_value()) {
      ret.m_on_reload = *on_reload;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (on_changedtick.has_value()) {
      ret.m_on_changedtick = *on_changedtick;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    return ret;
  }
};
struct buf_delete {
  std::optional<bool> force;
  std::optional<bool> unload;

  constexpr operator keysets::buf_delete() const noexcept {
    keysets::buf_delete ret{};
    if (force.has_value()) {
      ret.m_force = *force;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (unload.has_value()) {
      ret.m_unload = *unload;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    return ret;
  }
};
struct open_term {
  std::optional<lua_ref> on_input;
  std::optional<bool> force_crlf;

  constexpr operator keysets::open_term() const noexcept {
    keysets::open_term ret{};
    if (on_input.has_value()) {
      ret.m_on_input = *on_input;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (force_crlf.has_value()) {
      ret.m_force_crlf = *force_crlf;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    return ret;
  }
};
struct complete_set {
  std::optional<string> info;

  constexpr operator keysets::complete_set() const noexcept {
    keysets::complete_set ret{};
    if (info.has_value()) {
      ret.m_info = *info;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct xdl_diff {
  std::optional<lua_ref> on_hunk;
  std::optional<string> result_type;
  std::optional<string> algorithm;
  std::optional<std::int64_t> ctxlen;
  std::optional<std::int64_t> interhunkctxlen;
  std::optional<object> linematch;
  std::optional<bool> ignore_whitespace;
  std::optional<bool> ignore_whitespace_change;
  std::optional<bool> ignore_whitespace_change_at_eol;
  std::optional<bool> ignore_cr_at_eol;
  std::optional<bool> ignore_blank_lines;
  std::optional<bool> indent_heuristic;

  constexpr operator keysets::xdl_diff() const noexcept {
    keysets::xdl_diff ret{};
    if (ctxlen.has_value()) {
      ret.m_ctxlen = *ctxlen;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (on_hunk.has_value()) {
      ret.m_on_hunk = *on_hunk;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (algorithm.has_value()) {
      ret.m_algorithm = *algorithm;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (linematch.has_value()) {
      ret.m_linematch = *linematch;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (result_type.has_value()) {
      ret.m_result_type = *result_type;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (interhunkctxlen.has_value()) {
      ret.m_interhunkctxlen = *interhunkctxlen;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (ignore_cr_at_eol.has_value()) {
      ret.m_ignore_cr_at_eol = *ignore_cr_at_eol;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (indent_heuristic.has_value()) {
      ret.m_indent_heuristic = *indent_heuristic;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (ignore_whitespace.has_value()) {
      ret.m_ignore_whitespace = *ignore_whitespace;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (ignore_blank_lines.has_value()) {
      ret.m_ignore_blank_lines = *ignore_blank_lines;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    if (ignore_whitespace_change.has_value()) {
      ret.m_ignore_whitespace_change = *ignore_whitespace_change;
      ret.m_mask |= std::uint64_t{1} << 11;
    }
    if (ignore_whitespace_change_at_eol.has_value()) {
      ret.m_ignore_whitespace_change_at_eol = *ignore_whitespace_change_at_eol;
      ret.m_mask |= std::uint64_t{1} << 12;
    }
    return ret;
  }
};
struct redraw {
  std::optional<bool> flush;
  std::optional<bool> cursor;
  std::optional<bool> valid;
  std::optional<bool> statuscolumn;
  std::optional<bool> statusline;
  std::optional<bool> tabline;
  std::optional<bool> winbar;
  std::optional<array> range;
  std::optional<nvpp::window> win;
  std::optional<nvpp::buffer> buf;

  constexpr operator keysets::redraw() const noexcept {
    keysets::redraw ret{};
    if (buf.has_value()) {
      ret.m_buf = *buf;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (win.has_value()) {
      ret.m_win = *win;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (flush.has_value()) {
      ret.m_flush = *flush;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (range.has_value()) {
      ret.m_range = *range;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (valid.has_value()) {
      ret.m_valid = *valid;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (cursor.has_value()) {
      ret.m_cursor = *cursor;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (winbar.has_value()) {
      ret.m_winbar = *winbar;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (tabline.has_value()) {
      ret.m_tabline = *tabline;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (statusline.has_value()) {
      ret.m_statusline = *statusline;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (statuscolumn.has_value()) {
      ret.m_statuscolumn = *statuscolumn;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    return ret;
  }
};
struct ns_opts {
  std::optional<array> wins;

  constexpr operator keysets::ns_opts() const noexcept {
    keysets::ns_opts ret{};
    if (wins.has_value()) {
      ret.m_wins = *wins;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    return ret;
  }
};
struct _shada_search_pat {
  std::optional<bool> magic;
  std::optional<bool> smartcase;
  std::optional<bool> has_line_offset;
  std::optional<bool> place_cursor_at_end;
  std::optional<bool> is_last_used;
  std::optional<bool> is_substitute_pattern;
  std::optional<bool> highlighted;
  std::optional<bool> search_backward;
  std::optional<std::int64_t> offset;
  std::optional<string> pat;

  constexpr operator keysets::_shada_search_pat() const noexcept {
    keysets::_shada_search_pat ret{};
    if (search_backward.has_value()) {
      ret.m_search_backward = *search_backward;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (smartcase.has_value()) {
      ret.m_smartcase = *smartcase;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (place_cursor_at_end.has_value()) {
      ret.m_place_cursor_at_end = *place_cursor_at_end;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (highlighted.has_value()) {
      ret.m_highlighted = *highlighted;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (has_line_offset.has_value()) {
      ret.m_has_line_offset = *has_line_offset;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    if (magic.has_value()) {
      ret.m_magic = *magic;
      ret.m_mask |= std::uint64_t{1} << 6;
    }
    if (offset.has_value()) {
      ret.m_offset = *offset;
      ret.m_mask |= std::uint64_t{1} << 7;
    }
    if (pat.has_value()) {
      ret.m_pat = *pat;
      ret.m_mask |= std::uint64_t{1} << 8;
    }
    if (is_substitute_pattern.has_value()) {
      ret.m_is_substitute_pattern = *is_substitute_pattern;
      ret.m_mask |= std::uint64_t{1} << 9;
    }
    if (is_last_used.has_value()) {
      ret.m_is_last_used = *is_last_used;
      ret.m_mask |= std::uint64_t{1} << 10;
    }
    return ret;
  }
};
struct _shada_mark {
  std::optional<std::int64_t> n;
  std::optional<std::int64_t> l;
  std::optional<std::int64_t> c;
  std::optional<string> f;

  constexpr operator keysets::_shada_mark() const noexcept {
    keysets::_shada_mark ret{};
    if (c.has_value()) {
      ret.m_c = *c;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (f.has_value()) {
      ret.m_f = *f;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (l.has_value()) {
      ret.m_l = *l;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (n.has_value()) {
      ret.m_n = *n;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    return ret;
  }
};
struct _shada_register {
  std::optional<string_array> rc;
  std::optional<bool> ru;
  std::optional<std::int64_t> rt;
  std::optional<std::int64_t> n;
  std::optional<std::int64_t> rw;

  constexpr operator keysets::_shada_register() const noexcept {
    keysets::_shada_register ret{};
    if (n.has_value()) {
      ret.m_n = *n;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (rc.has_value()) {
      ret.m_rc = *rc;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (rt.has_value()) {
      ret.m_rt = *rt;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    if (ru.has_value()) {
      ret.m_ru = *ru;
      ret.m_mask |= std::uint64_t{1} << 4;
    }
    if (rw.has_value()) {
      ret.m_rw = *rw;
      ret.m_mask |= std::uint64_t{1} << 5;
    }
    return ret;
  }
};
struct _shada_buflist_item {
  std::optional<std::int64_t> l;
  std::optional<std::int64_t> c;
  std::optional<string> f;

  constexpr operator keysets::_shada_buflist_item() const noexcept {
    keysets::_shada_buflist_item ret{};
    if (c.has_value()) {
      ret.m_c = *c;
      ret.m_mask |= std::uint64_t{1} << 1;
    }
    if (f.has_value()) {
      ret.m_f = *f;
      ret.m_mask |= std::uint64_t{1} << 2;
    }
    if (l.has_value()) {
      ret.m_l = *l;
      ret.m_mask |= std::uint64_t{1} << 3;
    }
    return ret;
  }
};
}