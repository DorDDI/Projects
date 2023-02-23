/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/


#include <iostream>
#include "OrthogonalTriangle.h"
using namespace std;

OrthogonalTriangle::OrthogonalTriangle() :Shape()
//override the default constractor
{
	side_len = 0;
}

OrthogonalTriangle::OrthogonalTriangle(char* name, double side_len) : Shape(name)
//constractor that get a color and a sides len of the orthogonal triangle
{
	if (side_len <= 0)												//if the input of the sides is not positive
		throw "Exception: The sides must be greater then zero";		//throw exception
	this->side_len = side_len;										//init the len varieble if its positive
}

OrthogonalTriangle::~OrthogonalTriangle()
//override the default destractor
{

}

double OrthogonalTriangle::getPerimeter()
//func that override the father func that return the perimeter
{
	return sqrt(side_len * side_len * 2) + 2 * side_len;
}

double OrthogonalTriangle::getArea()
//func that override the father func that return the area
{
	return side_len * side_len / 2;
}

void OrthogonalTriangle::draw()
//func that draw the orthogonal triangle with "*"
{
	int side_len_int = (int)side_len;
	for (int i = 0; i < side_len_int; i++)				//run on all the rows
	{
		for (int j = 0; j <= i; j++)				//run on all the columns
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void OrthogonalTriangle::print()
//func that override the father func that print the orthogonal triangle
{
	cout << endl;
	cout << "OrthogonalTriangle details: color=" << color << ", side=" << side_len << endl;	//print the color and the sides len
	cout << "area= " << getArea() << ", perimeter=" << getPerimeter() << endl;					//print the area and the perimeter
	draw();																						//run the draw func
	cout << endl;																			
}