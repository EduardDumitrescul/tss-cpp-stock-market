//
// Created by eduard on 28.03.2025.
//

#include "App.h"

App::App() {
    stockMarket = std::make_shared<StockMarket>();
    traderManager = std::make_unique<TraderManager>();
}

StockMarket* App::getStockMarket()
{
    return stockMarket.get();
}

TraderManager* App::getTraderManager()
{
    return traderManager.get();
}
