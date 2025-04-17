#include <gtest/gtest.h>

#include "StockMarket.h"

class StockMarketInitializationTest: public testing::Test {
protected:
    Stock stock = Stock(Name("Apple"), Symbol("APPL"));
    std::shared_ptr<StockMarket> market = std::make_shared<StockMarket>();


};

TEST_F(StockMarketInitializationTest, RegisterStock) {
    market->registerStock(stock);
    auto orderBook = market->getOrderBook(stock);
    EXPECT_EQ(orderBook->getStock(), stock);
}

TEST_F(StockMarketInitializationTest, RegisterSameStock_Error) {
    market->registerStock(stock);
    EXPECT_THROW(market->registerStock(stock), std::exception);
}

TEST_F(StockMarketInitializationTest, GetInexistentOrderBook_Error) {
    EXPECT_THROW(market->getOrderBook(stock), std::exception);
}



