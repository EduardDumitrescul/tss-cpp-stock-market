//
// Created by eduard on 10.04.2025.
//

#ifndef TRADERMANAGER_H
#define TRADERMANAGER_H
#include <memory>
#include <vector>

#include "ITraderManager.h"
#include "../Trader.h"
#include "../traderId/TraderId.h"


class TraderManager final : public ITraderManager {
    std::unordered_map<TraderId, std::shared_ptr<Trader>> traders;

    bool traderWithNameExists(const Name& name) const;

public:
    std::shared_ptr<const Trader> insert(Name name) override;

    std::vector<std::shared_ptr<const Trader>> getTraders() const override;

    ~TraderManager() override;
};



#endif //TRADERMANAGER_H
