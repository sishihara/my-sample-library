
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

void bind_unknown_unknown_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// absl::StatusCode file: line:46
	pybind11::enum_<absl::StatusCode>(M("absl"), "StatusCode", "")
		.value("kOk", absl::StatusCode::kOk)
		.value("kCancelled", absl::StatusCode::kCancelled)
		.value("kUnknown", absl::StatusCode::kUnknown)
		.value("kInvalidArgument", absl::StatusCode::kInvalidArgument)
		.value("kDeadlineExceeded", absl::StatusCode::kDeadlineExceeded)
		.value("kNotFound", absl::StatusCode::kNotFound)
		.value("kAlreadyExists", absl::StatusCode::kAlreadyExists)
		.value("kPermissionDenied", absl::StatusCode::kPermissionDenied)
		.value("kResourceExhausted", absl::StatusCode::kResourceExhausted)
		.value("kFailedPrecondition", absl::StatusCode::kFailedPrecondition)
		.value("kAborted", absl::StatusCode::kAborted)
		.value("kOutOfRange", absl::StatusCode::kOutOfRange)
		.value("kUnimplemented", absl::StatusCode::kUnimplemented)
		.value("kInternal", absl::StatusCode::kInternal)
		.value("kUnavailable", absl::StatusCode::kUnavailable)
		.value("kDataLoss", absl::StatusCode::kDataLoss)
		.value("kUnauthenticated", absl::StatusCode::kUnauthenticated)
		.value("kDoNotUseReservedForFutureExpansionUseDefaultInSwitchInstead_", absl::StatusCode::kDoNotUseReservedForFutureExpansionUseDefaultInSwitchInstead_);

;

}
