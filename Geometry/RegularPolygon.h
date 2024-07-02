#pragma once
#include "BaseFigure.h"
#include <iostream>
#include <cmath>

class RegularPolygon : public BaseFigure {
private:
    Point center;
    double sideLength;
    int numberOfSides;
    double Pi = 3.14159;
public:
    RegularPolygon(const Point& center, double sideLength, int numberOfSides)
        : center(center), sideLength(sideLength), numberOfSides(numberOfSides) {}

    double area() const override;
    double perimeter() const override;
    void print() const override;
};
