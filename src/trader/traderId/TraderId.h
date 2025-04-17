//
// Created by eduard on 17.04.2025.
//

#ifndef TRADERID_H
#define TRADERID_H

class TraderId {
    static int counter;
    const int id;

    explicit TraderId(int id): id(id) {}
public:
    int getValue() const {
        return id;
    }

    static TraderId get() {
        counter ++;
        return TraderId(counter);
    }
};

int TraderId::counter = 0;

#endif //TRADERID_H
