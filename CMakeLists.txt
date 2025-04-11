cmake_minimum_required(VERSION 3.30)
project(tss_cpp_stock_market)

set(CMAKE_CXX_STANDARD 20)

set(IMPL_SOURCES
        src/trader/Trader.cpp
        src/trader/manager/TraderManager.cpp
        src/types/symbol/Symbol.h
        src/types/quantity/Quantity.h
        src/types/funds/Funds.h
        src/types/name/Name.h
        src/portfolio/Portfolio.cpp
)

# Test files
set(TEST_SOURCES
        hello_test.cc
        src/types/symbol/symbol_test.cc
        src/types/quantity/quantity_test.cc
        src/types/funds/funds_test.cc
        src/trader/manager/trader_manager_test.cc
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_library(tss_impl ${IMPL_SOURCES})


enable_testing()

add_executable(hello_test ${TEST_SOURCES})
target_link_libraries(hello_test
        PRIVATE
        tss_impl
        gtest_main
)


include(GoogleTest)
gtest_discover_tests(hello_test)