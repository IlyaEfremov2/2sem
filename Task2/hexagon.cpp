#include "hexagon.h"
#include <cmath>
#include <stdexcept>
using namespace std;

Hexagon::Hexagon(Point& center, double radius, Point& pointOnCircle)
    : center(center), radius(radius), pointOnCircle(pointOnCircle)
{
    if (radius <= 0) 
    {
        throw invalid_argument("Радиус должен быть положительным");
    }
}

double Hexagon::getSideLength() const
{
    return radius;
}

double Hexagon::getArea() const
{
    return (3 * sqrt(3) * radius * radius) / 2.0;
}