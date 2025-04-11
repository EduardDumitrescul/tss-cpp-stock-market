//
// Created by eduard on 10.04.2025.
//

#include "TraderManager.h"

void TraderManager::insert(const std::shared_ptr<const Trader> trader) {
    if (traderWithNameExists(trader->getName())) {
        throw std::invalid_argument("Trader with name " + trader->getName().toString() + " already exists");
    }
    traders.push_back(std::make_shared<Trader>(*trader));
}

bool TraderManager::traderWithNameExists(const Name& name) const {
    for (const auto& trader: traders) {
        if (trader->getName() == name) {
            return true;
        }
    }
    return false;
}


std::vector<std::shared_ptr<const Trader>> TraderManager::getTraders() const {
    std::vector<std::shared_ptr<const Trader>> result;
    result.reserve(traders.size());

    for (const auto& trader : traders) {
        result.push_back(std::const_pointer_cast<const Trader>(trader));
    }

    return result;
}

TraderManager::~TraderManager() = default;
