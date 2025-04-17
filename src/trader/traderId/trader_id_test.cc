#include <gtest/gtest.h>

#include "TraderId.h"

TEST(TraderIdTest, Initialization) {
    auto id1 = TraderId::get();
    auto id2 = TraderId::get();

    EXPECT_EQ(id1.getValue(), 1);
    EXPECT_EQ(id2.getValue(), 2);
}