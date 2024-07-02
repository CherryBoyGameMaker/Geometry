#pragma once
#include "BaseFigure.h"
#include <iostream>

class Square : public BaseFigure {
private:
    Point topLeft;
    double sideLength;

public:
    Square(const Point& topLeft, double sideLength)
        : topLeft(topLeft), sideLength(sideLength) {}
    Square(const Point& topLeft, const Point& bottomRight);
    double area() const override;

    double perimeter() const override;

    void print() const override;
};
