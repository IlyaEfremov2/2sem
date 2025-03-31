#include "hexagon.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

Hexagon::Hexagon(const Point& center, double radius, const Point& pointOnCircle)
    : center(center), radius(radius), pointOnCircle(pointOnCircle) {}

double Hexagon::getSideLength() const
{
    return radius;
}

double Hexagon::getArea() const
{
    return (3 * sqrt(3) * radius * radius) / 2;
}