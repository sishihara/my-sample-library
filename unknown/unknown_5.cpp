#include <iterator>
#include <memory>
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

void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // my::MyObj file: line:6
		pybind11::class_<my::MyObj, std::shared_ptr<my::MyObj>> cl(M("my"), "MyObj", "");
		cl.def( pybind11::init( [](){ return new my::MyObj(); } ) );
		cl.def("func1", (std::string (my::MyObj::*)()) &my::MyObj::func1, "C++: my::MyObj::func1() --> std::string");
		cl.def("func2", (class absl::Status (my::MyObj::*)()) &my::MyObj::func2, "C++: my::MyObj::func2() --> class absl::Status");
	}
}
