/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/


#include <iostream>
#include "Square.h"
using namespace std;

Square::Square() :Shape()
//override the default constractor
{
	len = 0;
}

Square::Square(char* name, double len) :Shape(name)
//constractor that get a color and a len of the side of the square
{
	if (len <= 0)											//if the input of the side is not positive
		throw "Exception: The side must be positive";		//throw exception
	this->len = len;										//init the len varieble if its positive
}

Square::~Square()
//override the default destractor
{

}

double Square::getPerimeter()
//func that override the father func that return the perimeter
{
	return 4.0 * len;
}

double Square::getArea()
//func that override the father func that return the area
{
	return len * len;
}

void Square::draw()
//func that draw the square with "*"
{
	int len_int = (int)len;
	for (int i = 0; i < len_int; i++)			//run on all the rows
	{
		for (int j = 0; j < len_int; j++)		//run on all the columns
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void Square::print()
//func that override the father func that print the square
{
	cout << endl;
	cout << "Square details: color=" << color << ", side length=" << len << endl;		//print the color and the side len
	cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;			//print the area and the perimeter
	draw();																				//run the draw func
	cout << endl;
}