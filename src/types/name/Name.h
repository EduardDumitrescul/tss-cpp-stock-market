//
// Created by eduard on 28.03.2025.
//

#ifndef NAME_H
#define NAME_H
#include <string>

class Name {
    const std::string name;

public:
    explicit Name(const std::string &name): name(name) {}

    bool operator==(const Name& other) const {
        return name == other.name;
    }

    std::string toString() const {
        return name;
    }
};

#endif //NAME_H
