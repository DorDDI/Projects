/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/

#include "VendingMachine.h"
#include <iostream>
using namespace std;

VendingMachine::VendingMachine(): orange(10,45) , carrot(5,50), pomegranate(4,75), counter()  
//override default constructor that build 3 DispenserType classes and one CashRegister class
{
	
}

VendingMachine::~VendingMachine()
//override default distractor
{

}

void VendingMachine::sellProduct(char item)						//get the item that need we want to buy
{
	switch (item)
	{
	case 'o':
		MakeDeal(orange,counter);								//start the MakeDeal func for orange selection 
		break;
	case 'c':
		MakeDeal(carrot, counter);								//start the MakeDeal func for carrot selection 
		break;
	case 'p':
		MakeDeal(pomegranate, counter);							//start the MakeDeal func for pomegranate selection 
		break;
	}
}

void MakeDeal(DispenserType &item, CashRegister &counter)
{
	int first_cost_input;												//varieble that will save the first input money
	if (item.getNoOfItems() != 0)										//do the deal while there is still the required items 
	{
		cout << "Please deposit " << item.getCost() << " cents"<<endl;
		cin >> first_cost_input;
		if (first_cost_input >= item.getCost())							//check if entered enough money
		{																//if yes, make the deal and deposite the enterned money
			item.makeSale();
			counter.acceptAmount(first_cost_input);
			cout << "Collect your item at the bottom and enjoy." << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
		}
		else                                                            //if not:
		{
			int second_cost_input = 0;									//varieble that will save the second input money
			cout << "Please deposit another " << (item.getCost() - first_cost_input) << " cents" << endl;
			cin >> second_cost_input;
			if (second_cost_input >= (item.getCost() - first_cost_input))        //check if entered enough money
			{															//if yes, make the deal and deposite the enterned money
				item.makeSale();
				counter.acceptAmount(first_cost_input + second_cost_input);
				cout << "Collect your item at the bottom and enjoy." << endl;
				cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
				cout << endl;
			}
			else                                                       //if not, return money and print
			{
				cout << "The amount is not enough. Collect what you deposited." << endl;
				cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
				cout << endl;
			}
		}
	}
	else
	{																	//there isnt enough items in the vending machine 
		cout << "Sorry, this item is sold out." << endl;
	}
}

