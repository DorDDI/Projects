
#ifndef __MYQUEUE_H					//define only once
#define __MYQUEUE_H
#include <vector>
#include <iostream>
using namespace std;

class myQueue
{
	vector<int> queue;						//vector class that save the eleents as queue
	int maxQ;								//maximal size of elements that can be save in the queue
public:
	myQueue();								//override the defult constructor
	myQueue(int );							//constructor with int input
	~myQueue();								//override the defult destructor
	bool enQueue(int);						//add an element to the queue. return true if success, false if failed
	bool deQueue();							//remove the top element of the queue. return true if success, false if failed
	bool isEmpty() const;					//check if the queue is empty
	int peek() const;						//return the first element in the queue, -1 if empty
	friend ostream& operator<<(ostream&, const myQueue&);	//oparator << (print) constructor
};

#endif //__MYQUEUE_H

