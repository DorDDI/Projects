/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#include "DispenserType.h"
#include <iostream>
using namespace std;

DispenserType::DispenserType() 
//override default constructor and make an empty dispenser
{
	cost = 0;
	numberOfItems = 0;
}
DispenserType::DispenserType(int item_number, int item_cost)
// constructor that init the sum of money and the number of item by value
{
	cost = item_cost;
	numberOfItems = item_number;
}
DispenserType::~DispenserType()
//override default distractor
{

}
int DispenserType::getCost() const
{
	return cost;									//return the cost value
}
int DispenserType::getNoOfItems() const
{
	return numberOfItems;							//return the number of items value
}
void DispenserType::makeSale()
{
	numberOfItems = numberOfItems - 1;				//decrease the number of items in the dispenser
}