//
// Created by eduard on 28.03.2025.
//

#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include <stdexcept>

class Symbol {
    std::string symbol;

    static void assertLengthAtLeast2(const std::string& value) {
        if (value.size() < 2) {
            throw std::invalid_argument("Stock Symbol should have at least length 2");
        }
    }

    static void assertLengthAtMost5(const std::string& value) {
        if (value.size() > 5) {
            throw std::invalid_argument("Stock Symbol should have at most length 5");
        }
    }

    static void assertUppercaseAlpha(const std::string& value) {
        for (const auto& chr: value) {
            if (std::isupper(chr) == false) {
                throw std::invalid_argument("Stock Symbol should only contain uppercase letters");
            }
        }
    }

public:
    explicit Symbol(
        const std::string& name
    ): symbol(name) {
        assertLengthAtLeast2(name);
        assertLengthAtMost5(name);
        assertUppercaseAlpha(name);
    }

    Symbol(const Symbol&) = default;

    bool operator==(const Symbol& other) const {
        return symbol == other.symbol;
    }

    Symbol& operator=(const Symbol& other) {
        if (*this == other) {
            return *this;
        }
        symbol = other.symbol;
        return *this;
    }

    friend struct std::hash<Symbol>;

};

namespace std {
    template<>
    struct hash<Symbol> {
            size_t operator()(const Symbol& s) const noexcept {
                // Implement your hash function here
                // Example:
                return hash<string>()(s.symbol);
            }
        };
}


#endif //SYMBOL_H
