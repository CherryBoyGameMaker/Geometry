#include "RegularPolygon.h"



double RegularPolygon::area() const {
    return (numberOfSides * sideLength * sideLength) / (4 * tan(Pi / numberOfSides));
}

double RegularPolygon::perimeter() const {
    return numberOfSides * sideLength;
}

void RegularPolygon::print() const {
    std::cout << "RegularPolygon: Center (" << center.x << ", " << center.y
        << "), side length " << sideLength
        << ", number of sides " << numberOfSides << "\n";
}
