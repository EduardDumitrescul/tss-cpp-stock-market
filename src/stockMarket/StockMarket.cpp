//
// Created by eduard on 28.03.2025.
//

#include "StockMarket.h"

void StockMarket::assertOrderBookForStockDoesNotExist(Stock stock) const {
    if (orderBooks.contains(stock.getSymbol())) {
        throw std::invalid_argument("Stock is already registered!");
    }
}

void StockMarket::assertOrderBookForStockExists(Stock stock) const {
    if (!orderBooks.contains(stock.getSymbol())) {
        throw std::invalid_argument("Stock is not registered!");
    }
}

void StockMarket::registerStock(Stock stock) {
    assertOrderBookForStockDoesNotExist(stock);
    orderBooks.insert({stock.getSymbol(), std::make_shared<OrderBook>(stock)});
}

std::shared_ptr<const OrderBook> StockMarket::getOrderBook(Stock stock) const {
    assertOrderBookForStockExists(stock);
    return orderBooks.at(stock.getSymbol());
}
