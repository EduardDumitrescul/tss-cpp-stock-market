//
// Created by eduard on 28.03.2025.
//

#include "Order.h"

Order::Order(
    std::shared_ptr<const Trader> trader,
    Stock stock,
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

Order & Order::operator=(const Order &other) {
    if (this == &other) {
        return *this;
    }
    trader = other.trader;
    stock = other.stock;
    quantity = other.quantity;
    price = other.price;
    return *this;
}

bool Order::operator==(const Order &other) const {
    return trader == other.trader
    && stock == other.stock
    && quantity == other.quantity
    && price == other.price;
}


Stock Order::getStock() const {
    return stock;
}

Price Order::getPrice() const {
    return price;
}

Quantity Order::getQuantity() const {
    return quantity;
}

void Order::setQuantity(Quantity q) {
    quantity = q;
}
