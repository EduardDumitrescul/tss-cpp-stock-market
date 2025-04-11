#include <gtest/gtest.h>

#include "TraderManager.h"

class TraderManagerTest: public testing::Test {
protected:
    const std::shared_ptr<ITraderManager> traderManager = std::make_shared<TraderManager>();
    const std::shared_ptr<const Trader> trader = std::make_shared<Trader>(Name("Edi"), Funds(1000));

    TraderManagerTest() {

    }
};

TEST_F(TraderManagerTest, Insert) {
    int numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 0);

    traderManager->insert(trader);
    numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 1);
}

TEST_F(TraderManagerTest, InsertTradersWithSameNameError) {
    EXPECT_THROW({
        traderManager->insert(trader);
        traderManager->insert(trader);
    },
        std::exception
    );
}