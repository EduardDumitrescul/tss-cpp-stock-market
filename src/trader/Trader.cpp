//
// Created by eduard on 28.03.2025.
//

#include "Trader.h"

Trader::Trader(const Name &name):
name(name),
portfolio(std::make_shared<Portfolio>()) {

}

Name Trader::getName() const {
    return name;
}

Funds Trader::getFunds() const {
    return portfolio->getFunds();
}

Trader::Trader(const Trader *other):
name(other->name),
portfolio(std::make_shared<Portfolio>(*other->portfolio))
{

}

void Trader::depositFunds(Funds funds) const {
    portfolio->addFunds(funds);
}
