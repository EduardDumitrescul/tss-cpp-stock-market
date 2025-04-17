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

    void assertOrderBookForStockDoesNotExist(Stock stock) const;
    void assertOrderBookForStockExists(Stock stock) const;
    void assertPortfolioForTraderIdExists(TraderId traderId) const;
    void assertTraderIsNotRegistered(std::shared_ptr<const Trader> trader) const;

public:
    // void placeBuyOrder(std::shared_ptr<const Trader>, Order order) const;
    // void placeSellOrder(std::shared_ptr<const Trader>, Order order) const;

    void registerStock(Stock stock);
    void registerTrader(std::shared_ptr<Trader> trader);

    std::shared_ptr<const OrderBook> getOrderBook(Stock stock) const;
    std::shared_ptr<const Portfolio> getPortfolio(TraderId traderId) const;
};



#endif //STOCKMARKET_H
