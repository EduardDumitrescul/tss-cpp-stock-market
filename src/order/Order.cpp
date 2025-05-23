//
// Created by eduard on 28.03.2025.
//

#include "Order.h"

void Order::assertTraderHasSufficientFunds() const {
    if (this->quantity.getValue() * this->price.getValue() > trader->getFunds().getValue()) {
        throw std::invalid_argument("Not enough funds for order");
    }
}

Order::Order(
    const std::shared_ptr<const Trader> &trader,
    const Stock& stock,
    const Quantity quantity,
    const Price price
):
trader(trader),
stock(stock),
quantity(quantity),
price(price) {}

Order::Order(const Order* other):
trader(other->trader),
stock(other->stock),
quantity(other->quantity),
price(other->price) {}

Order & Order::operator=(const Order &other) {
    if (this==&other) {
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
    && stock==other.stock
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

void Order::setQuantity(const Quantity q) {
    quantity = q;
}

std::shared_ptr<const Trader> Order::getTrader() const {
    return trader;
}
