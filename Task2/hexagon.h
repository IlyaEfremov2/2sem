#pragma once
#include "point.h"
class Hexagon
{
private:
    Point center;
    double radius;
    Point pointOnCircle;

public:
    Hexagon(const Point& center, double radius, const Point& pointOnCircle);
    double getSideLength() const;
    double getArea() const;
};
