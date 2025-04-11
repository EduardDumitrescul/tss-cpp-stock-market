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
    const Funds funds;
public:
    Trader(const Name &name, const Funds& funds);

    Name getName() const;

    explicit Trader(const Trader* other);
};



#endif //TRADER_H
