load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "e017528fd1c91c5a33f15493e3a398181a9e821a804eb7ff5acdd1d2d6c2b18d",
    strip_prefix = "rules_proto-4.0.0-3.20.0",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0-3.20.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

http_archive(
    name = "benchmark",
    sha256 = "e0e6a0f2a5e8971198e5d382507bfe8e4be504797d75bb7aec44b5ea368fa100",
    strip_prefix = "benchmark-1.7.0",
    urls = ["https://github.com/google/benchmark/archive/refs/tags/v1.7.0.zip"],
)

http_archive(
    name = "protobuf",
    strip_prefix = "protobuf-3.21.5",
    urls = ["https://github.com/protocolbuffers/protobuf/releases/download/v21.5/protobuf-cpp-3.21.5.zip"],
    #sha256="",
)
