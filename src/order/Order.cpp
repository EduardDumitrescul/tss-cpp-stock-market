//
// Created by eduard on 28.03.2025.
//

#include "Order.h"

Order::Order(
    std::shared_ptr<const Trader> trader,
    std::shared_ptr<const Stock> stock,
    Quantity quantity,
    Price price
):
trader(trader),
stock(stock),
quantity(quantity),
price(price) {

}

Order::Order(const Order* other):
trader(other->trader),
stock(other->stock),
quantity(other->quantity),
price(other->price) {}
