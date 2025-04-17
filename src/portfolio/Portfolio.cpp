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

Funds Portfolio::getFunds() const {
    return funds;
}
