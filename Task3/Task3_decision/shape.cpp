#include "shape.h"

unsigned int Shape::max_coord = 0;

void Shape::setMaxCoord(unsigned int max) {
    max_coord = max;
    Point::setMaxCoord(max);
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    os << shape.toString();
    return os;
}