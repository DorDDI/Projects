/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#include "StackNode.h"
#include <iostream>
using namespace std;


StackNode::StackNode()
//override default constructor that init the data with 0 and the next to NULL
{
	data = 0;
	next = NULL;
}
StackNode::StackNode(int data_input) 
//override default constructor that init the data by value and the next to NULL
{
	data = data_input;
	next = NULL;
}
StackNode::~StackNode()
//override default distractor
{

}
int StackNode::getData() const						//return the data in the stack node
{
	return data;
}
StackNode* StackNode::getNext() const				//return the next varieble in the stack
{
	return next;
}
void StackNode::setData(int input_data)				//set the data in the stack node
{
	data = input_data;
}
void StackNode::setNext(StackNode* input_next)		//set the next varieble in the stack
{
	next = input_next;
}