
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
