//
// Created by eduard on 28.03.2025.
//

#ifndef ORDER_H
#define ORDER_H
#include <memory>

#include "../stock/Stock.h"
#include "../types/price/Price.h"
#include "../types/quantity/Quantity.h"


class Trader;

class Order {
    std::shared_ptr<const Trader> trader;
    Stock stock;
    Quantity quantity;
    Price price;

public:
    Order(
        std::shared_ptr<const Trader> trader,
        Stock stock,
        Quantity quantity,
        Price price
    );

    explicit Order(const Order* other);
    Order& operator=(const Order& other);
    bool operator==(const Order& other) const;

    Stock getStock() const;

    Price getPrice() const;

    Quantity getQuantity() const;

    void setQuantity(Quantity q);
};



#endif //ORDER_H
