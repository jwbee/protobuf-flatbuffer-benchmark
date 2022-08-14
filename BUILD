# Run as: bazelisk-linux-amd64 run -c opt :proto_benchmark

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")

proto_library(
    name = "test_proto",
    srcs = ["test.proto"],
)

cc_proto_library(
    name = "test_cc_proto",
    deps = [":test_proto"],
)

cc_binary(
    name = "proto_benchmark",
    srcs = ["main.cc"],
    copts = ["-std=c++20","-Wall"],
    deps = [
        ":test_cc_proto",
        "@benchmark//:benchmark_main",
        "@protobuf//:protobuf_lite",
    ],
)
