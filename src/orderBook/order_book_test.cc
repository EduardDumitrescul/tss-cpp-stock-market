#include <gtest/gtest.h>

#include "OrderBook.h"
#include "../trader/Trader.h"

class OrderBookTest: public testing::Test {
protected:
    Stock appleStock = Stock(Name("Apple"), Symbol("APPL"));
    Stock nvidiaStock = Stock(Name("Nvidia"), Symbol("NVDA"));
    OrderBook orderBook = OrderBook(appleStock);
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Edi"), Funds(1000));

};

TEST_F(OrderBookTest, AddBuyOrder) {
    auto buyOrders = orderBook.getBuyOrders();
    EXPECT_EQ(buyOrders.size(), 0);

    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(5), Price(120)));

    buyOrders = orderBook.getBuyOrders();
    EXPECT_EQ(buyOrders.size(), 2);
}

TEST_F(OrderBookTest, AddSellOrder) {
    auto sellOrders = orderBook.getSellOrders();
    EXPECT_EQ(sellOrders.size(), 0);

    orderBook.addSellOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addSellOrder(Order(trader, appleStock, Quantity(5), Price(120)));

    sellOrders = orderBook.getSellOrders();
    EXPECT_EQ(sellOrders.size(), 2);
}

TEST_F(OrderBookTest, AddBuyOrderDifferentStock) {
    EXPECT_THROW({
        orderBook.addBuyOrder(Order(trader, nvidiaStock, Quantity(5), Price(120)));
    },
    std::exception
    );
}

TEST_F(OrderBookTest, AddSellOrderDifferentStock) {
    EXPECT_THROW({
        orderBook.addSellOrder(Order(trader, nvidiaStock, Quantity(5), Price(120)));
    },
    std::exception
    );
}