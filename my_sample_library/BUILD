
package(default_visibility = [":my_library_impl"])

package_group(
    name = "my_library_impl",
    packages = [
        "//my_sample_library/...",
    ],
)

cc_library(
    name = "my_library",
    srcs = ["my_library.cc"],
    hdrs = ["my_library.h"],
    deps = [
        "@com_google_absl//absl/status",
    ],
)
