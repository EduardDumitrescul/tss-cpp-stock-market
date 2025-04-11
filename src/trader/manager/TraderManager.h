//
// Created by eduard on 10.04.2025.
//

#ifndef TRADERMANAGER_H
#define TRADERMANAGER_H
#include <memory>
#include <vector>

#include "ITraderManager.h"
#include "../Trader.h"


class TraderManager final : public ITraderManager {
    std::vector<std::shared_ptr<Trader>> traders;

public:
    void insert(std::shared_ptr<const Trader> trader) override;

    std::vector<std::shared_ptr<const Trader>> getTraders() const override;

    ~TraderManager() override;
};



#endif //TRADERMANAGER_H
