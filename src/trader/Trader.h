//
// Created by eduard on 28.03.2025.
//

#ifndef TRADER_H
#define TRADER_H
#include <memory>

#include "../order/Order.h"
#include "../portfolio/Portfolio.h"
#include "../types/Funds.h"
#include "../types/Name.h"

class Trader {
    const Name name;
    const std::unique_ptr<const Portfolio> portfolio;
    const Funds funds;
public:
    const void placeBuyOrder(Order order) const;
    const void placeSellOrder(Order order) const;
};



#endif //TRADER_H
