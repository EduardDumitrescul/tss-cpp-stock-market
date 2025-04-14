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
