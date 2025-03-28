cmake_minimum_required(VERSION 3.30)
project(tss_cpp_stock_market)

set(CMAKE_CXX_STANDARD 20)

# Automatically gather source files (all .cpp files under src/)
file(GLOB_RECURSE SOURCE_FILES
        src/*.cpp
)

# Automatically gather header files (all .h files under src/)
file(GLOB_RECURSE HEADER_FILES
        src/*.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello_test
        hello_test.cc
        src/types/symbol/symbol_test.cc
        src/types/quantity/quantity_test.cc
        src/types/funds/funds_test.cc
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
