//
// Created by eduard on 28.03.2025.
//

#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <queue>
#include <vector>

#include "../order/Order.h"
#include "../stock/Stock.h"
#include "../trade/Trade.h"

class OrderBook {
    struct BuyOrderComparator {
        bool operator()(const Order& lhs, const Order& rhs) const {
            return lhs.getPrice() < rhs.getPrice(); // higher price = higher priority
        }
    };

    struct SellOrderComparator {
        bool operator()(const Order& lhs, const Order& rhs) const {
            return lhs.getPrice() > rhs.getPrice(); // lower price = higher priority
        }
    };

    Stock stock;
    std::priority_queue <Order, std::vector<Order>, SellOrderComparator> sellOrders;
    std::priority_queue <Order, std::vector<Order>, BuyOrderComparator> buyOrders;


    void assertOrderStockSameAsOrderBookStock(const Order& order) const;

    bool sellOrdersExist() const;
    bool buyOrdersExist() const;

    bool orderMatchExists() const;

    void removeBestSellOrder();
    void removeBestBuyOrder();

    std::vector<Trade> matchOrders();

public:
    explicit OrderBook(const Stock& stock);

    std::vector<Trade> addBuyOrder(const Order& order);
    std::vector<Trade> addSellOrder(const Order& order);

    Order bestSellOrder() const;
    Order bestBuyOrder() const;

    std::vector <Order> getBuyOrders() const;
    std::vector <Order> getSellOrders() const;

    Stock getStock() const;
};



#endif //ORDERBOOK_H
