#include "point.h"
#include <stdexcept>

unsigned int Point::max_coord = 0;

Point::Point(unsigned int x, unsigned int y) : x(x), y(y) {
    validate();
}

unsigned int Point::getX() const { return x; }
unsigned int Point::getY() const { return y; }

void Point::setX(unsigned int newX) {
    x = newX;
    validate();
}

void Point::setY(unsigned int newY) {
    y = newY;
    validate();
}

void Point::setMaxCoord(unsigned int max) {
    max_coord = max;
}

void Point::validate() const {
    if (x > max_coord || y > max_coord) {
        throw std::out_of_range("Координаты превышают максимально допустимое значение");
    }
}

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}

Point operator+(const Point& point, unsigned int value) {
    return Point(point.x + value, point.y + value);
}

Point operator-(const Point& point, unsigned int value) {
    if (value > point.x || value > point.y) {
        throw std::out_of_range("отрицательная координата");
    }
    return Point(point.x - value, point.y - value);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    char ch;
    unsigned int x, y;

    if (is >> ch && ch != '(') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> x)) return is;

    if (is >> ch && ch != ',') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> y)) return is;

    if (is >> ch && ch != ')') {
        is.setstate(std::ios::failbit);
        return is;
    }

    point.x = x;
    point.y = y;
    point.validate();

    return is;
}