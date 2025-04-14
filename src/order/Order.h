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
    const std::shared_ptr<const Trader> trader;
    const std::shared_ptr<const Stock> stock;
    const Quantity quantity;
    const Price price;

public:
    Order(
        std::shared_ptr<const Trader> trader,
        std::shared_ptr<const Stock> stock,
        Quantity quantity,
        Price price
    );

    explicit Order(const Order* other);

    Stock getStock() const;
};



#endif //ORDER_H
