#include "vector.hpp"


Vector::Vector(int x, int y) : x(x), y(x) {}

Vector Vector::operator+(Vector &other) {
    return Vector(this->x + other.x, this->y + other.y);
}

