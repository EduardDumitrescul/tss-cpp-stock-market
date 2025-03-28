#include <gtest/gtest.h>

#include "Funds.h"

TEST(FundsTest, FundsAreNotNegative) {
    EXPECT_NO_THROW({
        Funds funds(0);
    });

    EXPECT_THROW({
        Funds funds(-1);
    },
    std::invalid_argument);

    EXPECT_THROW({
        Funds funds(-1e10);
    },
    std::invalid_argument
    );
}


TEST(FundsTest, FundsAreAtMostABillion) {
        EXPECT_NO_THROW({
        Funds funds(1e9);
    });

    EXPECT_THROW({
        Funds funds(1e9+1);
    },
    std::invalid_argument);

    EXPECT_THROW({
        Funds funds(1e10);
    },
    std::invalid_argument
    );
}