workspace(name = "my_sample_library")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    ],
)

http_archive(
    name = "com_google_absl",
    # Commit from 2023-03-16
    url = "https://github.com/abseil/abseil-cpp/archive/0697762c62cdb51ead8d9c2f0d299c5d4a4ff9db.tar.gz",
    sha256 = "3439843ac7d7b9cc354dd6735b6790fa7589b73429bbda77976e0db61e92f1fd",
    strip_prefix = "abseil-cpp-0697762c62cdb51ead8d9c2f0d299c5d4a4ff9db",
)