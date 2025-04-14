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
    const Funds funds;
    std::unordered_map<Symbol, Quantity> stocks;

public:
    Portfolio();

    explicit Portfolio(const Portfolio* other);
};



#endif //PORTFOLIO_H
