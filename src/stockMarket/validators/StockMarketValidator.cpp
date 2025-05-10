//
// Created by gfa on 5/6/25.
//

#include "StockMarketValidator.h"

void StockMarketValidator::assertOrderBookForStockDoesNotExist(const StockMarket& market, const Stock& stock) {
    if (market.orderBooks.contains(stock.getSymbol()) == true) {
        throw std::invalid_argument("Stock is already registered!");
    }
}

void StockMarketValidator::assertOrderBookForStockExists(const StockMarket& market, const Stock& stock) {
    if (market.orderBooks.contains(stock.getSymbol()) == false) {
        throw std::invalid_argument("Stock is not registered!");
    }
}

void StockMarketValidator::assertPortfolioForTraderIdExists(const StockMarket& market, const TraderId traderId) {
    if (market.portfolios.contains(traderId) == false) {
        throw std::invalid_argument("Portfolio has not been registered");
    }
}

void StockMarketValidator::assertTraderIsNotRegistered(const StockMarket& market, const std::shared_ptr<const Trader>& trader) {
    if (market.portfolios.contains(trader->getId()) == true) {
        throw std::invalid_argument("Trader is already registered");
    }
}