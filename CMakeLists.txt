cmake_minimum_required(VERSION 3.30)
project(tss_cpp_stock_market)

set(CMAKE_CXX_STANDARD 20)

add_executable(tss_cpp_stock_market main.cpp
        src/trader/Trader.h
        src/portfolio/Portfolio.h
        src/trader/Trader.cpp
        src/stock/Stock.cpp
        src/stock/Stock.h
        src/stockMarket/StockMarket.cpp
        src/stockMarket/StockMarket.h
        src/orderBook/OrderBook.cpp
        src/orderBook/OrderBook.h
        src/order/Order.cpp
        src/order/Order.h
        src/types/Name.h
        src/types/Symbol.h
        src/types/Quantity.h
        src/types/Price.h
        src/types/Funds.h
        src/app/App.cpp
        src/app/App.h)
