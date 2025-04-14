//
// Created by eduard on 28.03.2025.
//

#ifndef PRICE_H
#define PRICE_H
#include <iomanip>
#include <sstream>

class Price {
    long long price;

public:
    Price(long long price):price(price) {}

    auto operator<=>(const Price & price) const = default;

    std::string toString() const {
        long long integerPart = price / 1000000;
        long long fractionalPart = price % 1000000;

        std::ostringstream oss;
        oss << integerPart << "." << std::setw(6) << std::setfill('0') << fractionalPart;
        return oss.str();
    }
};

#endif //PRICE_H
