#include<string>
#include "absl/status/status.h"

namespace my {

struct MyObj {
    std::string func1();
    absl::Status func2();
};

};
