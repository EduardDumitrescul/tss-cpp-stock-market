#include <gtest/gtest.h>

#include "Trader.h"

class TraderTest: public testing::Test {
protected:
    Trader trader = Trader(Name("edi"));
};

TEST_F(TraderTest, DepositFunds) {
    Funds initialFunds = trader.getFunds();
    Funds expectedInitialFunds = Funds(0);
    EXPECT_EQ(initialFunds, expectedInitialFunds);


    trader.depositFunds(Funds(100));
    Funds currentFunds = trader.getFunds();
    Funds expectedCurrentFunds = Funds(100);
    EXPECT_EQ(currentFunds, expectedCurrentFunds);
}
