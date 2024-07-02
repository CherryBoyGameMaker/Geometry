#pragma once
struct Point
{
	double x, y;
	Point(double newX, double newY)
	{
		x = newX;
		y = newY;
	}
};
class BaseFigure
{
public:
	virtual double area() const = 0;      
	virtual double perimeter() const = 0; 
	virtual void print() const = 0;          
};

