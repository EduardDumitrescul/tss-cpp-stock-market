#include <gtest/gtest.h>

#include "OrderBook.h"
#include "../trade/Trade.h"
#include "../trader/Trader.h"

class OrderBookTest: public testing::Test {
protected:
    Stock appleStock = Stock(Name("Apple"), Symbol("APPL"));
    Stock nvidiaStock = Stock(Name("Nvidia"), Symbol("NVDA"));
    OrderBook orderBook = OrderBook(appleStock);
    std::shared_ptr<Trader> trader = std::make_shared<Trader>(Name("Edi"));
    std::shared_ptr<Trader> trader2 = std::make_shared<Trader>(Name("Alex"));
};

TEST_F(OrderBookTest, AddBuyOrder) {
    auto buyOrders = orderBook.getBuyOrders();
    EXPECT_EQ(buyOrders.size(), 0);

    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(5), Price(120)));

    buyOrders = orderBook.getBuyOrders();
    EXPECT_EQ(buyOrders.size(), 2);
}

TEST_F(OrderBookTest, AddBuyOrderMantainOrder) {
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(5), Price(120)));

    auto buyOrder = orderBook.bestBuyOrder();
    EXPECT_EQ(buyOrder, Order(trader, appleStock, Quantity(5), Price(120)));
}

TEST_F(OrderBookTest, AddSellOrder) {
    auto sellOrders = orderBook.getSellOrders();
    EXPECT_EQ(sellOrders.size(), 0);

    orderBook.addSellOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addSellOrder(Order(trader, appleStock, Quantity(5), Price(120)));

    sellOrders = orderBook.getSellOrders();
    EXPECT_EQ(sellOrders.size(), 2);
}

TEST_F(OrderBookTest, AddSellOrderMantainOrder) {
    orderBook.addSellOrder(Order(trader, appleStock, Quantity(5), Price(120)));
    orderBook.addSellOrder(Order(trader, appleStock, Quantity(10), Price(100)));

    auto sellOrder = orderBook.bestSellOrder();
    EXPECT_EQ(sellOrder, Order(trader, appleStock, Quantity(10), Price(100)));
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

TEST_F(OrderBookTest, FullOrderMatching) {
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addSellOrder(Order(trader2, appleStock, Quantity(10), Price(80)));

    EXPECT_TRUE(orderBook.getSellOrders().empty());
    EXPECT_TRUE(orderBook.getBuyOrders().empty());
}

TEST_F(OrderBookTest, PartialOrderMatching) {
    orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    orderBook.addSellOrder(Order(trader2, appleStock, Quantity(3), Price(80)));

    EXPECT_TRUE(orderBook.getSellOrders().empty());
    EXPECT_TRUE(orderBook.bestBuyOrder().getQuantity() == 7);
}

TEST_F(OrderBookTest, OrderMatchingReturnsTrades) {
    auto trades1 = orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    auto trades2 = orderBook.addSellOrder(Order(trader2, appleStock, Quantity(3), Price(80)));
    EXPECT_TRUE(trades1.empty());
    std::vector expectedTrades2 =  {Trade(trader, trader2, appleStock, Quantity(3), Price(80))};
    EXPECT_EQ(trades2, expectedTrades2);
}

TEST_F(OrderBookTest, FullMatchReturnsCorrectTrade) {
    auto trades1 = orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));
    auto trades2 = orderBook.addSellOrder(Order(trader2, appleStock, Quantity(10), Price(80)));

    EXPECT_TRUE(trades1.empty());

    std::vector<Trade> expectedTrades = {
        Trade(trader, trader2, appleStock, Quantity(10), Price(80))
    };
    EXPECT_EQ(trades2, expectedTrades);
}

TEST_F(OrderBookTest, MultipleMatchesInOneGo) {
    orderBook.addSellOrder(Order(trader2, appleStock, Quantity(5), Price(80)));
    orderBook.addSellOrder(Order(trader2, appleStock, Quantity(5), Price(85)));

    auto trades = orderBook.addBuyOrder(Order(trader, appleStock, Quantity(10), Price(100)));

    std::vector<Trade> expectedTrades = {
        Trade(trader, trader2, appleStock, Quantity(5), Price(80)),
        Trade(trader, trader2, appleStock, Quantity(5), Price(85))
    };
    EXPECT_EQ(trades, expectedTrades);

    EXPECT_TRUE(orderBook.getBuyOrders().empty());
    EXPECT_TRUE(orderBook.getSellOrders().empty());
}

TEST_F(OrderBookTest, EmptyOrderBookThrowsOnBestOrderAccess) {
    EXPECT_THROW(orderBook.bestBuyOrder(), std::exception);
    EXPECT_THROW(orderBook.bestSellOrder(), std::exception);
}
