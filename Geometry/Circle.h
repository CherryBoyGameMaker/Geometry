#pragma once
#include "BaseFigure.h"
#include <iostream>

class Circle : public BaseFigure {
private:
    Point center;
    double radius;
    double Pi = 3.14159;
public:
    Circle(const Point& center, double radius)
        : center(center), radius(radius) {}

    double area() const override;

    double perimeter() const override;

    void print() const override;
};
