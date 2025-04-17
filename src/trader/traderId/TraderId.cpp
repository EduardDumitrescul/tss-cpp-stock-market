//
// Created by eduard on 17.04.2025.
//

#include "TraderId.h"

int TraderId::counter = 0;

int TraderId::getValue() const {
    return id;
}

TraderId TraderId::get() {
    counter ++;
    return TraderId(counter);
}