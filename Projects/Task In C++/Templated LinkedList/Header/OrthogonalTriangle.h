/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/


#ifndef __ORTHOGONALTRIANGLE_H					//define only once
#define __ORTHOGONALTRIANGLE_H

#include <iostream>
#include "Shape.h"
#include <cmath>
using namespace std;

class OrthogonalTriangle : public Shape
{
	double side_len;							//len of the sided of the orthogonal triangle
public:
	OrthogonalTriangle();						//override the default constractor
	~OrthogonalTriangle();						//override the default destractor
	OrthogonalTriangle(char*, double);			//constractor that get a color and a sides len of the orthogonal triangle
	double getPerimeter();						//func that override the father func that return the perimeter
	double getArea();							//func that override the father func that return the area
	void draw();								//func that draw the orthogonal triangle with "*"
	void print() ;								//func that override the father func that print the orthogonal triangle
};


#endif //__ORTHOGONALTRIANGLE_H