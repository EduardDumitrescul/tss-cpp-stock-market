#include <gtest/gtest.h>

#include "Quantity.h"

TEST(QuantityTest, isNotNegative) {
    ASSERT_NO_THROW(
        {
            Quantity q(0);
        }
    );
    ASSERT_THROW(
        {
            Quantity q(-1);
        },
        std::invalid_argument
    );
}


TEST(QuantityTest, AtMostABillion) {
    ASSERT_NO_THROW(
        {
            Quantity q(1000000000);
        }
    );
    ASSERT_THROW(
        {
            Quantity q(1000000001);
        },
        std::invalid_argument
    );
}