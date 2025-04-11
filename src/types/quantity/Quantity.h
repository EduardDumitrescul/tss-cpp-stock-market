//
// Created by eduard on 28.03.2025.
//

#ifndef QUANTITY_H
#define QUANTITY_H

#include <stdexcept>

class Quantity {
    const long long quantity;

    void assertNotNegative() const {
        if (quantity < 0) {
            throw std::invalid_argument("Quantity can't be negative. Current value: " + std::to_string(quantity));
        }
    }

    void assertAtMostABillion() const {
        if (quantity > 1000000000) {
            throw std::invalid_argument("Quantity can be at most a billion. Current value: " + std::to_string(quantity));
        }
    }
public:
    explicit Quantity(
        const long long quantity
    ): quantity(quantity) {
        assertNotNegative();
        assertAtMostABillion();
    }

    Quantity(const Quantity&) = default;
    Quantity& operator=(const Quantity&) = default;
};

#endif //QUANTITY_H
