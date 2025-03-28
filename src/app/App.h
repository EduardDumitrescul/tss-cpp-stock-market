//
// Created by eduard on 28.03.2025.
//

#ifndef APP_H
#define APP_H
#include <memory>

#include "../stockMarket/StockMarket.h"


class App {
    std::shared_ptr<const StockMarket> stockMarket;
    std::vector<const std::shared_ptr<const Portfolio>> portfolios;
    std::vector<const std::shared_ptr<const Trader>> traders;

public:

};



#endif //APP_H
