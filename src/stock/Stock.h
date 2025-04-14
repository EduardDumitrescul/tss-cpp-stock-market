//
// Created by eduard on 28.03.2025.
//

#ifndef STOCK_H
#define STOCK_H
#include <string>

#include "../types/name/Name.h"
#include "../types/symbol/Symbol.h"


class Stock {
    Name name;
    Symbol symbol;

public:
    Stock(Name name, Symbol symbol);
};



#endif //STOCK_H
