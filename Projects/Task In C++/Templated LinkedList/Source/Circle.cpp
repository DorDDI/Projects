
#include <iostream>
#include "Circle.h"

using namespace std;


Circle::Circle() :Shape()
//override the defult constructor
{
	radius = 0;
}

Circle::Circle(char* name, double radius) :Shape(name)
//constractor that get a color and a radius of the circle
{
	if (radius <= 0)										//if the input of the radius is not positive
		throw "Exception: The radius must be positive!";		//throw exception
	this->radius = radius;									//init the radius varieble if its positive
}

Circle::~Circle()
//override the default destractor
{

}

double Circle::getPerimeter()
//func that override the father func that return the perimeter
{
	return 3.14 * 2 * radius;
}

double Circle::getArea()
//func that override the father func that return the area
{
	return 3.14 * radius * radius;
}

void Circle::print() 
//func that override the father func that print the circle
{
	cout << endl;
	cout << "Circle details: color=" << color << ", radius=" << radius << endl;		//print the color and the radius
	cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;			//print the area and the perimeter
}
