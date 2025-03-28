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
    const std::shared_ptr<const Stock> stock;
    std::vector <const Order> sellOrders;
    std::vector <const Order> buyOrders;
public:

};



#endif //ORDERBOOK_H
