/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
//override default constructor and init an empty stack
{
	top = NULL;
	counter = 0;												//save the number of the puch items 
}
Stack::~Stack()
//override default distractor and pop all the data in the stack for delete function
{
	while (counter != 0)
		pop();
}
void Stack::push(int input_data)
{
	StackNode* temp = new StackNode(input_data);				//make a new StackNode with the input data
	if (top == NULL)											//if there is no items, the input item go to top
		top = temp;
	else                                                        //else go to top end the previous top go to next 
	{
		temp->setNext(top);
		top = temp;
	}
	counter++;													//add one to item counter			
}
void Stack::pop()
{
	if (counter == 0)											//if there is no items, print stack empty
		cout << "Stack is empty" << endl;

	else                                                        //else, decrease the counter, make the next item to the top and delete the dinamic previous top 
	{
		counter--;
		StackNode* temp = top;
		top = top->getNext();
		delete temp;
	}
}
bool Stack::isEmpty()
{
	return (counter == 0);										//check if there is no items in the stack and return true/false
}
int Stack::peek()												//return thre top item or INT_MIN if empty
{
	if (isEmpty())
		return INT_MIN;

	return top->getData();
}
