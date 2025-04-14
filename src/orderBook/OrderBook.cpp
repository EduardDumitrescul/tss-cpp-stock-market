//
// Created by eduard on 28.03.2025.
//

#include "OrderBook.h"

OrderBook::OrderBook(std::shared_ptr<const Stock> stock):
stock(stock){

}

void OrderBook::addBuyOrder(Order order) {
    buyOrders.push_back(order);
}

void OrderBook::addSellOrder(Order order) {
    sellOrders.push_back(order);
}

std::vector <Order> OrderBook::getBuyOrders() const {
    return buyOrders;
}


std::vector <Order> OrderBook::getSellOrders() const {
    return sellOrders;
}
