#include <iostream>
#include <locale>
#include "hexagon.h"
#include "point.h" 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Point center(0, 0);
    double radius = 5.0;
    Point pointOnCircle(radius, 0);
    Hexagon hexagon(center, radius, pointOnCircle);
    cout << "Длина стороны шестиугольника: " << hexagon.getSideLength() << endl;
    cout << "Площадь шестиугольника: " << hexagon.getArea() << endl;
    return 0;
}