//
// Created by eduard on 28.03.2025.
//

#include "Trader.h"

Trader::Trader(const Name &name, const Funds& funds):
name(name),
funds(funds),
portfolio(std::make_shared<Portfolio>()) {

}

Trader::Trader(const Trader *other):
name(other->name),
portfolio(std::make_shared<Portfolio>(*other->portfolio)),
funds(other->funds) {

}