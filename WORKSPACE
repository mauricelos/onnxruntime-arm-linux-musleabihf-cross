workspace(name = "onnxruntime-arm-musleabihf-cross")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "arm32_gcc_linux_x86_64_musl",
    build_file = "//toolchain_arm32_gcc_musl:arm32_gcc_linux_x86_64_musl.BUILD",
    patches = [
        "//toolchain_arm32_gcc_musl:libtoolize.patch",
        "//toolchain_arm32_gcc_musl:aclocal.patch",
        "//toolchain_arm32_gcc_musl:aclocal_m4.patch",
        "//toolchain_arm32_gcc_musl:autom4te.patch",
    ],
    strip_prefix = "armv7-eabihf--musl--stable-2024.02-1",
    urls = ["https://toolchains.bootlin.com/downloads/releases/toolchains/armv7-eabihf/tarballs/armv7-eabihf--musl--stable-2024.02-1.tar.bz2"],
)

register_toolchains(
    "//toolchain_arm32_gcc_musl:arm32_gcc_linux_x86_64_musl",
)

git_repository(
    name = "onnxruntime",
    build_file = "//external_libs:onnxruntime.BUILD",
    patches = [
        "//external_libs:onnxruntime.patch",
        "//external_libs:onnxruntime_providers.patch",
        "//external_libs:onnxruntime_logging.patch",
        "//external_libs:onnxruntime_stacktrace.patch",
        "//external_libs:onnxruntime_common.patch",
        "//external_libs:onnxruntime_mlas.patch",
    ],
    recursive_init_submodules = True,
    remote = "https://github.com/microsoft/onnxruntime.git",
    tag = "v1.17.3",
)

git_repository(
    name = "rules_foreign_cc",
    remote = "https://github.com/bazelbuild/rules_foreign_cc.git",
    tag = "0.11.1",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies(cmake_version = "3.26.4")
