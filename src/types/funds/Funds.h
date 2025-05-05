//
// Created by eduard on 28.03.2025.
//

#ifndef FUNDS_H
#define FUNDS_H

#include <stdexcept>

class Funds {
    long long amount;

    void assertNotNegative() const {
        if (amount < 0) {
            throw std::invalid_argument("Funds cannot be negative. Current value: " + std::to_string(amount));
        }
    }

    void assertAtMostOneBillion() const {
        if (amount > 1000000000) {
            throw std::invalid_argument("Funds can be at most one billion. Current value: " + std::to_string(amount));
        }
    }

public:
    explicit Funds(const long long amount):
    amount(amount) {
        assertNotNegative();
        assertAtMostOneBillion();
    }

    bool operator==(const Funds &) const = default;

    Funds operator+(const Funds& funds) const {
        const Funds updatedFunds(amount + funds.amount);
        return updatedFunds;
    }

    Funds operator-(const Funds & funds) const {
        const Funds updatedFunds(amount - funds.amount);
        return updatedFunds;
    }
};

#endif //FUNDS_H
