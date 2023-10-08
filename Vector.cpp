#include "Vector.h"


void Vector::operator+=(const Vector &other) {
    this->operator=(operator+(other));
}


Vector Vector::operator+(const Vector &other) const {
    return {(int)(x + other.x), (int)(y + other.y)};
}


Vector::Vector(int x, int y, const std::pair<int, int> &restrictX, const std::pair<int, int> &restrictY) :
        Vector(
                std::clamp(x , restrictX.first, restrictX.second),
                std::clamp(y, restrictY.first, restrictY.second)
        ) {
}


Vector::Vector(int x, int y) :
        x(x), y(y){
}