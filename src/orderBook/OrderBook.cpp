//
// Created by eduard on 28.03.2025.
//

#include "OrderBook.h"

void OrderBook::assertOrderStockSameAsOrderBookStock(Order order) const {
    if (order.getStock() != stock) {
        throw std::invalid_argument("Order does not belong in this OrderBook - different stock");
    }
}

bool OrderBook::sellOrdersExist() const {
    return sellOrders.empty() == false;
}

bool OrderBook::buyOrdersExist() const {
    return buyOrders.empty() == false;
}

Order OrderBook::bestSellOrder() const {
    return sellOrders.top();
}

Order OrderBook::bestBuyOrder() const {
    return buyOrders.top();
}

bool OrderBook::orderMatchExists() const {
    return bestSellOrder().getPrice() <= bestBuyOrder().getPrice();
}

void OrderBook::removeBestSellOrder() {
    sellOrders.pop();
}

void OrderBook::removeBestBuyOrder() {
    buyOrders.pop();
}

void OrderBook::matchOrders() {
    while (
        sellOrdersExist()
        && buyOrdersExist()
        && orderMatchExists()
    ) {
        Order sellOrder = bestSellOrder();
        Order buyOrder = bestBuyOrder();

        removeBestSellOrder();
        removeBestBuyOrder();

        if (sellOrder.getQuantity() > buyOrder.getQuantity()) {
            Quantity remainingQuantity = sellOrder.getQuantity() - buyOrder.getQuantity();
            sellOrder.setQuantity(remainingQuantity);
            addSellOrder(sellOrder);
        }
        else if (buyOrder.getQuantity() > sellOrder.getQuantity()) {
            Quantity remainingQuantity = buyOrder.getQuantity() - sellOrder.getQuantity();
            buyOrder.setQuantity(remainingQuantity);
            addBuyOrder(buyOrder);
        }
    }
}

OrderBook::OrderBook(Stock stock):
stock(stock){

}

void OrderBook::addBuyOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    buyOrders.push(order);
    matchOrders();
}

void OrderBook::addSellOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    sellOrders.push(order);
    matchOrders();
}

std::vector<Order> OrderBook::getBuyOrders() const {
    std::priority_queue<Order, std::vector<Order>, BuyOrderComparator> tempQueue = buyOrders;
    std::vector<Order> result;
    while (!tempQueue.empty()) {
        result.push_back(tempQueue.top());
        tempQueue.pop();
    }
    return result;
}

std::vector<Order> OrderBook::getSellOrders() const {
    std::priority_queue<Order, std::vector<Order>, SellOrderComparator> tempQueue = sellOrders;
    std::vector<Order> result;
    while (!tempQueue.empty()) {
        result.push_back(tempQueue.top());
        tempQueue.pop();
    }
    return result;
}
