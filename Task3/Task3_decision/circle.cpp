#include "circle.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

Circle::Circle(const Point& center, unsigned int radius)
    : center(center), radius(radius) {
    validateRadius();
}

Circle::Circle(unsigned int x, unsigned int y, unsigned int radius)
    : center(x, y), radius(radius) {
    validateRadius();
}

void Circle::validateRadius() const {
    if (radius == 0) {
        throw std::invalid_argument("");
    }

    if (center.getX() < radius || center.getY() < radius ||
        center.getX() + radius > max_coord ||
        center.getY() + radius > max_coord) {
        throw std::out_of_range("выход за пределы");
    }
}

Point Circle::getCenter() const { return center; }
unsigned int Circle::getRadius() const { return radius; }

double Circle::getArea() const {
    return radius * radius;
}

double Circle::getPerimeter() const {
    return 2 *  radius;
}

bool Circle::contains(const Point& point) const {
    int dx = static_cast<int>(point.getX()) - static_cast<int>(center.getX());
    int dy = static_cast<int>(point.getY()) - static_cast<int>(center.getY());
    return (dx * dx + dy * dy) <= static_cast<int>(radius * radius);
}

std::string Circle::toString() const {
    std::ostringstream oss;
    oss << "круг с центром в точке " << center << " и радиусом " << radius;
    return oss.str();
}

Circle Circle::readFromStream() {
    Point center;
    unsigned int radius;

    std::cout << "ввод круга (формат: (x,y) радиус): ";
    std::cin >> center >> radius;

    return Circle(center, radius);
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    Point center;
    unsigned int radius;

    if (is >> center >> radius) {
        circle = Circle(center, radius);
    }

    return is;
}