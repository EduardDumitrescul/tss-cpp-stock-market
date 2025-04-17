//
// Created by eduard on 10.04.2025.
//

#ifndef ITRADERMANAGER_H
#define ITRADERMANAGER_H
#include <memory>

#include "../Trader.h"

class ITraderManager {
public:
    virtual std::shared_ptr<const Trader> insert(Name name) = 0;
    virtual std::vector<std::shared_ptr<const Trader>> getTraders() const = 0;
    virtual ~ITraderManager() = default;
};

#endif //ITRADERMANAGER_H
