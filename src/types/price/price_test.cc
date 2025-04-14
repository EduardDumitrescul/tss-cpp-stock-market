#include <gtest/gtest.h>

#include "Price.h"

TEST(PriceTest, ReturnDecimalFormat) {
    EXPECT_EQ(Price(123456789).toString(), "123.456789");
    EXPECT_EQ(Price(123).toString(), "0.000123");
    EXPECT_EQ(Price(12300000).toString(), "12.300000");
}