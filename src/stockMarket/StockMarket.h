//
// Created by eduard on 28.03.2025.
//

#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include "../orderBook/OrderBook.h"
#include "../portfolio/Portfolio.h"


class StockMarket {
    std::unordered_map<Symbol, std::shared_ptr<OrderBook>> orderBooks;
    std::unordered_map<TraderId, std::shared_ptr<Portfolio>> portfolios;

    friend class StockMarketValidator;

public:
    std::vector<Trade> placeBuyOrder(const Order &order) const;
    std::vector<Trade> placeSellOrder(const Order &order) const;

    void registerStock(const Stock& stock);
    void registerTrader(const std::shared_ptr<Trader>& trader);

    std::shared_ptr<const OrderBook> getOrderBook(const Stock& stock) const;
    std::shared_ptr<const Portfolio> getPortfolio(TraderId traderId) const;
};



#endif //STOCKMARKET_H
