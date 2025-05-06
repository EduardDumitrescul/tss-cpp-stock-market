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

void StockMarket::applyTradesToPortfolios(const std::vector<Trade> &trades) {
    if (trades.empty()) {
        return;
    }
    for (const Trade &trade : trades) {
        const auto tradeFunds = trade.getTotalFunds();
        trade.getBuyer()->withdrawFunds(tradeFunds);
        trade.getBuyer()->portfolio->addStock(trade.getStock(), trade.getQuantity());
        trade.getSeller()->depositFunds(tradeFunds);
        trade.getSeller()->portfolio->removeStock(trade.getStock(), trade.getQuantity());
    }
}

std::vector<Trade> StockMarket::placeBuyOrder(const Order &order) const {
    assertPortfolioForTraderIdExists(order.getTrader()->getId());
    assertOrderBookForStockExists(order.getStock());

    auto trades = this->orderBooks.at(order.getStock().getSymbol())->addBuyOrder(order);
    applyTradesToPortfolios(trades);
    return trades;
}

std::vector<Trade> StockMarket::placeSellOrder(const Order &order) const {
    assertPortfolioForTraderIdExists(order.getTrader()->getId());
    assertOrderBookForStockExists(order.getStock());

    auto trades = this->orderBooks.at(order.getStock().getSymbol())->addSellOrder(order);
    applyTradesToPortfolios(trades);
    return trades;
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

