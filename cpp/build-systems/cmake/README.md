# C++ Playground - CMake Build System

This directory demonstrates using CMake as an alternative build system to Bazel.

## Prerequisites

```bash
# macOS
brew install cmake boost googletest

# Ubuntu/Debian
sudo apt-get install -y cmake libboost-all-dev libgtest-dev
```

## Build Instructions

```bash
# Create build directory
mkdir -p build-systems/cmake/build
cd build-systems/cmake/build

# Configure
cmake ../../..

# Build all targets
cmake --build .

# Run a specific example
./hello
./threads
./timer1  # if Boost is available

# Run tests
ctest
```

## Build Specific Targets

```bash
# Build only language features examples
cmake --build . --target hello
cmake --build . --target auto
cmake --build . --target lambda

# Build concurrency examples
cmake --build . --target threads

# Build I/O examples
cmake --build . --target iostream
cmake --build . --target fstream

# Build Boost.Asio examples (if available)
cmake --build . --target timer1
cmake --build . --target sync_server

# Build and run tests
cmake --build . --target factorial_test
./factorial_test
```

## Project Structure

The CMakeLists.txt builds all examples organized by topic:

- `language-features/` - C++ language feature demonstrations
- `concurrency/` - Threading and concurrency examples
- `io-operations/` - File I/O examples
- `third-party-libs/boost-asio/` - Boost.Asio networking examples
- `tests/` - Unit tests using GoogleTest
