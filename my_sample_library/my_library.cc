#include <string>
#include "absl/status/status.h"

namespace my {

struct MyObj {
    
    std::string func1() {
        return "func1";
    }

    absl::Status func2() {
        return absl::Status(absl::StatusCode::kOk, "func2");
    }

};

};
