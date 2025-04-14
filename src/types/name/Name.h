//
// Created by eduard on 28.03.2025.
//

#ifndef NAME_H
#define NAME_H
#include <string>

class Name {
    std::string name;

public:
    explicit Name(const std::string &name): name(name) {}

    bool operator==(const Name& other) const {
        return name == other.name;
    }

    Name& operator=(const Name& other) {
        if (this == &other) {
            return *this;
        }
        name = other.name;
        return *this;
    }

    std::string toString() const {
        return name;
    }
};

#endif //NAME_H
