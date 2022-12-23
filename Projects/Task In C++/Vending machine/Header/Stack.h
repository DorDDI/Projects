/* Assignment C++: 1
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#include "StackNode.h"
#include <climits>

class Stack
{
	StackNode* top;
	int counter;

public:
	Stack();
	~Stack();
	void push(int);
	void pop();
	bool isEmpty();
	int peek();
};
