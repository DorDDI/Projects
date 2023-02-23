
#include "Shape.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"
#include "Square.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Menu
{

public:
	Menu();					//override the defult constructor
	~Menu();				//override the defult destructor
	void delete_list(LinkedList<Shape*>&);		//delete the dynamic data 
	void mainMenu();		//run the main menu func
};
