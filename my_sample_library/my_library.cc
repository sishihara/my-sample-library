#include <string>
#include "absl/status/status.h"

struct MyObj {
    
    std::string func1() {
        return "func1";
    }

    absl::Status func2() {
        return absl::Status(absl::StatusCode::kOk, "func2");
    }

};
