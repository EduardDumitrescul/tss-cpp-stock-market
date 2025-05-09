#include <gtest/gtest.h>

#include "Order.h"
#include "../portfolio/Portfolio.h"
#include "../stock/Stock.h"
#include "../trader/Trader.h"

class OrderTest: public testing::Test {
protected:
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Alex"));
    Stock stockApple = Stock(Name("Apple"), Symbol("APPL"));
    Quantity quantityApple = Quantity(10);
    Price priceApple = Price(100);

};

TEST_F(OrderTest, OrderSuccessfullyCreated) {
    EXPECT_NO_THROW({
        Order order(trader, stockApple, quantityApple, priceApple);
    });

}
