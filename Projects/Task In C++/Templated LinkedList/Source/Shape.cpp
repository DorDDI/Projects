/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/



#include <iostream>
#include <cstring>
#include "Shape.h"
using namespace std;

Shape::Shape()
//override the default constractor
{
	color = new char[10];	
}

Shape::Shape(char* color)
//constractor that get the color of the shape
{
	if (strcmp(color, "red")==0 || strcmp(color, "blue")==0 || strcmp(color, "green")==0)	//check if the color is red green or blue
	{
		this->color = new char[10];
		strcpy(this->color, color);
	}
	else                                     //the color is not correct and throw an exception
		throw - 1;
}

Shape::~Shape()
//override the default destractor
{
	delete [] color;						//delete the dynamic color varieble
}

double Shape::getPerimeter()
//calculate and return the perimeter of the shape (virtual and need to be edit in the son class)
{
	return 0;
}

double Shape::getArea()
//calculate and return the area of the shape (virtual and need to be edit in the son class)
{
	return 0;
}

void Shape::print()
//funt that print the shape variebles (virtual and need to be edit in the son class)
{

}