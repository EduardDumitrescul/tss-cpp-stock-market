//
// Created by eduard on 10.04.2025.
//

#include "TraderManager.h"

std::shared_ptr<const Trader> TraderManager::insert(Name name) {
    if (traderWithNameExists(name)) {
        throw std::invalid_argument("Trader with name " + name.toString() + " already exists");
    }
    auto trader = std::make_shared<Trader>(name);
    traders.insert({trader->getId(), trader});
    return trader;
}

bool TraderManager::traderWithNameExists(const Name& name) const {
    for (const auto& [id, trader]: traders) {
        if (trader->getName() == name) {
            return true;
        }
    }
    return false;
}


std::vector<std::shared_ptr<const Trader>> TraderManager::getTraders() const {
    std::vector<std::shared_ptr<const Trader>> result;
    result.reserve(traders.size());

    for (const auto& [id, trader]: traders) {
        result.push_back(std::const_pointer_cast<const Trader>(trader));
    }

    return result;
}

TraderManager::~TraderManager() = default;
