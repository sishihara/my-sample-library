#include <optional>
#include <sstream> // __str__
#include <string>
#include <string_view>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <pybind11/stl.h>
#include "absl/status/status.h"
#include "my_sample_library/my_library.h"


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_optional(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::optional file:optional line:662
		pybind11::class_<std::optional<std::basic_string_view<char>>, std::shared_ptr<std::optional<std::basic_string_view<char>>>> cl(M("std"), "optional_std_basic_string_view_char_t", "");
		cl.def( pybind11::init( [](){ return new std::optional<std::basic_string_view<char>>(); } ) );
		cl.def( pybind11::init<struct std::nullopt_t>(), pybind11::arg("") );

		cl.def( pybind11::init( [](std::optional<std::basic_string_view<char>> const &o){ return new std::optional<std::basic_string_view<char>>(o); } ) );
		cl.def("assign", (class std::optional<class std::basic_string_view<char> > & (std::optional<std::basic_string_view<char>>::*)(struct std::nullopt_t)) &std::optional<std::basic_string_view<char>>::operator=, "C++: std::optional<std::basic_string_view<char>>::operator=(struct std::nullopt_t) --> class std::optional<class std::basic_string_view<char> > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("swap", (void (std::optional<std::basic_string_view<char>>::*)(class std::optional<class std::basic_string_view<char> > &)) &std::optional<std::basic_string_view<char>>::swap, "C++: std::optional<std::basic_string_view<char>>::swap(class std::optional<class std::basic_string_view<char> > &) --> void", pybind11::arg("__other"));
		cl.def("arrow", (class std::basic_string_view<char> * (std::optional<std::basic_string_view<char>>::*)()) &std::optional<std::basic_string_view<char>>::operator->, "C++: std::optional<std::basic_string_view<char>>::operator->() --> class std::basic_string_view<char> *", pybind11::return_value_policy::automatic);
		cl.def("dereference", (class std::basic_string_view<char> & (std::optional<std::basic_string_view<char>>::*)()) &std::optional<std::basic_string_view<char>>::operator*, "C++: std::optional<std::basic_string_view<char>>::operator*() --> class std::basic_string_view<char> &", pybind11::return_value_policy::automatic);
		cl.def("has_value", (bool (std::optional<std::basic_string_view<char>>::*)() const) &std::optional<std::basic_string_view<char>>::has_value, "C++: std::optional<std::basic_string_view<char>>::has_value() const --> bool");
		cl.def("value", (class std::basic_string_view<char> & (std::optional<std::basic_string_view<char>>::*)()) &std::optional<std::basic_string_view<char>>::value, "C++: std::optional<std::basic_string_view<char>>::value() --> class std::basic_string_view<char> &", pybind11::return_value_policy::automatic);
		cl.def("reset", (void (std::optional<std::basic_string_view<char>>::*)()) &std::optional<std::basic_string_view<char>>::reset, "C++: std::optional<std::basic_string_view<char>>::reset() --> void");
		cl.def("assign", (class std::optional<class std::basic_string_view<char> > & (std::optional<std::basic_string_view<char>>::*)(const class std::optional<class std::basic_string_view<char> > &)) &std::optional<std::basic_string_view<char>>::operator=, "C++: std::optional<std::basic_string_view<char>>::operator=(const class std::optional<class std::basic_string_view<char> > &) --> class std::optional<class std::basic_string_view<char> > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // std::nullopt_t file:optional line:68
		pybind11::class_<std::nullopt_t, std::shared_ptr<std::nullopt_t>> cl(M("std"), "nullopt_t", "");
		cl.def( pybind11::init<enum std::nullopt_t::_Construct>(), pybind11::arg("") );

		cl.def( pybind11::init( [](std::nullopt_t const &o){ return new std::nullopt_t(o); } ) );

		pybind11::enum_<std::nullopt_t::_Construct>(cl, "_Construct", "")
			.value("_Token", std::nullopt_t::_Construct::_Token);

	}
}
