
#include "myQueue.h"
#include "Set.h"
#include <iostream>
using namespace std;

class Menu
{

public:
	Menu();					//override the defult constructor
	~Menu();				//override the defult destructor
	void mainMenu();		//run the main menu func
	void setMenu();			//run the set menu func
	void queueMenu();		//run the queue menu func
};