//
// Created by eduard on 28.03.2025.
//

#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include "../orderBook/OrderBook.h"
#include "../portfolio/Portfolio.h"


class StockMarket {
    std::unordered_map<Symbol, std::shared_ptr<OrderBook>> orderBooks;

    void assertOrderBookForStockDoesNotExist(Stock stock) const;
    void assertOrderBookForStockExists(Stock stock) const;

public:
    // void placeBuyOrder(std::shared_ptr<const Trader>, Order order) const;
    // void placeSellOrder(std::shared_ptr<const Trader>, Order order) const;

    void registerStock(Stock stock);

    std::shared_ptr<const OrderBook> getOrderBook(Stock stock) const;
};



#endif //STOCKMARKET_H
