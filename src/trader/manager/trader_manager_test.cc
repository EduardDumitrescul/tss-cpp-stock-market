#include <gtest/gtest.h>

#include "TraderManager.h"

class TraderManagerTest: public testing::Test {
protected:
    const std::shared_ptr<ITraderManager> traderManager = std::make_shared<TraderManager>();

    TraderManagerTest() = default;
};

TEST_F(TraderManagerTest, Insert) {
    int numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 0);

    auto trader1 = traderManager->insert(Name("Edi"));
    numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 1);
}

TEST_F(TraderManagerTest, InsertTradersWithSameNameError) {
    EXPECT_NO_THROW({
        traderManager->insert(Name("Edi"));
        traderManager->insert(Name("Alex"));
    });
    EXPECT_THROW({
        traderManager->insert(Name("Edi"));
    },
        std::exception
    );
}