//
// Created by eduard on 28.03.2025.
//

#ifndef ORDER_H
#define ORDER_H
#include <memory>

#include "../stock/Stock.h"
#include "../types/price/Price.h"
#include "../types/quantity/Quantity.h"


class Order {
    const std::shared_ptr<const Stock> stock;
    const Quantity quantity;
    const Price price;
};



#endif //ORDER_H
