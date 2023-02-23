/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/


#ifndef __SHAPE_H					//define only once
#define __SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
protected:
	char* color;					//varieble of the name of the shape
public:
	Shape(char*);					//constractor that get the color of the shape
	Shape();						//override the default constractor
	~Shape();						//override the default destractor
	virtual double getPerimeter();	//calculate and return the perimeter of the shape (virtual and need to be edit in the son class)
	virtual double getArea();		//calculate and return the area of the shape (virtual and need to be edit in the son class)
	virtual void print();			//funt that print the shape variebles (virtual and need to be edit in the son class)
};


#endif //__SHAPE_H