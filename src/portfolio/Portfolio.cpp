//
// Created by eduard on 28.03.2025.
//

#include "Portfolio.h"

Portfolio::Portfolio(
    const std::shared_ptr<const Trader> &owner
):owner(owner), funds(0), stocks() {
}

Portfolio::Portfolio(const Portfolio *other):
owner(other->owner),
funds(other->funds),
stocks(other->stocks)
{
}

void Portfolio::addFunds(const Funds funds) {
    this->funds = this->funds + funds;
}

void Portfolio::withdrawFunds(const Funds funds) {
    if (this->funds < funds) {
        throw std::runtime_error("Insufficient funds");
    }
    this->funds = this->funds - funds;
}

void Portfolio::addStock(const Stock& stock, const Quantity quantity) {
    stocks[stock.getSymbol()] += quantity;
}

void Portfolio::removeStock(const Stock& stock, const Quantity quantity) {
    if (stocks.at(stock.getSymbol()) < quantity) {
        throw std::runtime_error("You don't have enough stocks.");
    }
    stocks[stock.getSymbol()] -= quantity;
}

bool Portfolio::hasFunds(const Funds &funds) const {
    return this->funds >= funds;
}

bool Portfolio::hasStock(const Stock &stock, Quantity quantity) const {
    if (!stocks.contains(stock.getSymbol()))
        return false;
    if (stocks.at(stock.getSymbol()) < quantity)
        return false;
    return true;
}

Funds Portfolio::getFunds() const {
    return funds;
}

Quantity Portfolio::getStockQuantity(const Stock& stock) const {
    return stocks.at(stock.getSymbol());
}

std::shared_ptr<const Trader> Portfolio::getOwner() const {
    return owner;
}
