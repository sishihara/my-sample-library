#include<string>
#include "absl/status/status.h"

struct MyObj {
    std::string func1();
    absl::Status func2();
}