//
// Created by eduard on 28.03.2025.
//

#ifndef APP_H
#define APP_H
#include <memory>

#include "../stockMarket/StockMarket.h"
#include "../trader/manager/TraderManager.h"


class App {
    std::shared_ptr<const StockMarket> stockMarket;

    std::unique_ptr<TraderManager> traderManager;

public:

};



#endif //APP_H
