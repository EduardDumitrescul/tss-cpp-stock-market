//
// Created by eduard on 16.04.2025.
//

#ifndef TRADE_H
#define TRADE_H
#include <memory>

#include "../stock/Stock.h"
#include "../types/price/Price.h"
#include "../types/quantity/Quantity.h"
#include "../types/funds/Funds.h"

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
        Quantity quantity,
        Price price
    );

    bool operator==(const Trade &other) const;

    std::shared_ptr<const Trader> getBuyer() const;

    std::shared_ptr<const Trader> getSeller() const;

    const Stock &getStock() const;

    const Quantity &getQuantity() const;

    const Price &getPrice() const;

    Funds getTotalFunds() const;
};

#endif //TRADE_H
