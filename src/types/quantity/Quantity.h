//
// Created by eduard on 28.03.2025.
//

#ifndef QUANTITY_H
#define QUANTITY_H

#include <stdexcept>

class Quantity {
    long long quantity;

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
        const long long quantity = 0
    ): quantity(quantity) {
        assertNotNegative();
        assertAtMostABillion();
    }

    Quantity(const Quantity&) = default;

    bool operator==(int i) const {
        return  quantity == i;
    }

    auto operator<=>(const Quantity & quantity) const = default;

    Quantity operator-(const Quantity & quantity) const {
        return Quantity(this->quantity - quantity.quantity);
    }
    Quantity operator-(int i) const {
        return Quantity(this->quantity - i);
    }

    Quantity operator+(const Quantity & quantity) const {
        return Quantity(this->quantity + quantity.quantity);
    }

    Quantity& operator+=(const Quantity & quantity) {
        this->quantity += quantity.quantity;
        return *this;
    }

    Quantity& operator-=(const Quantity & quantity) {
        this->quantity -= quantity.quantity;
        return *this;
    }

    Quantity& operator-=(int i) {
        this->quantity -= i;
        return *this;
    }

    bool operator==(const Quantity & quantity) const = default;

    long long getValue() const {
        return quantity;
    }
};

#endif //QUANTITY_H
