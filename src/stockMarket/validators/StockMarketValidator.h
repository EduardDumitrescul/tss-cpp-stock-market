//
// Created by gfa on 5/6/25.
//

#ifndef STOCKMARKETVALIDATOR_H
#define STOCKMARKETVALIDATOR_H
#include <memory>
#include "../StockMarket.h"

class Stock;
class TraderId;
class Trader;

class StockMarketValidator {
    public:
    static void assertOrderBookForStockDoesNotExist(const StockMarket& market, const Stock& stock);
    static void assertOrderBookForStockExists(const StockMarket& market, const Stock& stock);
    static void assertPortfolioForTraderIdExists(const StockMarket& market, TraderId traderId);
    static void assertTraderIsNotRegistered(const StockMarket& market, const std::shared_ptr<const Trader>& trader);
};

#endif //STOCKMARKETVALIDATOR_H
