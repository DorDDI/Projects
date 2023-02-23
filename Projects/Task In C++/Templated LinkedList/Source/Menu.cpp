
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
	bool program_flag = true;
	LinkedList<Shape*> list;
	int operation = 0;									//main menu operation varieble 
	bool flag_menu = true;								//flag for the insert checking
	while (program_flag)										//flag for exit selection
	{													//print main menu
		cout << "=======================================" << endl;
		cout << "<1> Add element to the list" << endl;
		cout << "<2> Remove the last shape from list" << endl;
		cout << "<3> Print the last shape" << endl;
		cout << "<4> Exit" << endl;
		cout << "=======================================" << endl;
		cin >> operation;
		switch (operation)
		{
		case 1:											//Insert a shape to the list
		{
			cout << endl;
			flag_menu = true;
			cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle: " ;
			int operation_shape;
			cin >> operation_shape;
			switch (operation_shape)					//check which shape selected
			{
			case 1:										//the selected shape is square
			{
				while (flag_menu)
				{										//get the color and the len
					cout << "Enter square's color: ";
					char name[10];
					cin >> name;
					cout << "Enter square's side length: ";
					double len;
					cin >> len;
					try                                 //try build a square class
					{
						Square* temp_squere = new Square(name, len);
						list.insert(temp_squere);		//if succeed, add it to the list
						flag_menu = false;
					}
					catch (int number)					//exception for color error
					{
						cout << "Exception: color must be red green or blue" << endl;
						cout << "please try again" << endl;
					}
					catch (const char* string)			//exception for len error
					{
						cout << string << endl;
						cout << "please try again" << endl;
					}
				}

				break;
			}

			case 2:										//the selected shape is circle
			{
				while (flag_menu)
				{										//get the color and the radius
					cout << "Enter circle's color: ";
					char name[10];
					cin >> name;
					cout << "Enter circle's radius: ";
					double radius;
					cin >> radius;
					try                                 //try build a circle class
					{
						Circle* temp_circle = new Circle(name, radius);
						list.insert(temp_circle);		//if succeed, add it to the list
						flag_menu = false;
					}
					catch (int number)					//exception for color error
					{
						cout << "Exception: color must be red green or blue" << endl;
						cout << "please try again" << endl;
					}
					catch (const char* string)			//exception for radius error
					{
						cout << string << endl;
						cout << "please try again" << endl;
					}
				}
				break;
			}

			case 3:										//the selected shape is triangle
			{
				while (flag_menu)
				{										//get the color and the sides
					cout << "Enter Triangle's color: ";
					char name[10];
					cin >> name;
					cout << "Enter Triangle's side: ";
					double side;
					cin >> side;
					try                                 //try build a orthogonal triangle class
					{
						OrthogonalTriangle* temp_orthogonaltriangle = new OrthogonalTriangle(name, side);
						list.insert(temp_orthogonaltriangle);	//if succeed, add it to the list
						flag_menu = false;
					}
					catch (int number)					//exception for color error
					{
						cout << "Exception: color must be red green or blue" << endl;
						cout << "please try again" << endl;
					}
					catch (const char* string)			//exception for sides error
					{
						cout << string << endl;
						cout << "please try again" << endl;
					}
				}
				break;
			}

			default:									//the selected shape is not correcr
				cout << "Invalid choice" << endl;
				break;
			}
			break;
		}
		case 2:											//Delete the first shape in the list
			try 
			{
				Shape* a = list.deleteNode();
				delete a;
			}
			catch (int number)							//exception if the list is empty
			{
				cout << "Exception: The List is empty!" << endl;
				cout << "please try again" << endl;
			}
			catch (char* string)						//exception if the selected data to delete in not found
			{
				cout << string << endl;
				cout << "please try again" << endl;
			}
			break;

		case 3:											//Print the last insert element in the list
		{
			
			try
			{
				list.getTop()->print();

			}
			catch (int number)							//exception if the list is empty
			{
				cout << "Exception: List is empty!" << endl;
				cout << endl;
			}
			break;
		}

		case 4:											//exit the main manu
		{
			cout << "Goodbye!" << endl;
			program_flag = false;
			delete_list(list);
			break;
		}

		default:										//enterd wrong operation number
			cout << "Invalid selection." << endl;
			break;
		}
	}
}

void Menu::delete_list(LinkedList<Shape*>& list)
//delete the dynamic data 
{
	if (list.IsEmpty())									//check if the list is empty
		return;											//if empty do nothing
	Node<Shape*>* current_ptr = list.GetHead();			//pointer to the current node
	while (current_ptr != nullptr)						//run until we arrive to the last node
	{
		delete current_ptr->GetDataNode();				//delete the data in the node
		current_ptr = current_ptr->GetNextNode();		//set the current pointer to be the next pointer
	}										
}
