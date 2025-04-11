#include <gtest/gtest.h>

#include "TraderManager.h"

TEST(TraderManager, Insert) {
    const std::shared_ptr<ITraderManager> traderManager = std::make_shared<TraderManager>();
    const std::shared_ptr<const Trader> trader = std::make_shared<Trader>(Name("Edi"), Funds(1000));

    int numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 0);

    traderManager->insert(trader);
    numberOfTraders = traderManager->getTraders().size();
    EXPECT_EQ(numberOfTraders, 1);
}