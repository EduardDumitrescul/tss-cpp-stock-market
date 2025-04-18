#include <gtest/gtest.h>

#include "StockMarket.h"

class StockMarketInitializationTest: public testing::Test {
protected:
    Stock stock = Stock(Name("Apple"), Symbol("APPL"));
    std::shared_ptr<StockMarket> market = std::make_shared<StockMarket>();
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Edi"));


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

TEST_F(StockMarketInitializationTest, RegisterTrader) {
    market->registerTrader(trader);
    auto portfolio = market->getPortfolio(trader->getId());
    EXPECT_EQ(portfolio->getOwner()->getId(), trader->getId());
}

TEST_F(StockMarketInitializationTest, RegisterSameTrader_Error) {
    market->registerTrader(trader);
    EXPECT_THROW(market->registerTrader(trader), std::exception);
}

TEST_F(StockMarketInitializationTest, GetInexistentPortfolio_Error) {
    EXPECT_THROW(market->getPortfolio(trader->getId()), std::exception);
}



