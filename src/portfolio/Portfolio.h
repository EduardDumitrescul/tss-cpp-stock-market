//
// Created by eduard on 28.03.2025.
//

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <unordered_map>

#include "../types/funds/Funds.h"
#include "../types/quantity/Quantity.h"
#include "../types/symbol/Symbol.h"


class Portfolio {
    Funds funds;
    std::unordered_map<Symbol, Quantity> stocks;

public:
    Portfolio();

    explicit Portfolio(const Portfolio* other);

    void addFunds(Funds funds);
    void withdrawFunds(Funds funds);

    Funds getFunds() const;
};



#endif //PORTFOLIO_H
