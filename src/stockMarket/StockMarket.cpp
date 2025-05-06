//
// Created by eduard on 28.03.2025.
//

#include "StockMarket.h"

#include "services/TradeSettlementService.h"
#include "validators/StockMarketValidator.h"

std::vector<Trade> StockMarket::placeBuyOrder(const Order &order) const {
    StockMarketValidator::assertPortfolioForTraderIdExists(*this, order.getTrader()->getId());
    StockMarketValidator::assertOrderBookForStockExists(*this, order.getStock());

    auto trades = this->orderBooks.at(order.getStock().getSymbol())->addBuyOrder(order);
    TradeSettlementService::applyTrades(trades);
    return trades;
}

std::vector<Trade> StockMarket::placeSellOrder(const Order &order) const {
    StockMarketValidator::assertPortfolioForTraderIdExists(*this, order.getTrader()->getId());
    StockMarketValidator::assertOrderBookForStockExists(*this, order.getStock());

    auto trades = this->orderBooks.at(order.getStock().getSymbol())->addSellOrder(order);
    TradeSettlementService::applyTrades(trades);
    return trades;
}

void StockMarket::registerStock(const Stock& stock) {
    StockMarketValidator::assertOrderBookForStockDoesNotExist(*this, stock);
    orderBooks.insert({stock.getSymbol(), std::make_shared<OrderBook>(stock)});
}

void StockMarket::registerTrader(const std::shared_ptr<Trader>& trader) {
    StockMarketValidator::assertTraderIsNotRegistered(*this, trader);
    portfolios.insert({trader->getId(), trader->portfolio});
}

std::shared_ptr<const OrderBook> StockMarket::getOrderBook(const Stock& stock) const {
    StockMarketValidator::assertOrderBookForStockExists(*this, stock);
    return orderBooks.at(stock.getSymbol());
}

std::shared_ptr<const Portfolio> StockMarket::getPortfolio(const TraderId traderId) const {
    StockMarketValidator::assertPortfolioForTraderIdExists(*this, traderId);
    return portfolios.at(traderId);
}

