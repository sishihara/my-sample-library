#include <ios>
#include <iterator>
#include <locale>
#include <memory>
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

void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// absl::StatusToStringMode file: line:290
	pybind11::enum_<absl::StatusToStringMode>(M("absl"), "StatusToStringMode", "")
		.value("kWithNoExtraData", absl::StatusToStringMode::kWithNoExtraData)
		.value("kWithPayload", absl::StatusToStringMode::kWithPayload)
		.value("kWithEverything", absl::StatusToStringMode::kWithEverything)
		.value("kDefault", absl::StatusToStringMode::kDefault);

;

	{ // absl::Status file: line:424
		pybind11::class_<absl::Status, std::shared_ptr<absl::Status>> cl(M("absl"), "Status", "");
		cl.def( pybind11::init( [](){ return new absl::Status(); } ) );
		cl.def( pybind11::init<enum absl::StatusCode, class std::basic_string_view<char>>(), pybind11::arg("code"), pybind11::arg("msg") );

		cl.def( pybind11::init( [](absl::Status const &o){ return new absl::Status(o); } ) );
		cl.def("assign", (class absl::Status & (absl::Status::*)(const class absl::Status &)) &absl::Status::operator=, "C++: absl::Status::operator=(const class absl::Status &) --> class absl::Status &", pybind11::return_value_policy::automatic, pybind11::arg("x"));
		cl.def("Update", (void (absl::Status::*)(const class absl::Status &)) &absl::Status::Update, "C++: absl::Status::Update(const class absl::Status &) --> void", pybind11::arg("new_status"));
		cl.def("ok", (bool (absl::Status::*)() const) &absl::Status::ok, "C++: absl::Status::ok() const --> bool");
		cl.def("code", (enum absl::StatusCode (absl::Status::*)() const) &absl::Status::code, "C++: absl::Status::code() const --> enum absl::StatusCode");
		cl.def("raw_code", (int (absl::Status::*)() const) &absl::Status::raw_code, "C++: absl::Status::raw_code() const --> int");
		cl.def("message", (class std::basic_string_view<char> (absl::Status::*)() const) &absl::Status::message, "C++: absl::Status::message() const --> class std::basic_string_view<char>");
		cl.def("ToString", [](absl::Status const &o) -> std::string { return o.ToString(); }, "");
		cl.def("ToString", (std::string (absl::Status::*)(enum absl::StatusToStringMode) const) &absl::Status::ToString, "C++: absl::Status::ToString(enum absl::StatusToStringMode) const --> std::string", pybind11::arg("mode"));
		cl.def("IgnoreError", (void (absl::Status::*)() const) &absl::Status::IgnoreError, "C++: absl::Status::IgnoreError() const --> void");
		cl.def("SetPayload", (void (absl::Status::*)(class std::basic_string_view<char>, class absl::Cord)) &absl::Status::SetPayload, "C++: absl::Status::SetPayload(class std::basic_string_view<char>, class absl::Cord) --> void", pybind11::arg("type_url"), pybind11::arg("payload"));
		cl.def("ErasePayload", (bool (absl::Status::*)(class std::basic_string_view<char>)) &absl::Status::ErasePayload, "C++: absl::Status::ErasePayload(class std::basic_string_view<char>) --> bool", pybind11::arg("type_url"));

		cl.def("__str__", [](absl::Status const &o) -> std::string { std::ostringstream s; using namespace absl; s << o; return s.str(); } );
	}
}
