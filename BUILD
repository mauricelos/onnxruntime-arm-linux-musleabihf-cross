load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "onnxruntime_test",
    srcs = ["test/onnxruntime_test.cpp"],
    copts = [
        "-std=c++20",
        "-Wall",
        "-Werror",
    ],
    features = ["fully_static_link"],
    linkopts = [
        "-static",
        "-lstdc++",
    ],
    linkstatic = True,
    deps = [
        "@onnxruntime",
    ],
)
