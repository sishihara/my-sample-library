#include <sstream> // __str__

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

void bind_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // absl::CordBuffer file: line:105
		pybind11::class_<absl::CordBuffer, std::shared_ptr<absl::CordBuffer>> cl(M("absl"), "CordBuffer", "");
		cl.def( pybind11::init( [](){ return new absl::CordBuffer(); } ) );
		cl.def_static("MaximumPayload", (unsigned long (*)()) &absl::CordBuffer::MaximumPayload, "C++: absl::CordBuffer::MaximumPayload() --> unsigned long");
		cl.def_static("MaximumPayload", (unsigned long (*)(unsigned long)) &absl::CordBuffer::MaximumPayload, "C++: absl::CordBuffer::MaximumPayload(unsigned long) --> unsigned long", pybind11::arg("block_size"));
		cl.def_static("CreateWithDefaultLimit", (class absl::CordBuffer (*)(unsigned long)) &absl::CordBuffer::CreateWithDefaultLimit, "C++: absl::CordBuffer::CreateWithDefaultLimit(unsigned long) --> class absl::CordBuffer", pybind11::arg("capacity"));
		cl.def_static("CreateWithCustomLimit", (class absl::CordBuffer (*)(unsigned long, unsigned long)) &absl::CordBuffer::CreateWithCustomLimit, "C++: absl::CordBuffer::CreateWithCustomLimit(unsigned long, unsigned long) --> class absl::CordBuffer", pybind11::arg("block_size"), pybind11::arg("capacity"));
		cl.def("available", (class absl::Span<char> (absl::CordBuffer::*)()) &absl::CordBuffer::available, "C++: absl::CordBuffer::available() --> class absl::Span<char>");
		cl.def("available_up_to", (class absl::Span<char> (absl::CordBuffer::*)(unsigned long)) &absl::CordBuffer::available_up_to, "C++: absl::CordBuffer::available_up_to(unsigned long) --> class absl::Span<char>", pybind11::arg("size"));
		cl.def("data", (char * (absl::CordBuffer::*)()) &absl::CordBuffer::data, "C++: absl::CordBuffer::data() --> char *", pybind11::return_value_policy::automatic);
		cl.def("length", (unsigned long (absl::CordBuffer::*)() const) &absl::CordBuffer::length, "C++: absl::CordBuffer::length() const --> unsigned long");
		cl.def("capacity", (unsigned long (absl::CordBuffer::*)() const) &absl::CordBuffer::capacity, "C++: absl::CordBuffer::capacity() const --> unsigned long");
		cl.def("IncreaseLengthBy", (void (absl::CordBuffer::*)(unsigned long)) &absl::CordBuffer::IncreaseLengthBy, "C++: absl::CordBuffer::IncreaseLengthBy(unsigned long) --> void", pybind11::arg("n"));
		cl.def("SetLength", (void (absl::CordBuffer::*)(unsigned long)) &absl::CordBuffer::SetLength, "C++: absl::CordBuffer::SetLength(unsigned long) --> void", pybind11::arg("length"));
	}
}
