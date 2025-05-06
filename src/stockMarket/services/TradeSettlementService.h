//
// Created by gfa on 5/6/25.
//

#ifndef TRADESETTLEMENTSERVICE_H
#define TRADESETTLEMENTSERVICE_H
#include <vector>
#include "../../trade/Trade.h"
#include "../../trader/Trader.h"
#include "../../portfolio/Portfolio.h"

class TradeSettlementService {
public:
    static void applyTrades(const std::vector<Trade>& trades);
    static bool settleTrade(const Trade& trade);
};

#endif //TRADESETTLEMENTSERVICE_H
