//
// Created by alexco on 08.05.2025.
//

#include <gtest/gtest.h>

#include "App.h"
#include "../order/Order.h"

class AppTest: public testing::Test {
protected:
    App app;

};

TEST_F(AppTest, End2EndTest) {
    int x = 1;
    EXPECT_EQ(x, 1);

}
