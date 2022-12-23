/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
//override default constructor and init the two classes (one VendingMachine class and one Stack class)
{

}
Menu::~Menu()
//override default distractor
{

}
void Menu::mainMenu()
{
	int operation = 0;									//main menu operation varieble 
	while(true)											//flag for exit selection
	{													//print juice menu
		cout << "(1) Fresh juice Shop" << endl;
		cout << "(2) Integer Stack" << endl;
		cout << "(3) Exit" << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:											//enter the juice menu
			shopMenu();
			break;
		case 2:											//enter the stack managment menu
			stackMenu();
			break;
		case 3:											//exit the program
			cout << "Goodbye!" << endl;					
			exit(0);
			break;
		default:										//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}
void Menu::shopMenu()
{
	VendingMachine vending_machine;							//varieble for the VendingMachine class, will be restart every time we enter this menu
	int juice_operation = 0;								//juice operation varieble 
	bool shop_flag = true;									//flag for exit selection
	while (shop_flag)
	{														
		cout << "*** Welcome to juice Shop ***" << endl;	//print juice menue
		cout << "To select an item, enter" << endl;
		cout << "1 For Orange juice" << endl;
		cout << "2 For Carrot juice" << endl;
		cout << "3 For Pomegranate" << endl;
		cout << "4 To exit" << endl;
		cin >> juice_operation;

		switch (juice_operation)
		{
		case 1:												//run the sell func for the Orange selection
			vending_machine.sellProduct('o');
			break;
		case 2:												//run the sell func for the Carrot selection
			vending_machine.sellProduct('c');
			break;
		case 3:												//run the sell func for the Pomegranate selection
			vending_machine.sellProduct('p');
			break;
		case 4:												//exit the juice shop 
			shop_flag = false;								
			cout << "Thank you!" << endl;
			break;
		default:											//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}
void Menu::stackMenu()
{
	Stack vending_stack;									//varieble for the Stack class, will be restart every time we enter this menu
	int element;											//varieble for the push func
	int stack_operation = 0;								//stack operation varieble 
	bool stack_flag = true;									//flag for exit selection
	while (stack_flag)
	{
		cout << "*** Manage your integer stack ***" << endl;  //print juice menue
		cout << "1 Push new element" << endl;
		cout << "2 Pop element" << endl;
		cout << "3 Show the first element" << endl;
		cout << "4 Check if empty" << endl;
		cout << "5 to exit" << endl;
		cin >> stack_operation;

		switch (stack_operation)
		{
		case 1:												//run the push func and input an element
			cout << "Please insert the new element: ";
			cin >> element;
			vending_stack.push(element);					//push the element in the stack
			break;
		case 2:												//run the pop func
			if (!(vending_stack.isEmpty()))					//if there is items in the stack
			{
				cout << "Removing " << vending_stack.peek() << endl;
				vending_stack.pop();						//pop the item
			}
			else                                            //else print stack empty
				cout << "Stack empty" << endl;
			break;
		case 3:												//run the peek func and return the first item in the stack
			cout << "The first element is: " << vending_stack.peek() << endl;
			break;
		case 4:												//run the isEmpty func and check if the stack is empty
			if (vending_stack.isEmpty())
				cout << "The stack is empty" << endl;
			else
				cout << "The stack is not empty" << endl;
			break;
		case 5:												//exit the stack managment
			stack_flag = false;
			cout << "Thank you!" << endl;
			break;

		default:											//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}