cmake_minimum_required(VERSION 3.20)
project(CppPlayground CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Language Features Examples
add_executable(hello language-features/hello.cc)
add_executable(auto language-features/auto.cc)
add_executable(foreach language-features/foreach.cc)
add_executable(shared_ptr language-features/shared_ptr.cc)
add_executable(shared_ptr2 language-features/shared_ptr2.cc)
add_executable(shared_ptr3 language-features/shared_ptr3.cc)
add_executable(optional language-features/optional.cc)
add_executable(left_right_reference language-features/left_right_reference.cc)
add_executable(default_parameter language-features/default_parameter.cc)
add_executable(explicit language-features/explicit.cc)
add_executable(static_member language-features/static_member.cc)
add_executable(function language-features/function.cc)
add_executable(function2 language-features/function2.cc)
add_executable(function3 language-features/function3.cc)
add_executable(function4 language-features/function4.cc)

# Lambda requires Abseil (optional dependency)
# Uncomment if you have Abseil installed
# find_package(absl REQUIRED)
# add_executable(lambda language-features/lambda.cc)
# target_link_libraries(lambda absl::strings)

# Concurrency Examples
add_executable(threads concurrency/threads.cc)

# I/O Operations Examples
add_executable(iostream io-operations/iostream.cc)
add_executable(fstream io-operations/fstream.cc)

# Boost.Asio Examples (requires Boost)
find_package(Boost COMPONENTS system QUIET)
if(Boost_FOUND)
    message(STATUS "Boost found, building Boost.Asio examples")
    
    add_executable(timer1 third-party-libs/boost-asio/timer1.cc)
    target_link_libraries(timer1 Boost::system)
    
    add_executable(timer2 third-party-libs/boost-asio/timer2.cc)
    target_link_libraries(timer2 Boost::system)
    
    add_executable(timer3 third-party-libs/boost-asio/timer3.cc)
    target_link_libraries(timer3 Boost::system)
    
    add_executable(timer4 third-party-libs/boost-asio/timer4.cc)
    target_link_libraries(timer4 Boost::system)
    
    add_executable(timer5 third-party-libs/boost-asio/timer5.cc)
    target_link_libraries(timer5 Boost::system)
    
    add_executable(daytime1 third-party-libs/boost-asio/daytime1.cc)
    target_link_libraries(daytime1 Boost::system)
    
    add_executable(daytime2 third-party-libs/boost-asio/daytime2.cc)
    target_link_libraries(daytime2 Boost::system)
    
    add_executable(sync_client third-party-libs/boost-asio/sync_client.cc)
    target_link_libraries(sync_client Boost::system)
    
    add_executable(sync_server third-party-libs/boost-asio/sync_server.cc)
    target_link_libraries(sync_server Boost::system)
else()
    message(STATUS "Boost not found, skipping Boost.Asio examples")
endif()

# Tests (requires GoogleTest)
enable_testing()
find_package(GTest QUIET)
if(GTest_FOUND)
    message(STATUS "GoogleTest found, building tests")
    
    add_library(factorial tests/factorial.cc tests/factorial.h)
    
    add_executable(factorial_test tests/factorial_test.cc)
    target_link_libraries(factorial_test factorial GTest::gtest_main)
    
    include(GoogleTest)
    gtest_discover_tests(factorial_test)
else()
    message(STATUS "GoogleTest not found, skipping tests")
endif()
