//
// Created by eduard on 28.03.2025.
//

#include "Stock.h"

Stock::Stock(Name name, Symbol symbol):
name(name), symbol(symbol){

}

bool Stock::operator==(const Stock &stock) const {
    return name == stock.name && symbol == stock.symbol;
}

Stock & Stock::operator=(const Stock& other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    symbol = other.symbol;
    return *this;
}

Symbol Stock::getSymbol() const {
    return symbol;
}
