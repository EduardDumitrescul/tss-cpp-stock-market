//
// Created by eduard on 28.03.2025.
//

#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <string>
#include <unordered_map>

#include "../types/Quantity.h"
#include "../types/Symbol.h"


class Portfolio {
    std::unordered_map<const Symbol, const Quantity> stocks;

public:

};



#endif //PORTFOLIO_H
