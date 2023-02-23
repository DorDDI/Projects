
#ifndef __CIRCLE_H					//define only once
#define __CIRCLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
	double radius;				//size of the radius of the circle
public:
	Circle();					//override the defult constructor
	~Circle();					//override the default destractor
	Circle(char*, double);		//constractor that get a color and a radius of the circle
	double getPerimeter();		//func that override the father func that return the perimeter
	double getArea();			//func that override the father func that return the area
	void print() ;				//func that override the father func that print the circle

};


#endif //__CIRCLE_H
