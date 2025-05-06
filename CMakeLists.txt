cmake_minimum_required(VERSION 3.30)
project(tss_cpp_stock_market)

set(CMAKE_CXX_STANDARD 20)

# Implementation sources
set(IMPL_SOURCES
        src/trade/Trade.cpp
        src/trader/Trader.cpp
        src/trader/manager/TraderManager.cpp
        src/portfolio/Portfolio.cpp
        src/order/Order.cpp
        src/stock/Stock.cpp
        src/orderBook/OrderBook.cpp
        src/stockMarket/StockMarket.cpp
        src/trader/traderId/TraderId.cpp
        src/stockMarket/validators/StockMarketValidator.cpp
        src/stockMarket/services/TradeSettlementService.cpp
)

# Test sources
set(TEST_SOURCES
        hello_test.cc
        src/types/symbol/symbol_test.cc
        src/types/quantity/quantity_test.cc
        src/types/funds/funds_test.cc
        src/trader/manager/trader_manager_test.cc
        src/orderBook/order_book_test.cc
        src/types/price/price_test.cc
        src/trader/trader_test.cc
        src/portfolio/portfolio_test.cc
        src/order/order_test.cc
        src/trader/traderId/trader_id_test.cc
        src/stockMarket/stock_market_test.cc
        src/stockMarket/services/TradeSettlementService.h
)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Implementation library
add_library(tss_impl ${IMPL_SOURCES})

add_executable(tss_main main.cpp)
target_link_libraries(tss_main PRIVATE tss_impl)


# Enable tests
enable_testing()

# Test executable
add_executable(hello_test ${TEST_SOURCES})
target_link_libraries(hello_test PRIVATE tss_impl gtest_main)

# Register tests
include(GoogleTest)
gtest_discover_tests(hello_test)
