//
// Created by eduard on 28.03.2025.
//

#include "Stock.h"

Stock::Stock(Name name, Symbol symbol):
name(name), symbol(symbol){

}

bool Stock::operator==(const std::shared_ptr<const Stock> &stock) const {
    return name == stock->name && symbol == stock->symbol;
}
