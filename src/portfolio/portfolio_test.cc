#include <gtest/gtest.h>

#include "Portfolio.h"

class PortfolioTest: public testing::Test {
protected:
    Portfolio portfolio;
    Funds funds100 = Funds(100);
    Funds funds50 = Funds(50);
};

TEST_F(PortfolioTest, DepositFunds) {
    Funds initialFunds = portfolio.getFunds();
    Funds expectedInitialFunds = Funds(0);
    EXPECT_EQ(initialFunds, expectedInitialFunds);


    portfolio.addFunds(funds100);
    Funds currentFunds = portfolio.getFunds();
    Funds expectedCurrentFunds = funds100;
    EXPECT_EQ(currentFunds, expectedCurrentFunds);
}

TEST_F(PortfolioTest, WithdrawFunds) {
    portfolio.addFunds(funds100);
    portfolio.withdrawFunds(funds50);
    Funds currentFunds = portfolio.getFunds();
    Funds expectedFunds = funds50;
    EXPECT_EQ(currentFunds, expectedFunds);
}

TEST_F(PortfolioTest, WithdrawFunds_ErrorOnOver) {
    portfolio.addFunds(funds50);
    EXPECT_THROW(portfolio.withdrawFunds(funds100), std::exception);
}
