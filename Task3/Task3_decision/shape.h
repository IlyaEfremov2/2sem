#pragma once
#include "point.h"
#include <string>

class Shape {
protected:
    static unsigned int max_coord;

public:
    virtual ~Shape() = default;

    static void setMaxCoord(unsigned int max);

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual bool contains(const Point& point) const = 0;
    virtual std::string toString() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};