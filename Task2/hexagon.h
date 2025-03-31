#pragma once
#include "point.h"
class Hexagon
{
private:
    Point center;
    double radius;
    Point pointOnCircle;

public:
    Hexagon(Point& center, double radius, Point& pointOnCircle);
    double getSideLength() const;
    double getArea() const;
};
