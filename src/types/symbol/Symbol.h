//
// Created by eduard on 28.03.2025.
//

#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>

class Symbol {
    const std::string symbol;

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
};

#endif //SYMBOL_H
