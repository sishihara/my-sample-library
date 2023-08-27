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

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // absl::Span file: line:153
		pybind11::class_<absl::Span<char>, std::shared_ptr<absl::Span<char>>> cl(M("absl"), "Span_char_t", "");
		cl.def( pybind11::init( [](){ return new absl::Span<char>(); } ) );
		cl.def( pybind11::init<char *, unsigned long>(), pybind11::arg("array"), pybind11::arg("length") );

		cl.def( pybind11::init( [](absl::Span<char> const &o){ return new absl::Span<char>(o); } ) );
		cl.def("data", (char * (absl::Span<char>::*)() const) &absl::Span<char>::data, "C++: absl::Span<char>::data() const --> char *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (absl::Span<char>::*)() const) &absl::Span<char>::size, "C++: absl::Span<char>::size() const --> unsigned long");
		cl.def("length", (unsigned long (absl::Span<char>::*)() const) &absl::Span<char>::length, "C++: absl::Span<char>::length() const --> unsigned long");
		cl.def("empty", (bool (absl::Span<char>::*)() const) &absl::Span<char>::empty, "C++: absl::Span<char>::empty() const --> bool");
		cl.def("__getitem__", (char & (absl::Span<char>::*)(unsigned long) const) &absl::Span<char>::operator[], "C++: absl::Span<char>::operator[](unsigned long) const --> char &", pybind11::return_value_policy::automatic, pybind11::arg("i"));
		cl.def("at", (char & (absl::Span<char>::*)(unsigned long) const) &absl::Span<char>::at, "C++: absl::Span<char>::at(unsigned long) const --> char &", pybind11::return_value_policy::automatic, pybind11::arg("i"));
		cl.def("front", (char & (absl::Span<char>::*)() const) &absl::Span<char>::front, "C++: absl::Span<char>::front() const --> char &", pybind11::return_value_policy::automatic);
		cl.def("back", (char & (absl::Span<char>::*)() const) &absl::Span<char>::back, "C++: absl::Span<char>::back() const --> char &", pybind11::return_value_policy::automatic);
		cl.def("begin", (char * (absl::Span<char>::*)() const) &absl::Span<char>::begin, "C++: absl::Span<char>::begin() const --> char *", pybind11::return_value_policy::automatic);
		cl.def("cbegin", (const char * (absl::Span<char>::*)() const) &absl::Span<char>::cbegin, "C++: absl::Span<char>::cbegin() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("end", (char * (absl::Span<char>::*)() const) &absl::Span<char>::end, "C++: absl::Span<char>::end() const --> char *", pybind11::return_value_policy::automatic);
		cl.def("cend", (const char * (absl::Span<char>::*)() const) &absl::Span<char>::cend, "C++: absl::Span<char>::cend() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("remove_prefix", (void (absl::Span<char>::*)(unsigned long)) &absl::Span<char>::remove_prefix, "C++: absl::Span<char>::remove_prefix(unsigned long) --> void", pybind11::arg("n"));
		cl.def("remove_suffix", (void (absl::Span<char>::*)(unsigned long)) &absl::Span<char>::remove_suffix, "C++: absl::Span<char>::remove_suffix(unsigned long) --> void", pybind11::arg("n"));
		cl.def("subspan", [](absl::Span<char> const &o) -> absl::Span<char> { return o.subspan(); }, "");
		cl.def("subspan", [](absl::Span<char> const &o, unsigned long const & a0) -> absl::Span<char> { return o.subspan(a0); }, "", pybind11::arg("pos"));
		cl.def("subspan", (class absl::Span<char> (absl::Span<char>::*)(unsigned long, unsigned long) const) &absl::Span<char>::subspan, "C++: absl::Span<char>::subspan(unsigned long, unsigned long) const --> class absl::Span<char>", pybind11::arg("pos"), pybind11::arg("len"));
		cl.def("first", (class absl::Span<char> (absl::Span<char>::*)(unsigned long) const) &absl::Span<char>::first, "C++: absl::Span<char>::first(unsigned long) const --> class absl::Span<char>", pybind11::arg("len"));
		cl.def("last", (class absl::Span<char> (absl::Span<char>::*)(unsigned long) const) &absl::Span<char>::last, "C++: absl::Span<char>::last(unsigned long) const --> class absl::Span<char>", pybind11::arg("len"));
	}
}
