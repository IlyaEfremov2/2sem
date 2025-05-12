#pragma once
#include <iostream>

class Point {
private:
    unsigned int x;
    unsigned int y;
    static unsigned int max_coord;

public:
    Point(unsigned int x = 0, unsigned int y = 0);
    unsigned int getX() const;
    unsigned int getY() const;
    void setX(unsigned int newX);
    void setY(unsigned int newY);
    static void setMaxCoord(unsigned int max);
    void validate() const;

    friend bool operator==(const Point& lhs, const Point& rhs);
    friend bool operator!=(const Point& lhs, const Point& rhs);
    friend Point operator+(const Point& point, unsigned int value);
    friend Point operator-(const Point& point, unsigned int value);
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
};
