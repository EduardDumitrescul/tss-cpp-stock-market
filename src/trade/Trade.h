//
// Created by eduard on 16.04.2025.
//

#ifndef TRADE_H
#define TRADE_H
#include <memory>

#include "../stock/Stock.h"
#include "../types/price/Price.h"
#include "../types/quantity/Quantity.h"

class Trader;

class Trade {
    std::shared_ptr<const Trader> buyer;
    std::shared_ptr<const Trader> seller;
    Stock stock;
    Quantity quantity;
    Price price;

public:
    Trade(
        const std::shared_ptr<const Trader> &buyer,
        const std::shared_ptr<const Trader> &seller,
        const Stock &stock,
        const Quantity quantity,
        const Price price
    ):
    buyer(buyer),
    seller(seller),
    stock(stock),
    quantity(quantity),
    price(price) {}

    bool operator==(const Trade &other) const {
        return buyer == other.buyer
        && seller == other.seller
        && stock == other.stock
        && quantity == other.quantity
        && price == other.price;
    }
};

#endif //TRADE_H
