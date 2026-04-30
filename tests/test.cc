#include <nvpp/macros.hh>
#include <nvpp/types.hh>

[[maybe_unused]]
constexpr auto arr = nvpp_array(1, "");

// static_assert(nvpp::object{true}.get<bool>() == true);
// static_assert(nvpp::object{1}.get_unchecked<int>() == 1);
//
// constexpr auto xs = std::array<nvpp::object, 3>{1, 2, 3};
// constexpr auto arr = nvpp::array(xs);
// constexpr auto tpl = arr.to_tuple_unchecked<int, int>();
// static_assert(std::get<1>(tpl) == 2);
