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

std::vector<Trade> OrderBook::matchOrders() {
    std::vector <Trade> trades;
    while (
        sellOrdersExist()
        && buyOrdersExist()
        && orderMatchExists()
    ) {
        Order sellOrder = bestSellOrder();
        Order buyOrder = bestBuyOrder();

        removeBestSellOrder();
        removeBestBuyOrder();

        Quantity tradeQuantity(std::min(sellOrder.getQuantity(), buyOrder.getQuantity()));
        Price tradePrice(sellOrder.getPrice());
        Trade trade(buyOrder.getTrader(), sellOrder.getTrader(), buyOrder.getStock(), tradeQuantity, tradePrice);
        trades.push_back(trade);

        long long remainingSellQuantity = sellOrder.getQuantity().getValue() - buyOrder.getQuantity().getValue();
        if (remainingSellQuantity > 0) {
            sellOrder.setQuantity(Quantity(remainingSellQuantity));
            addSellOrder(sellOrder);
        }

        long long remainingBuyQuantity = buyOrder.getQuantity().getValue() - sellOrder.getQuantity().getValue();
        if (remainingBuyQuantity > 0) {
            buyOrder.setQuantity(Quantity(remainingBuyQuantity));
            addBuyOrder(buyOrder);
        }



    }
    return trades;
}

OrderBook::OrderBook(Stock stock):
stock(stock){

}

std::vector<Trade> OrderBook::addBuyOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    buyOrders.push(order);
    return matchOrders();
}

std::vector<Trade> OrderBook::addSellOrder(Order order) {
    assertOrderStockSameAsOrderBookStock(order);
    sellOrders.push(order);
    return matchOrders();
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
