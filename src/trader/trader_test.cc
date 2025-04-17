#include <gtest/gtest.h>

#include "Trader.h"

class TraderTest: public testing::Test {
protected:
    Trader trader = Trader(Name("edi"));
    Funds funds100 = Funds(100);
    Funds funds50 = Funds(50);
};

TEST_F(TraderTest, DepositFunds) {
    Funds initialFunds = trader.getFunds();
    Funds expectedInitialFunds = Funds(0);
    EXPECT_EQ(initialFunds, expectedInitialFunds);


    trader.depositFunds(funds100);
    Funds currentFunds = trader.getFunds();
    Funds expectedCurrentFunds = funds100;
    EXPECT_EQ(currentFunds, expectedCurrentFunds);
}

TEST_F(TraderTest, WithdrawFunds) {
    trader.depositFunds(funds100);
    trader.withdrawFunds(funds50);
    Funds currentFunds = trader.getFunds();
    Funds expectedFunds = funds50;
    EXPECT_EQ(currentFunds, expectedFunds);
}

TEST_F(TraderTest, WithdrawFunds_ErrorOnOver) {
    trader.depositFunds(funds50);
    EXPECT_THROW(trader.withdrawFunds(funds100), std::exception);
}
