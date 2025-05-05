#include <gtest/gtest.h>

#include "Order.h"
#include "../portfolio/Portfolio.h"
#include "../stock/Stock.h"
#include "../trader/Trader.h"

class OrderTest: public testing::Test {
protected:
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Alex"));
    std::shared_ptr<Portfolio> portofolio = trader->getPortfolio();
    Funds funds1000 = Funds(1000);

    Stock stockApple = Stock(Name("Apple"), Symbol("APPL"));
    Quantity quantityApple = Quantity(10);
    Price priceApple = Price(100);
    Stock stockNvidia = Stock(Name("Nvidia"), Symbol("VNDA"));
    Quantity quantityNvidia = Quantity(20);
    Price priceNvidia = Price(100);
};

TEST_F(OrderTest, TraderNeedsEnoughFunds) {
    portofolio->addFunds(funds1000);
    EXPECT_NO_THROW({
        Order order(trader, stockApple, quantityApple, priceApple);
    });
    EXPECT_THROW({
        Order order(trader, stockNvidia, quantityNvidia, priceNvidia);
    },
    std::invalid_argument);
}
