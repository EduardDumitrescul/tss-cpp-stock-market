#include <gtest/gtest.h>

#include "StockMarket.h"

class StockMarketInitializationTest: public testing::Test {
protected:
    Stock stock = Stock(Name("Apple"), Symbol("APPL"));
    std::shared_ptr<StockMarket> market = std::make_shared<StockMarket>();

    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Edi"));
    std::shared_ptr<Trader> trader2 = std::make_shared<Trader>(Name("Alex"));

    std::shared_ptr<Portfolio> portfolio = trader->getPortfolio();
    std::shared_ptr<Portfolio> portfolio2 = trader2->getPortfolio();

    Quantity buyQuantity = Quantity(100);
    Quantity sellQuantity = Quantity(200);

    Price buyPrice = Price(200);
    Price sellPrice = Price(100);

    void SetUp() override {
        trader->depositFunds(Funds(10e7));
        trader2->depositFunds(Funds(10e7));
    }
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

TEST_F(StockMarketInitializationTest, PlaceOrders) {
    market->registerStock(stock);
    market->registerTrader(trader);
    market->registerTrader(trader2);
    portfolio2->addStock(stock, sellQuantity);

    auto initialFundsBuyer = portfolio->getFunds();
    auto initialFundsSeller = portfolio->getFunds();

    Order order(trader, stock, buyQuantity, buyPrice);
    Order order2(trader2, stock, sellQuantity, sellPrice);

    auto trades = market->placeBuyOrder(order);
    EXPECT_TRUE(trades.empty());

    // verify trade details
    auto trades2 = market->placeSellOrder(order2);
    auto tradeQuantity = std::min(sellQuantity, buyQuantity);
    EXPECT_EQ(trades2.size(), 1);
    EXPECT_EQ(trades2[0].getQuantity(), tradeQuantity);
    EXPECT_EQ(trades2[0].getPrice(), sellPrice);

    auto tradeFunds = trades2[0].getTotalFunds();
    // verify portfolio changes
    EXPECT_EQ(portfolio->getFunds(), initialFundsBuyer - tradeFunds);
    EXPECT_EQ(portfolio2->getFunds(), initialFundsSeller + tradeFunds);

    // verify buyer now has stock holdings
    EXPECT_EQ(portfolio->getStockQuantity(stock), buyQuantity);
    EXPECT_EQ(portfolio2->getStockQuantity(stock), sellQuantity - buyQuantity);
}

