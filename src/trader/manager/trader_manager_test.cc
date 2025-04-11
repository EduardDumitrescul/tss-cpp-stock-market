#include <gtest/gtest.h>

#include "TraderManager.h"

class TraderManagerTest: public testing::Test {
protected:
    const std::shared_ptr<ITraderManager> traderManager = std::make_shared<TraderManager>();
    const std::shared_ptr<const Trader> trader1 = std::make_shared<Trader>(Name("Edi"), Funds(1000));
    const std::shared_ptr<const Trader> trader2 = std::make_shared<Trader>(Name("Alex"), Funds(1000));

    TraderManagerTest() = default;
};

TEST_F(TraderManagerTest, Insert) {
    int numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 0);

    traderManager->insert(trader1);
    numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 1);
}

TEST_F(TraderManagerTest, InsertTradersWithSameNameError) {
    EXPECT_NO_THROW({
        traderManager->insert(trader1);
        traderManager->insert(trader2);
    });
    EXPECT_THROW({
        traderManager->insert(trader1);
    },
        std::exception
    );
}