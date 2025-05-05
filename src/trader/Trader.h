//
// Created by eduard on 28.03.2025.
//

#ifndef TRADER_H
#define TRADER_H

#include <memory>

#include "../portfolio/Portfolio.h"
#include "../types/funds/Funds.h"
#include "../types/name/Name.h"
#include "traderId/TraderId.h"

class Trader {
    friend class StockMarket;

    TraderId id;
    Name name;
    std::shared_ptr<Portfolio> portfolio;
public:
    explicit Trader(const Name &name);

    explicit Trader(const Trader* other);

    void depositFunds(Funds funds) const;
    void withdrawFunds(Funds funds) const;

    Name getName() const;
    Funds getFunds() const;
    std::shared_ptr<Portfolio> getPortfolio() const;
    TraderId getId() const;
};



#endif //TRADER_H
