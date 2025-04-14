//
// Created by eduard on 28.03.2025.
//

#include "OrderBook.h"

void OrderBook::assertOrderStockSameAsOrderBookStock(Order order) const {
    if (order.getStock() != stock) {
        throw std::invalid_argument("Order does not belong in this OrderBook - different stock");
    }
}

OrderBook::OrderBook(Stock stock):
stock(stock){

}

void OrderBook::addBuyOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    buyOrders.push_back(order);
}

void OrderBook::addSellOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    sellOrders.push_back(order);
}

std::vector <Order> OrderBook::getBuyOrders() const {
    return buyOrders;
}


std::vector <Order> OrderBook::getSellOrders() const {
    return sellOrders;
}
