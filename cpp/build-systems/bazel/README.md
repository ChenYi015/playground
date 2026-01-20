# C++ Playground - Bazel Build System

This directory demonstrates using Bazel as a build system.

## Prerequisites

```bash
# Install Bazelisk (recommended)
# macOS
brew install bazelisk

# Or install Bazel directly
brew install bazel
```

## Build Instructions

```bash
# From the cpp/ directory or project root:

# Build all C++ targets
bazel build //cpp/...

# Build specific examples
bazel build //cpp/language-features:hello
bazel build //cpp/language-features:auto
bazel build //cpp/concurrency:threads

# Run an example
bazel run //cpp/language-features:hello
bazel run //cpp/third-party-libs/boost-asio:timer1

# Run tests
bazel test //cpp/tests:factorial_test
bazel test //cpp/...
```

## Project Structure

Each subdirectory has its own BUILD.bazel file:
- `//cpp/language-features/` - C++ language feature demonstrations
- `//cpp/concurrency/` - Threading and concurrency examples
- `//cpp/io-operations/` - File I/O examples
- `//cpp/third-party-libs/boost-asio/` - Boost.Asio networking examples
- `//cpp/tests/` - Unit tests using GoogleTest

## External Dependencies

Dependencies are managed through the root MODULE.bazel file:
- Abseil C++ (for some language features)
- Boost (for networking examples)
- GoogleTest (for unit tests)

## Advantages of Bazel

- **Hermetic builds**: Reproducible across machines
- **Incremental builds**: Only rebuilds what changed
- **Remote caching**: Share build artifacts across team
- **Multi-language support**: Build C++, Go, Python, Java in one system
