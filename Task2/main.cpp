#include <iostream>
#include <locale>
#include "hexagon.h"
#include "point.h" 

using namespace std;

Point getPoint(string message);
double getValue(string message);

int main()
{
    setlocale(LC_ALL, "Russian");
    Point center = getPoint("Введите координаты x и y центра окружности: ");
    double radius = getValue("Введите радиус: ");
    Point pointOnCircle = getPoint("Введите координаты x и y точки: ");
    Hexagon hexagon(center, radius, pointOnCircle);
    cout << "Длина стороны шестиугольника: " << hexagon.getSideLength() << endl;
    cout << "Площадь шестиугольника: " << hexagon.getArea() << endl;
    return 0;
}

Point getPoint(string message)
{
    cout << message << endl;
    double x = 0.0;
    double y = 0.0;
    cin >> x >> y;
    if (cin.fail())
    {
        throw invalid_argument("Введено некорректное значение");
    }
    return Point(x, y);
}
double getValue(string message)
{
    cout << message << endl;
    double radius = 0.0;
    cin >> radius;
    if (cin.fail())
    {
        throw invalid_argument("Введено некорректное значение");
    }
    return radius;
}


