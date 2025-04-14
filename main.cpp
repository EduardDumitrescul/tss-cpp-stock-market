#include <iostream>

#include "src/orderBook/OrderBook.h"
#include "src/stock/Stock.h"

int main() {
    auto stock = std::make_shared<Stock>(Name("TestStock"), Symbol("TST"));
    OrderBook book(stock);
    return 0;
}
