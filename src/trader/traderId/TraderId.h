//
// Created by eduard on 17.04.2025.
//

#ifndef TRADERID_H
#define TRADERID_H

#include <functional>

class TraderId {
    static int counter;
    const int id;

    explicit TraderId(int id): id(id) {}
public:
    int getValue() const;

    bool operator==(const TraderId &) const = default;

    static TraderId get();
};

namespace std {
    template <>
    struct hash<TraderId> {
        size_t operator()(const TraderId& traderId) const noexcept {
            return hash<int>()(traderId.getValue());
        }
    };
}

#endif //TRADERID_H
