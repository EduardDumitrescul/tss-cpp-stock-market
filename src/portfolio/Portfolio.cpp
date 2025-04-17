//
// Created by eduard on 28.03.2025.
//

#include "Portfolio.h"

Portfolio::Portfolio(): stocks(), funds(0) {
}

Portfolio::Portfolio(const Portfolio *other):
stocks(other->stocks),
funds(other->funds)
{
}

void Portfolio::addFunds(Funds funds) {
    this->funds = this->funds + funds;
}

void Portfolio::withdrawFunds(Funds funds) {
    this->funds = this->funds - funds;
}

void Portfolio::addStock(Stock stock, Quantity quantity) {
    stocks[stock.getSymbol()] += quantity;
}

void Portfolio::removeStock(Stock stock, Quantity quantity) {
    if (stocks.at(stock.getSymbol()) < quantity) {
        throw std::runtime_error("You don't have enough stocks.");
    }
    stocks[stock.getSymbol()] -= quantity;
}

Funds Portfolio::getFunds() const {
    return funds;
}

Quantity Portfolio::getStockQuantity(Stock stock) const {
    return stocks.at(stock.getSymbol());
}
