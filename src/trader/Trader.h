//
// Created by eduard on 28.03.2025.
//

#ifndef TRADER_H
#define TRADER_H
#include <memory>

#include "../portfolio/Portfolio.h"
#include "../types/funds/Funds.h"
#include "../types/name/Name.h"

class Trader {
    const Name name;
    const std::shared_ptr<Portfolio> portfolio;
public:
    Trader(const Name &name);

    explicit Trader(const Trader* other);

    void depositFunds(Funds funds);
    void withdrawFunds(Funds funds);

    Name getName() const;
    Funds getFunds() const;
};



#endif //TRADER_H
