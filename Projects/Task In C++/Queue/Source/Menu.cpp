
#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
//override the defult constructor
{

}
Menu::~Menu()
//override the defult destructor
{

}

void Menu::mainMenu()
//run the main menu func
{
	int operation = 0;									//main menu operation varieble 
	while (true)										//flag for exit selection
	{													//print main menu
		cout << "(1) Set Menu" << endl;
		cout << "(2) Integer Queue Menu" << endl;
		cout << "(3) Exit" << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:											//enter the set menu
			setMenu();
			break;
		case 2:											//enter the queue menu
			queueMenu();
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
void Menu::setMenu()
//run the set menu func
{
	int temp;											
	Set set1;											//first Set varieble
	Set set2;											//second Set varieble
	int set_operation = 0;								//set operation varieble 
	bool set_flag = true;								//flag for exit selection
	while (set_flag)
	{													//print set menue
		cout << "*** Welcome to Set Menu ***" << endl;	
		cout << "To select an item, enter" << endl;
		cout << "1 Show set 1" << endl;
		cout << "2 Show set 2" << endl;
		cout << "3 add element to set 1" << endl;
		cout << "4 add element tp set 2" << endl;
		cout << "5 Show set1 U set 2 (union)" << endl;
		cout << "6 to exit" << endl;
		cin >> set_operation;

		switch (set_operation)
		{
		case 1:									//show the first set array		
			if (set1.isEmpty())							//check if the first set array is empty	
				cout << "Set 1 is empty" << endl;		//if empty print empty
			else
				cout << set1 << endl;					//else print the set value using operator << (print)
			break;
		case 2:									//show the second set array											
			if (set2.isEmpty())							//check if the second set array is empty
				cout << "Set 2 is empty" << endl;		//if empty print empty
			else
				cout << set2 << endl;					//else print the set value using operator << (print)
			break;
		case 3:									//add a number to the first set array				
			cout << "Give a number: ";
			cin >> temp;
			set1 += temp;								//add the number using the += operator
			break;
		case 4:									//add a number to the second set array				
			cout << "Give a number: ";
			cin >> temp;
			set2 += temp;								//add the number using the += operator
			break;
		case 5:									//show the union between first set and second set
			if (set1.isEmpty() && set2.isEmpty())		//if both are empty
				cout << "The union is empty" << endl;	//print empty union
			else                                        //else print the return value of the + operator of both sets
				cout << set1 + set2 << endl;
			break;
		case 6:												//exit the set shop 
			set_flag = false;
			break;
		default:											//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}
void Menu::queueMenu()
//run the queue menu func
{
	int size_of_queue;										//queue size varieble 
	cout << "Enter the size of the queue: " ;
	cin >> size_of_queue;
	myQueue my_queue(size_of_queue);						//init the my_queue varieble constructor with the input size

	int element;											
	int queue_operation = 0;								//queue operation varieble 
	bool queue_flag = true;									//flag for exit selection
	while (queue_flag)
	{														//print queu menue
		cout << "*** Welcome to Queue Menu ***" << endl; 
		cout << "To select an item, enter" << endl;
		cout << "1 Show Queue" << endl;
		cout << "2 Insert new element" << endl;
		cout << "3 Remove element" << endl;
		cout << "4 Check the first element" << endl;
		cout << "5 to exit" << endl;
		cin >> queue_operation;

		switch (queue_operation)
		{
		case 1:										//print the queue element		
			if (my_queue.isEmpty())							//if the queue is empty print empty
				cout << "The queue is empty" << endl;
			else                                            //else print the qeueu varieble usint the << (print) operator
				cout << my_queue << endl;
			break;
		case 2:										//insert a new element to the end of the queue							
			cout << "insert new element: ";
			cin >> element;
			if (my_queue.enQueue(element))					//try to add the element
			{
				cout << "The new queue:" << endl;			//if successed, print the queue with the new element
				cout << my_queue << endl;
			}
			else                                            //if failed (the queue is full), print queue full
				cout << "Queue is full" << endl;
			break;
		case 3:										//remove the top element in the queue			
			if (my_queue.deQueue())							//try to remove the element
			{
				cout << "The new queue:" << endl;			//if successed, print the queue after the removal
				cout << my_queue << endl;
			}
			else                                            //if failed (the queue is empty), print queue empty
				cout << "Queue is empty" << endl;
			break;
		case 4:										//return the top element of the queue
			if (my_queue.isEmpty())							//if the queue is empty print empty
				cout << "Queue is empty" << endl;
			else                                            //else print the top of the queue
				cout << my_queue.peek() << endl;
			break;
		case 5:												//exit the queu managment
			queue_flag = false;
			break;

		default:											//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}