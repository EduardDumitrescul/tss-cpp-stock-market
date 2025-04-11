//
// Created by eduard on 28.03.2025.
//

#include "Portfolio.h"

Portfolio::Portfolio(): stocks() {
}

Portfolio::Portfolio(const Portfolio *other):
stocks(other->stocks)
{
}
