#include <iostream>
#include <locale>
#include "hexagon.h"
#include "point.h" 

using namespace std;

Hexagon inputHexagon();

int main()
{
    setlocale(LC_ALL, "Russian");
    Hexagon hexagon = inputHexagon();
    cout << "Длина стороны шестиугольника: " << hexagon.getSideLength() << endl;
    cout << "Площадь шестиугольника: " << hexagon.getArea() << endl;
    return 0;
}

Hexagon inputHexagon()
{
    double x, y;

    cout << "Введите координаты центра (x, y): ";
    cin >> x >> y;
    Point center = Point(x, y);
    double radius;
    cout << "Введите радиус описанной окружности: ";
    cin >> radius;
    if (radius <= 0)
    {
        throw invalid_argument("Радиус должен быть положительным");
    }
    Point pointOnCircle;
    cout << "Введите координаты точки на окружности (x y): ";
    cin >> x >> y;
    pointOnCircle = Point(x, y);
    return Hexagon(center, radius, pointOnCircle);
}

