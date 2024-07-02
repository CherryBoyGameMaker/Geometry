#include "Square.h"

Square::Square(const Point& topLeft, const Point& bottomRight)
    : topLeft(topLeft) {
    // Вычисляем длину стороны квадрата
    sideLength = std::abs(bottomRight.x - topLeft.x);
}

double Square::area() const
{
    return sideLength * sideLength;
}

double Square::perimeter() const
{
    return 4 * sideLength;
}

void Square::print() const
{
    std::cout << "Square: Top-left corner (" << topLeft.x << ", " << topLeft.y
        << "), side length " << sideLength << std::endl;
}
