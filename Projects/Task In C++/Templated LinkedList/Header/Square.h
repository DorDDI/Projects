/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/


#ifndef __SQUARE_H					//define only once
#define __SQUARE_H

#include <iostream>
#include "Shape.h"
using namespace std;

class Square : public Shape
{
	double len;						//len of the side of the square
public:
	Square();						//override the default constractor
	Square(char*, double);			//constractor that get a color and a len of the side of the square
	void draw();					//func that draw the square with "*"
	~Square();						//override the default destractor
	double getPerimeter();			//func that override the father func that return the perimeter
	double getArea();				//func that override the father func that return the area
	void print() ;					//func that override the father func that print the square

};


#endif //__SQUARE_H