//
// Created by eduard on 28.03.2025.
//

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <unordered_map>

#include "../stock/Stock.h"
#include "../types/funds/Funds.h"
#include "../types/quantity/Quantity.h"
#include "../types/symbol/Symbol.h"


class Trader;

class Portfolio {
    std::shared_ptr<const Trader> owner;
    Funds funds;
    std::unordered_map<Symbol, Quantity> stocks;

public:
    explicit Portfolio(const std::shared_ptr <const Trader> &owner);

    explicit Portfolio(const Portfolio* other);

    void addFunds(Funds funds);
    void withdrawFunds(Funds funds);

    void addStock(const Stock& stock, Quantity quantity);
    void removeStock(const Stock& stock, Quantity quantity);


    Funds getFunds() const;
    Quantity getStockQuantity(const Stock& stock) const;
    std::shared_ptr<const Trader> getOwner() const;
};



#endif //PORTFOLIO_H
