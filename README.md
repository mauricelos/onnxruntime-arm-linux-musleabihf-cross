
# ONNX Runtime for ARMv7

This repository contains the necessary files and instructions to build ONNX Runtime for ARMv7 architecture using a Bootlin musl toolchain. The setup is specifically tailored for a musleabihf (musl libc, EABI, hard-float) environment, providing an optimized runtime for machine learning models on ARM-based devices.

## Prerequisites

- Python 3

## Getting Started

### Clone the Repository

```sh
git clone https://github.com/mauricelos/onnxruntime-arm-linux-musleabihf-cross.git
cd onnxruntime-arm-linux-musleabihf-cross
```

### Build ONNX Runtime

Build the ONNX Runtime Library using Bazel with Bootlin musl toolchain:

```sh
python3 bazelisk/bazelisk.py build //:onnxruntime_test --platforms=//toolchain_arm32_gcc_musl --compilation_mode=opt
```

Alternatively, since this project was developed with [`VS Code`](https://code.visualstudio.com/) it has VS Code specific functionalities like starting the build from VS Code Tasks. Build tasks can be selected/started for execution via <kbd>ctrl</kbd> + <kbd>shift</kbd> + <kbd>B</kbd> on Windows and Linux and via <kbd>command</kbd> + <kbd>shift</kbd> + <kbd>B</kbd> on MacOS.

## Directory Structure

- `.github/workflows`: GitHub Actions workflows for CI/CD.
- `.vscode`: VSCode configuration files.
- `bazelisk`: Bazelisk submodule.
- `external_libs`: BUILD file for onnxruntime.
- `test`: Code to test if ONNX Runtime works.
- `toolchain_arm32_gcc_musl`: Toolchain files for ARMv7 musl.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- [ONNX Runtime](https://github.com/microsoft/onnxruntime)
- [Toolchains Bootlin](https://toolchains.bootlin.com/)

## Contact

For any questions or issues, please open an issue on this repository.

---
