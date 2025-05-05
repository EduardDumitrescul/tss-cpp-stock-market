//
// Created by eduard on 28.03.2025.
//

#include "StockMarket.h"

void StockMarket::assertOrderBookForStockDoesNotExist(const Stock& stock) const {
    if (orderBooks.contains(stock.getSymbol())) {
        throw std::invalid_argument("Stock is already registered!");
    }
}

void StockMarket::assertOrderBookForStockExists(const Stock& stock) const {
    if (!orderBooks.contains(stock.getSymbol())) {
        throw std::invalid_argument("Stock is not registered!");
    }
}

void StockMarket::assertPortfolioForTraderIdExists(const TraderId traderId) const {
    if (!portfolios.contains(traderId)) {
        throw std::invalid_argument("Portfolio has not been registered");
    }
}

void StockMarket::assertTraderIsNotRegistered(const std::shared_ptr<const Trader>& trader) const {
    if (portfolios.contains(trader->getId())) {
        throw std::invalid_argument("Trader is already registered");
    }
}

void StockMarket::registerStock(const Stock& stock) {
    assertOrderBookForStockDoesNotExist(stock);
    orderBooks.insert({stock.getSymbol(), std::make_shared<OrderBook>(stock)});
}

void StockMarket::registerTrader(const std::shared_ptr<Trader>& trader) {
    assertTraderIsNotRegistered(trader);
    portfolios.insert({trader->getId(), trader->portfolio});
}

std::shared_ptr<const OrderBook> StockMarket::getOrderBook(const Stock& stock) const {
    assertOrderBookForStockExists(stock);
    return orderBooks.at(stock.getSymbol());
}

std::shared_ptr<const Portfolio> StockMarket::getPortfolio(const TraderId traderId) const {
    assertPortfolioForTraderIdExists(traderId);
    return portfolios.at(traderId);
}

