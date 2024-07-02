#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "RegularPolygon.h"
using namespace std;
void displayMenu() {
    cout << "Choose an option:"<< endl;
    cout << "1. Create a Square" << endl;
    cout << "2. Create a Triangle" << endl;
    cout << "3. Create a Circle" << endl;
    cout << "4. Create a Regular Polygon" << endl;
    cout << "5. Exit" << endl;
}

void displayFigureMenu() {
    cout << "Choose an action:" << endl;
    cout << "1. Print Figure" << endl;
    cout << "2. Calculate Area" << endl;
    cout << "3. Calculate Perimeter" << endl;
    cout << "4. Specific Actions (for Triangle only)" << endl;
    cout << "5. Back to Main Menu" << endl;
}

int main() {
    vector<unique_ptr<BaseFigure>> figures;
    int mainChoice, figureChoice;

    do {
        displayMenu();
        cin >> mainChoice;

        if (mainChoice == 1) {
            double x, y, side;
            cout << "Enter top-left corner coordinates (x y): ";
            cin >> x >> y;
            cout << "Enter side length: ";
            cin >> side;
            figures.push_back(make_unique<Square>(Point(x, y), side));

        }
        else if (mainChoice == 2) {
            double x1, y1, x2, y2, x3, y3;
            cout << "Enter first point coordinates (x1 y1): ";
            cin >> x1 >> y1;
            cout << "Enter second point coordinates (x2 y2): ";
            cin >> x2 >> y2;
            cout << "Enter third point coordinates (x3 y3): ";
            cin >> x3 >> y3;
            figures.push_back(make_unique<Triangle>(Point(x1, y1), Point(x2, y2), Point(x3, y3)));

        }
        else if (mainChoice == 3) {
            double x, y, radius;
            cout << "Enter center coordinates (x y): ";
            cin >> x >> y;
            cout << "Enter radius: ";
            cin >> radius;
            figures.push_back(make_unique<Circle>(Point(x, y), radius));

        }
        else if (mainChoice == 4) {
            double x, y, side;
            int sides;
            cout << "Enter center coordinates (x y): ";
            cin >> x >> y;
            cout << "Enter side length: ";
            cin >> side;
            cout << "Enter number of sides: ";
            cin >> sides;
            figures.push_back(make_unique<RegularPolygon>(Point(x, y), side, sides));
        }

        if (mainChoice >= 1 && mainChoice <= 4) {
            do {
                displayFigureMenu();
                cin >> figureChoice;

                if (figureChoice == 1) {
                    figures.back()->print();
                }
                else if (figureChoice == 2) {
                    cout << "Area: " << figures.back()->area() << endl;
                }
                else if (figureChoice == 3) {
                    cout << "Perimeter: " << figures.back()->perimeter() << endl;
                }
                else if (figureChoice == 4) {
                    if (auto triangle = dynamic_cast<Triangle*>(figures.back().get())) {
                        cout << "Is Right Triangle: " << (triangle->isRight() ? "Yes" : "No") << endl;
                        cout << "Is Equilateral Triangle: " << (triangle->isEquilateral() ? "Yes" : "No") << endl;
                        cout << "Is Isosceles Triangle: " << (triangle->isIsosceles() ? "Yes" : "No") << endl;
                    }
                    else {
                        cout << "Specific actions are only available for triangles."<< endl;
                    }
                }
            } while (figureChoice != 5);
        }
    } while (mainChoice != 5);

    return 0;
}
