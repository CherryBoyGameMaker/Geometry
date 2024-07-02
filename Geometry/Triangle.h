#pragma once
#include "BaseFigure.h"
#include <cmath>
#include <iostream>

class Triangle : public BaseFigure {
private:
    Point p1, p2, p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : p1(p1), p2(p2), p3(p3) {}

    double area() const override;

    double perimeter() const override;

    void print() const override;

    bool isRight() const;  
    bool isEquilateral() const;
    bool isIsosceles() const;
};
