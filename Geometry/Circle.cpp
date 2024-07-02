#include "Circle.h"

double Circle::area() const
{
    return Pi * radius * radius;
}

double Circle::perimeter() const
{
    return Pi * radius;
}

void Circle::print() const
{
    std::cout << "Circle: Center (" << center.x << ", " << center.y
        << "), radius " << radius << std::endl;
}