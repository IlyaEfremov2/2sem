#pragma once
#include "shape.h"

class Circle : public Shape {
private:
    Point center;
    unsigned int radius;

    void validateRadius() const;

public:
    Circle(const Point& center, unsigned int radius);
    Circle(unsigned int x, unsigned int y, unsigned int radius);

    Point getCenter() const;
    unsigned int getRadius() const;

    double getArea() const override;
    double getPerimeter() const override;
    bool contains(const Point& point) const override;
    std::string toString() const override;

    static Circle readFromStream();
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};