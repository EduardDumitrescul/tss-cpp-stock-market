#include <gtest/gtest.h>

#include "Portfolio.h"
#include "../stock/Stock.h"
#include "../trader/Trader.h"

class PortfolioTest: public testing::Test {
protected:
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Edi"));
    std::shared_ptr<Portfolio> portfolio = trader->getPortfolio();
    Funds funds100 = Funds(100);
    Funds funds50 = Funds(50);

    Stock stockApple = Stock(Name("Apple"), Symbol("APPL"));
    Quantity quantityApple = Quantity(10);
    Stock stockNvidia = Stock(Name("Nvidia"), Symbol("VNDA"));
    Quantity quantityNvidia = Quantity(20);
    Stock stockMicrosoft = Stock(Name("Microsoft"), Symbol("MSFT"));
};

TEST_F(PortfolioTest, DepositFunds) {
    Funds initialFunds = portfolio->getFunds();
    Funds expectedInitialFunds = Funds(0);
    EXPECT_EQ(initialFunds, expectedInitialFunds);


    portfolio->addFunds(funds100);
    Funds currentFunds = portfolio->getFunds();
    Funds expectedCurrentFunds = funds100;
    EXPECT_EQ(currentFunds, expectedCurrentFunds);

    Funds currentTraderFunds = trader->getFunds();
    EXPECT_EQ(currentTraderFunds, expectedCurrentFunds);
}

TEST_F(PortfolioTest, WithdrawFunds) {
    portfolio->addFunds(funds100);
    portfolio->withdrawFunds(funds50);
    Funds currentFunds = portfolio->getFunds();
    Funds expectedFunds = funds50;
    EXPECT_EQ(currentFunds, expectedFunds);
}

TEST_F(PortfolioTest, WithdrawFunds_ErrorOnOver) {
    portfolio->addFunds(funds50);
    EXPECT_THROW(portfolio->withdrawFunds(funds100), std::exception);
}


TEST_F(PortfolioTest, AddStock) {
    portfolio->addStock(stockApple, quantityApple);
    portfolio->addStock(stockNvidia, quantityNvidia);

    Quantity actualAppleStockQuantity = portfolio->getStockQuantity(stockApple);
    Quantity actualNvidiaStockQuantity = portfolio->getStockQuantity(stockNvidia);

    EXPECT_EQ(actualAppleStockQuantity, quantityApple);
    EXPECT_EQ(actualNvidiaStockQuantity, quantityNvidia);
}

TEST_F(PortfolioTest, AddStock_MultipleTimes) {
    portfolio->addStock(stockApple, quantityApple);
    portfolio->addStock(stockApple, quantityApple);

    Quantity actualAppleStockQuantity = portfolio->getStockQuantity(stockApple);

    EXPECT_EQ(actualAppleStockQuantity, quantityApple + quantityApple);
}

TEST_F(PortfolioTest, RemoveStock) {
    portfolio->addStock(stockApple, quantityApple);
    portfolio->removeStock(stockApple, Quantity(2));

    Quantity actualAppleStockQuantity = portfolio->getStockQuantity(stockApple);

    EXPECT_EQ(actualAppleStockQuantity, quantityApple - 2);
}

TEST_F(PortfolioTest, RemoveStock_Overdraft) {
    portfolio->addStock(stockApple, quantityApple);

    EXPECT_THROW(portfolio->removeStock(stockApple, Quantity(20)), std::exception);
}
