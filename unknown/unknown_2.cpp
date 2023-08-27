#include <ios>
#include <locale>
#include <optional>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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

void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// absl::CordMemoryAccounting file: line:109
	pybind11::enum_<absl::CordMemoryAccounting>(M("absl"), "CordMemoryAccounting", "")
		.value("kTotal", absl::CordMemoryAccounting::kTotal)
		.value("kFairShare", absl::CordMemoryAccounting::kFairShare);

;

	{ // absl::Cord file: line:150
		pybind11::class_<absl::Cord, std::shared_ptr<absl::Cord>> cl(M("absl"), "Cord", "");
		cl.def( pybind11::init( [](){ return new absl::Cord(); } ) );
		cl.def( pybind11::init( [](absl::Cord const &o){ return new absl::Cord(o); } ) );
		cl.def( pybind11::init<class std::basic_string_view<char>>(), pybind11::arg("src") );

		cl.def("assign", (class absl::Cord & (absl::Cord::*)(const class absl::Cord &)) &absl::Cord::operator=, "C++: absl::Cord::operator=(const class absl::Cord &) --> class absl::Cord &", pybind11::return_value_policy::automatic, pybind11::arg("x"));
		cl.def("assign", (class absl::Cord & (absl::Cord::*)(class std::basic_string_view<char>)) &absl::Cord::operator=, "C++: absl::Cord::operator=(class std::basic_string_view<char>) --> class absl::Cord &", pybind11::return_value_policy::automatic, pybind11::arg("src"));
		cl.def("Clear", (void (absl::Cord::*)()) &absl::Cord::Clear, "C++: absl::Cord::Clear() --> void");
		cl.def("Append", (void (absl::Cord::*)(const class absl::Cord &)) &absl::Cord::Append, "C++: absl::Cord::Append(const class absl::Cord &) --> void", pybind11::arg("src"));
		cl.def("Append", (void (absl::Cord::*)(class std::basic_string_view<char>)) &absl::Cord::Append, "C++: absl::Cord::Append(class std::basic_string_view<char>) --> void", pybind11::arg("src"));
		cl.def("Append", (void (absl::Cord::*)(class absl::CordBuffer)) &absl::Cord::Append, "C++: absl::Cord::Append(class absl::CordBuffer) --> void", pybind11::arg("buffer"));
		cl.def("GetAppendBuffer", [](absl::Cord &o, unsigned long const & a0) -> absl::CordBuffer { return o.GetAppendBuffer(a0); }, "", pybind11::arg("capacity"));
		cl.def("GetAppendBuffer", (class absl::CordBuffer (absl::Cord::*)(unsigned long, unsigned long)) &absl::Cord::GetAppendBuffer, "C++: absl::Cord::GetAppendBuffer(unsigned long, unsigned long) --> class absl::CordBuffer", pybind11::arg("capacity"), pybind11::arg("min_capacity"));
		cl.def("GetCustomAppendBuffer", [](absl::Cord &o, unsigned long const & a0, unsigned long const & a1) -> absl::CordBuffer { return o.GetCustomAppendBuffer(a0, a1); }, "", pybind11::arg("block_size"), pybind11::arg("capacity"));
		cl.def("GetCustomAppendBuffer", (class absl::CordBuffer (absl::Cord::*)(unsigned long, unsigned long, unsigned long)) &absl::Cord::GetCustomAppendBuffer, "C++: absl::Cord::GetCustomAppendBuffer(unsigned long, unsigned long, unsigned long) --> class absl::CordBuffer", pybind11::arg("block_size"), pybind11::arg("capacity"), pybind11::arg("min_capacity"));
		cl.def("Prepend", (void (absl::Cord::*)(const class absl::Cord &)) &absl::Cord::Prepend, "C++: absl::Cord::Prepend(const class absl::Cord &) --> void", pybind11::arg("src"));
		cl.def("Prepend", (void (absl::Cord::*)(class std::basic_string_view<char>)) &absl::Cord::Prepend, "C++: absl::Cord::Prepend(class std::basic_string_view<char>) --> void", pybind11::arg("src"));
		cl.def("Prepend", (void (absl::Cord::*)(class absl::CordBuffer)) &absl::Cord::Prepend, "C++: absl::Cord::Prepend(class absl::CordBuffer) --> void", pybind11::arg("buffer"));
		cl.def("RemovePrefix", (void (absl::Cord::*)(unsigned long)) &absl::Cord::RemovePrefix, "C++: absl::Cord::RemovePrefix(unsigned long) --> void", pybind11::arg("n"));
		cl.def("RemoveSuffix", (void (absl::Cord::*)(unsigned long)) &absl::Cord::RemoveSuffix, "C++: absl::Cord::RemoveSuffix(unsigned long) --> void", pybind11::arg("n"));
		cl.def("Subcord", (class absl::Cord (absl::Cord::*)(unsigned long, unsigned long) const) &absl::Cord::Subcord, "C++: absl::Cord::Subcord(unsigned long, unsigned long) const --> class absl::Cord", pybind11::arg("pos"), pybind11::arg("new_size"));
		cl.def("swap", (void (absl::Cord::*)(class absl::Cord &)) &absl::Cord::swap, "C++: absl::Cord::swap(class absl::Cord &) --> void", pybind11::arg("other"));
		cl.def("size", (unsigned long (absl::Cord::*)() const) &absl::Cord::size, "C++: absl::Cord::size() const --> unsigned long");
		cl.def("empty", (bool (absl::Cord::*)() const) &absl::Cord::empty, "C++: absl::Cord::empty() const --> bool");
		cl.def("EstimatedMemoryUsage", [](absl::Cord const &o) -> unsigned long { return o.EstimatedMemoryUsage(); }, "");
		cl.def("EstimatedMemoryUsage", (unsigned long (absl::Cord::*)(enum absl::CordMemoryAccounting) const) &absl::Cord::EstimatedMemoryUsage, "C++: absl::Cord::EstimatedMemoryUsage(enum absl::CordMemoryAccounting) const --> unsigned long", pybind11::arg("accounting_method"));
		cl.def("Compare", (int (absl::Cord::*)(class std::basic_string_view<char>) const) &absl::Cord::Compare, "C++: absl::Cord::Compare(class std::basic_string_view<char>) const --> int", pybind11::arg("rhs"));
		cl.def("Compare", (int (absl::Cord::*)(const class absl::Cord &) const) &absl::Cord::Compare, "C++: absl::Cord::Compare(const class absl::Cord &) const --> int", pybind11::arg("rhs"));
		cl.def("StartsWith", (bool (absl::Cord::*)(const class absl::Cord &) const) &absl::Cord::StartsWith, "C++: absl::Cord::StartsWith(const class absl::Cord &) const --> bool", pybind11::arg("rhs"));
		cl.def("StartsWith", (bool (absl::Cord::*)(class std::basic_string_view<char>) const) &absl::Cord::StartsWith, "C++: absl::Cord::StartsWith(class std::basic_string_view<char>) const --> bool", pybind11::arg("rhs"));
		cl.def("EndsWith", (bool (absl::Cord::*)(class std::basic_string_view<char>) const) &absl::Cord::EndsWith, "C++: absl::Cord::EndsWith(class std::basic_string_view<char>) const --> bool", pybind11::arg("rhs"));
		cl.def("EndsWith", (bool (absl::Cord::*)(const class absl::Cord &) const) &absl::Cord::EndsWith, "C++: absl::Cord::EndsWith(const class absl::Cord &) const --> bool", pybind11::arg("rhs"));
		cl.def("chunk_begin", (class absl::Cord::ChunkIterator (absl::Cord::*)() const) &absl::Cord::chunk_begin, "C++: absl::Cord::chunk_begin() const --> class absl::Cord::ChunkIterator");
		cl.def("chunk_end", (class absl::Cord::ChunkIterator (absl::Cord::*)() const) &absl::Cord::chunk_end, "C++: absl::Cord::chunk_end() const --> class absl::Cord::ChunkIterator");
		cl.def("Chunks", (class absl::Cord::ChunkRange (absl::Cord::*)() const) &absl::Cord::Chunks, "C++: absl::Cord::Chunks() const --> class absl::Cord::ChunkRange");
		cl.def_static("AdvanceAndRead", (class absl::Cord (*)(class absl::Cord::CharIterator *, unsigned long)) &absl::Cord::AdvanceAndRead, "C++: absl::Cord::AdvanceAndRead(class absl::Cord::CharIterator *, unsigned long) --> class absl::Cord", pybind11::arg("it"), pybind11::arg("n_bytes"));
		cl.def_static("Advance", (void (*)(class absl::Cord::CharIterator *, unsigned long)) &absl::Cord::Advance, "C++: absl::Cord::Advance(class absl::Cord::CharIterator *, unsigned long) --> void", pybind11::arg("it"), pybind11::arg("n_bytes"));
		cl.def_static("ChunkRemaining", (class std::basic_string_view<char> (*)(const class absl::Cord::CharIterator &)) &absl::Cord::ChunkRemaining, "C++: absl::Cord::ChunkRemaining(const class absl::Cord::CharIterator &) --> class std::basic_string_view<char>", pybind11::arg("it"));
		cl.def("char_begin", (class absl::Cord::CharIterator (absl::Cord::*)() const) &absl::Cord::char_begin, "C++: absl::Cord::char_begin() const --> class absl::Cord::CharIterator");
		cl.def("char_end", (class absl::Cord::CharIterator (absl::Cord::*)() const) &absl::Cord::char_end, "C++: absl::Cord::char_end() const --> class absl::Cord::CharIterator");
		cl.def("Chars", (class absl::Cord::CharRange (absl::Cord::*)() const) &absl::Cord::Chars, "C++: absl::Cord::Chars() const --> class absl::Cord::CharRange");
		cl.def("__getitem__", (char (absl::Cord::*)(unsigned long) const) &absl::Cord::operator[], "C++: absl::Cord::operator[](unsigned long) const --> char", pybind11::arg("i"));
		cl.def("TryFlat", (class std::optional<class std::basic_string_view<char> > (absl::Cord::*)() const) &absl::Cord::TryFlat, "C++: absl::Cord::TryFlat() const --> class std::optional<class std::basic_string_view<char> >");
		cl.def("Flatten", (class std::basic_string_view<char> (absl::Cord::*)()) &absl::Cord::Flatten, "C++: absl::Cord::Flatten() --> class std::basic_string_view<char>");
		cl.def("SetExpectedChecksum", (void (absl::Cord::*)(unsigned int)) &absl::Cord::SetExpectedChecksum, "C++: absl::Cord::SetExpectedChecksum(unsigned int) --> void", pybind11::arg("crc"));

		cl.def("__str__", [](absl::Cord const &o) -> std::string { std::ostringstream s; using namespace absl; s << o; return s.str(); } );

		{ // absl::Cord::CharIterator file: line:586
			auto & enclosing_class = cl;
			pybind11::class_<absl::Cord::CharIterator, std::shared_ptr<absl::Cord::CharIterator>> cl(enclosing_class, "CharIterator", "");
			cl.def( pybind11::init( [](){ return new absl::Cord::CharIterator(); } ) );
			cl.def( pybind11::init( [](absl::Cord::CharIterator const &o){ return new absl::Cord::CharIterator(o); } ) );
			cl.def("pre_increment", (class absl::Cord::CharIterator & (absl::Cord::CharIterator::*)()) &absl::Cord::CharIterator::operator++, "C++: absl::Cord::CharIterator::operator++() --> class absl::Cord::CharIterator &", pybind11::return_value_policy::automatic);
			cl.def("post_increment", (class absl::Cord::CharIterator (absl::Cord::CharIterator::*)(int)) &absl::Cord::CharIterator::operator++, "C++: absl::Cord::CharIterator::operator++(int) --> class absl::Cord::CharIterator", pybind11::arg(""));
			cl.def("__eq__", (bool (absl::Cord::CharIterator::*)(const class absl::Cord::CharIterator &) const) &absl::Cord::CharIterator::operator==, "C++: absl::Cord::CharIterator::operator==(const class absl::Cord::CharIterator &) const --> bool", pybind11::arg("other"));
			cl.def("__ne__", (bool (absl::Cord::CharIterator::*)(const class absl::Cord::CharIterator &) const) &absl::Cord::CharIterator::operator!=, "C++: absl::Cord::CharIterator::operator!=(const class absl::Cord::CharIterator &) const --> bool", pybind11::arg("other"));
			cl.def("dereference", (const char & (absl::Cord::CharIterator::*)() const) &absl::Cord::CharIterator::operator*, "C++: absl::Cord::CharIterator::operator*() const --> const char &", pybind11::return_value_policy::automatic);
			cl.def("arrow", (const char * (absl::Cord::CharIterator::*)() const) &absl::Cord::CharIterator::operator->, "C++: absl::Cord::CharIterator::operator->() const --> const char *", pybind11::return_value_policy::automatic);
		}

		{ // absl::Cord::ChunkIterator file: line:425
			auto & enclosing_class = cl;
			pybind11::class_<absl::Cord::ChunkIterator, std::shared_ptr<absl::Cord::ChunkIterator>> cl(enclosing_class, "ChunkIterator", "");
			cl.def( pybind11::init( [](){ return new absl::Cord::ChunkIterator(); } ) );
			cl.def( pybind11::init( [](absl::Cord::ChunkIterator const &o){ return new absl::Cord::ChunkIterator(o); } ) );
			cl.def("pre_increment", (class absl::Cord::ChunkIterator & (absl::Cord::ChunkIterator::*)()) &absl::Cord::ChunkIterator::operator++, "C++: absl::Cord::ChunkIterator::operator++() --> class absl::Cord::ChunkIterator &", pybind11::return_value_policy::automatic);
			cl.def("post_increment", (class absl::Cord::ChunkIterator (absl::Cord::ChunkIterator::*)(int)) &absl::Cord::ChunkIterator::operator++, "C++: absl::Cord::ChunkIterator::operator++(int) --> class absl::Cord::ChunkIterator", pybind11::arg(""));
			cl.def("__eq__", (bool (absl::Cord::ChunkIterator::*)(const class absl::Cord::ChunkIterator &) const) &absl::Cord::ChunkIterator::operator==, "C++: absl::Cord::ChunkIterator::operator==(const class absl::Cord::ChunkIterator &) const --> bool", pybind11::arg("other"));
			cl.def("__ne__", (bool (absl::Cord::ChunkIterator::*)(const class absl::Cord::ChunkIterator &) const) &absl::Cord::ChunkIterator::operator!=, "C++: absl::Cord::ChunkIterator::operator!=(const class absl::Cord::ChunkIterator &) const --> bool", pybind11::arg("other"));
			cl.def("dereference", (class std::basic_string_view<char> (absl::Cord::ChunkIterator::*)() const) &absl::Cord::ChunkIterator::operator*, "C++: absl::Cord::ChunkIterator::operator*() const --> class std::basic_string_view<char>");
			cl.def("arrow", (const class std::basic_string_view<char> * (absl::Cord::ChunkIterator::*)() const) &absl::Cord::ChunkIterator::operator->, "C++: absl::Cord::ChunkIterator::operator->() const --> const class std::basic_string_view<char> *", pybind11::return_value_policy::automatic);
			cl.def("assign", (class absl::Cord::ChunkIterator & (absl::Cord::ChunkIterator::*)(const class absl::Cord::ChunkIterator &)) &absl::Cord::ChunkIterator::operator=, "C++: absl::Cord::ChunkIterator::operator=(const class absl::Cord::ChunkIterator &) --> class absl::Cord::ChunkIterator &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // absl::Cord::ChunkRange file: line:520
			auto & enclosing_class = cl;
			pybind11::class_<absl::Cord::ChunkRange, std::shared_ptr<absl::Cord::ChunkRange>> cl(enclosing_class, "ChunkRange", "");
			cl.def( pybind11::init<const class absl::Cord *>(), pybind11::arg("cord") );

			cl.def( pybind11::init( [](absl::Cord::ChunkRange const &o){ return new absl::Cord::ChunkRange(o); } ) );
			cl.def("begin", (class absl::Cord::ChunkIterator (absl::Cord::ChunkRange::*)() const) &absl::Cord::ChunkRange::begin, "C++: absl::Cord::ChunkRange::begin() const --> class absl::Cord::ChunkIterator");
			cl.def("end", (class absl::Cord::ChunkIterator (absl::Cord::ChunkRange::*)() const) &absl::Cord::ChunkRange::end, "C++: absl::Cord::ChunkRange::end() const --> class absl::Cord::ChunkIterator");
		}

		{ // absl::Cord::CharRange file: line:661
			auto & enclosing_class = cl;
			pybind11::class_<absl::Cord::CharRange, std::shared_ptr<absl::Cord::CharRange>> cl(enclosing_class, "CharRange", "");
			cl.def( pybind11::init<const class absl::Cord *>(), pybind11::arg("cord") );

			cl.def( pybind11::init( [](absl::Cord::CharRange const &o){ return new absl::Cord::CharRange(o); } ) );
			cl.def("begin", (class absl::Cord::CharIterator (absl::Cord::CharRange::*)() const) &absl::Cord::CharRange::begin, "C++: absl::Cord::CharRange::begin() const --> class absl::Cord::CharIterator");
			cl.def("end", (class absl::Cord::CharIterator (absl::Cord::CharRange::*)() const) &absl::Cord::CharRange::end, "C++: absl::Cord::CharRange::end() const --> class absl::Cord::CharIterator");
		}

	}
}
