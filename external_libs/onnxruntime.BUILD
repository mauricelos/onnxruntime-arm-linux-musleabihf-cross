load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all",
    srcs = glob(["**"]),
)

cmake(
    name = "onnxruntime",
    env = {
        "PATH": "$$EXT_BUILD_ROOT$$/external/arm32_gcc_linux_x86_64_musl/bin:$$PATH",
        "CMAKE_BUILD_PARALLEL_LEVEL": "4",
        "AR": "$$EXT_BUILD_ROOT$$/external/arm32_gcc_linux_x86_64_musl/arm-buildroot-linux-musleabihf/bin/ar",
        "AR_FLAGS": "--plugin=$$EXT_BUILD_ROOT$$/external/arm32_gcc_linux_x86_64_musl/libexec/gcc/arm-buildroot-linux-musleabihf/12.3.0/liblto_plugin.so",
        "ARFLAGS": "--plugin=$$EXT_BUILD_ROOT$$/external/arm32_gcc_linux_x86_64_musl/libexec/gcc/arm-buildroot-linux-musleabihf/12.3.0/liblto_plugin.so",
    },
    generate_args = [
        "-Donnxruntime_BUILD_UNIT_TESTS=OFF",
        "-Donnxruntime_ENABLE_CPUINFO=OFF",
        "-DONNX_BUILD_SHARED_LIBS=OFF",
        "-DCMAKE_SYSTEM_NAME=Linux",
        "-DCMAKE_SYSTEM_VERSION=1",
        "-DCMAKE_C_COMPILER=arm-buildroot-linux-musleabihf-gcc.br_real",
        "-DCMAKE_CXX_COMPILER=arm-buildroot-linux-musleabihf-g++.br_real",
        "-DCMAKE_AR=$$EXT_BUILD_ROOT$$/external/arm32_gcc_linux_x86_64_musl/arm-buildroot-linux-musleabihf/bin/ar",
        "-DCMAKE_SYSTEM_PROCESSOR=armv7",
        "-DCMAKE_CXX_STANDARD=20",
        "-DCMAKE_CXX_EXTENSIONS=ON",
        "-DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER",
        "-DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY",
        "-DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY",
        "-DCMAKE_FIND_ROOT_PATH_MODE_PACKAGE=ONLY",
        "-DCMAKE_EXE_LINKER_FLAGS=-lstdc++",
        "-DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY",
        "-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=TRUE",
        "-DFLATBUFFERS_BUILD_FLATC:BOOL=OFF",
    ],
    generate_crosstool_file = False,
    lib_source = ":all",
    linkopts = [
        "-pthread",
        "-latomic",
    ],
    out_static_libs = [
        "libonnxruntime_session.a",
        "libonnxruntime_optimizer.a",
        "libonnxruntime_providers.a",
        "libonnxruntime_util.a",
        "libonnxruntime_framework.a",
        "libonnxruntime_graph.a",
        "libonnxruntime_common.a",
        "libonnxruntime_flatbuffers.a",
        "libonnxruntime_mlas.a",
        "libflatbuffers.a",
        "libonnx.a",
        "libonnx_proto.a",
        "libnsync_cpp.a",
        "libabsl_bad_optional_access.a",
        "libabsl_bad_variant_access.a",
        "libabsl_int128.a",
        "libabsl_string_view.a",
        "libabsl_cordz_functions.a",
        "libabsl_cordz_handle.a",
        "libabsl_cord_internal.a",
        "libabsl_strings_internal.a",
        "libabsl_cord.a",
        "libabsl_cordz_info.a",
        "libabsl_strings.a",
        "libabsl_str_format_internal.a",
        "libabsl_hashtablez_sampler.a",
        "libabsl_raw_hash_set.a",
        "libabsl_demangle_internal.a",
        "libabsl_symbolize.a",
        "libabsl_debugging_internal.a",
        "libabsl_stacktrace.a",
        "libabsl_flags_reflection.a",
        "libabsl_flags_config.a",
        "libabsl_flags_commandlineflag_internal.a",
        "libabsl_flags_marshalling.a",
        "libabsl_flags_internal.a",
        "libabsl_flags_private_handle_accessor.a",
        "libabsl_flags_commandlineflag.a",
        "libabsl_flags_program_name.a",
        "libabsl_exponential_biased.a",
        "libabsl_civil_time.a",
        "libabsl_time.a",
        "libabsl_time_zone.a",
        "libabsl_synchronization.a",
        "libabsl_kernel_timeout_internal.a",
        "libabsl_graphcycles_internal.a",
        "libabsl_crc_cpu_detect.a",
        "libabsl_crc_internal.a",
        "libabsl_crc_cord_state.a",
        "libabsl_crc32c.a",
        "libabsl_city.a",
        "libabsl_hash.a",
        "libabsl_low_level_hash.a",
        "libabsl_log_severity.a",
        "libabsl_raw_logging_internal.a",
        "libabsl_base.a",
        "libabsl_malloc_internal.a",
        "libabsl_throw_delegate.a",
        "libabsl_spinlock_wait.a",
        "libprotobuf-lite.a",
        "libre2.a",
    ],
    postfix_script = """
        include_dir="$INSTALLDIR/include"

        find "$include_dir" -type l | while IFS= read -r file; do
            if [[ -L "$file" ]]; then
                target="$(readlink -f "$file")"
                rm "$file" && cp -a "${target}" "$file"
            fi
        done

        build_deps_dir="$BUILD_TMPDIR/_deps"
        lib_dir="$INSTALLDIR/lib"

        find $build_deps_dir -type f -name '*.a' -exec cp {} $lib_dir \\;

        find "$lib_dir" -type l -name "*.a" | while IFS= read -r file; do
            if [[ -L "$file" ]]; then
                target="$(readlink -f "$file")"
                rm "$file" && cp -a "${target}" "$file"
            fi
        done
    """,
    tags = ["requires-network"],
    visibility = ["//visibility:public"],
    working_directory = "cmake",
)
