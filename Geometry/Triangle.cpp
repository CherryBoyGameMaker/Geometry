#include "Triangle.h"
#include <cmath>
#include <algorithm>
double Triangle::area() const
{
    return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

double Triangle::perimeter() const
{
    double side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double side2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
    double side3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
    return side1 + side2 + side3;
}

void Triangle::print() const
{
    std::cout << "Triangle: Points (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y
        << "), (" << p3.x << ", " << p3.y << std::endl;
}

bool Triangle::isRight() const
{
    double side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double side2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
    double side3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));

    double sides[3] = { side1, side2, side3 };
    std::sort(sides, sides + 3);

    // �������� �� ������������� ����������� �� ������� ��������
    return std::abs(sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2]) < 1e-6;// �� 0 ������ ��� ��������� ����������� ����������
}
bool Triangle::isEquilateral() const
{
    double side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double side2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
    double side3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));

    // �������� �� ��������� ���� ������
    return std::abs(side1 - side2) < 1e-6 && std::abs(side2 - side3) < 1e-6;
}
bool Triangle::isIsosceles() const
{
    double side1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double side2 = std::sqrt(std::pow(p3.x - p2.x, 2) + std::pow(p3.y - p2.y, 2));
    double side3 = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));

    // �������� �� ��������� ���� ������
    return std::abs(side1 - side2) < 1e-6 || std::abs(side2 - side3) < 1e-6 || std::abs(side1 - side3) < 1e-6;
}
