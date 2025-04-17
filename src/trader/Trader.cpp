//
// Created by eduard on 28.03.2025.
//

#include "Trader.h"

Trader::Trader(const Name &name):
id(TraderId::get()),
name(name) {
    portfolio = std::make_shared<Portfolio>(std::make_shared<Trader>(*this));
}

Name Trader::getName() const {
    return name;
}

Funds Trader::getFunds() const {
    return portfolio->getFunds();
}

TraderId Trader::getId() const {
    return id;
}

Trader::Trader(const Trader *other):
id(TraderId::get()),
name(other->name),
portfolio(std::make_shared<Portfolio>(*other->portfolio))
{

}

void Trader::depositFunds(Funds funds) {
    portfolio->addFunds(funds);
}

void Trader::withdrawFunds(Funds funds) {
    portfolio->withdrawFunds(funds);
}
