//
// Created by gfa on 5/5/25.
//

#include "Trade.h"

Trade::Trade(
        const std::shared_ptr<const Trader> &buyer,
        const std::shared_ptr<const Trader> &seller,
        const Stock &stock,
        const Quantity quantity,
        const Price price
):
buyer(buyer),
seller(seller),
stock(stock),
quantity(quantity),
price(price) {}

bool Trade::operator==(const Trade &other) const {
    return buyer == other.buyer
    && seller == other.seller
    && stock == other.stock
    && quantity == other.quantity
    && price == other.price;
}

std::shared_ptr<const Trader> Trade::getBuyer() const {
    return buyer;
}

std::shared_ptr<const Trader> Trade::getSeller() const {
    return seller;
}

const Stock &Trade::getStock() const {
    return stock;
}

const Quantity &Trade::getQuantity() const {
    return quantity;
}

Funds Trade::getTotalFunds() const {
    return Funds(quantity.getValue() * price.getValue());
}