//
// Created by bjo on 14/11/18.
//

#include "Case.h"

Case::Case(int x, int y) : x(x), y(y) {}

int Case::getX() const {
    return x;
}

void Case::setX(int x) {
    Case::x = x;
}

int Case::getY() const {
    return y;
}

void Case::setY(int y) {
    Case::y = y;
}
