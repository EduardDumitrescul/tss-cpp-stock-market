//
// Created by eduard on 28.03.2025.
//

#ifndef STOCKMARKET_H
#define STOCKMARKET_H
#include <vector>

#include "../orderBook/OrderBook.h"
#include "../portfolio/Portfolio.h"
#include "../trader/Trader.h"


class StockMarket {
    std::vector<const std::unique_ptr<const OrderBook>> orderBooks;
    std::vector<const std::shared_ptr<const Portfolio>> portfolios;

public:
    void placeBuyOrder(std::shared_ptr<const Trader>, Order order) const;
    void placeSellOrder(std::shared_ptr<const Trader>, Order order) const;
};



#endif //STOCKMARKET_H
