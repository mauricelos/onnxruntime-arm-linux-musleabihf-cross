package(default_visibility = ["//visibility:public"])

toolchain(
    name = "arm32_gcc_linux_x86_64_musl",
    exec_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
    target_compatible_with = [
        "@platforms//os:linux",
        "@platforms//cpu:armv7",
    ],
    toolchain_type = "@rules_cc//cc:toolchain_type",
    toolchain = "@arm32_gcc_linux_x86_64_musl//:cc_toolchain",
)

platform(
    name = "toolchain_arm32_gcc_musl",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:armv7",
    ],
)
