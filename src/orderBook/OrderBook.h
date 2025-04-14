//
// Created by eduard on 28.03.2025.
//

#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <memory>
#include <vector>

#include "../order/Order.h"
#include "../stock/Stock.h"


class OrderBook {
    Stock stock;
    std::vector <Order> sellOrders;
    std::vector <Order> buyOrders;

    void assertOrderStockSameAsOrderBookStock(Order order) const;

public:
    explicit OrderBook(Stock stock);

    void addBuyOrder(Order order);
    void addSellOrder(Order order);

    std::vector <Order> getBuyOrders() const;
    std::vector <Order> getSellOrders() const;
};



#endif //ORDERBOOK_H
