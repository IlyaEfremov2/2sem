#include <iostream>
#include "../Task3_decision/circle.h"
#include "../Task3_decision/point.h"
#include "../Task3_decision/shape.h"

Point getPoint(const std::string& message);
unsigned int getValue(const std::string& message);

int main() {
    try {
        unsigned int screen_width = 1920;
        unsigned int screen_height = 1080;
        unsigned int max_coord = (screen_width > screen_height) ? screen_width : screen_height;

        shape::setMaxCoord(max_coord);

        shape*shape = new Circle(getPoint("ввод координат центра (x y): "),
            getValue("ввод радиуса: "));

        std::cout << *shape << std::endl;
        std::cout << "площадь: " << shape->getArea() << std::endl;
        std::cout << "периметр: " << shape->getPerimeter() << std::endl;

        Point testPoint = getPoint("координаты точки (x y): ");
        std::cout << "Содержит ли точку " << testPoint << ": "
            << (shape->contains(testPoint) ? "ДА" : "НЕТ") << std::endl;

        delete shape;

    }
    catch (const std::exception& e) {
        std::cerr << "ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

Point getPoint(const std::string& message) {
    std::cout << message;
    unsigned int x, y;
    std::cin >> x >> y;
    if (std::cin.fail()) {
        throw std::invalid_argument("ошибка ввода");
    }
    return Point(x, y);
}

unsigned int getValue(const std::string& message) {
    std::cout << message;
    unsigned int value;
    std::cin >> value;
    if (std::cin.fail()) {
        throw std::invalid_argument("ошибка ввода");
    }
    return value;
}