
#include "myQueue.h"
#include <iostream>

using namespace std;

myQueue::myQueue()
//override the defult constructor
{
	this->maxQ = 100;						//init the maxQ with 100 as defult
}
myQueue::myQueue(int maxQ)
//constructor with int input
{
	if (maxQ < 0)							//init the maxQ with maxQ input. if the input is <0, maxQ = 0
		maxQ = 0;
	this->maxQ = maxQ;
}
myQueue::~myQueue()
//override the defult destructor
{

}
bool myQueue::enQueue(int val)
//add an element to the queue. return true if success, false if failed
{
	if (queue.size() == maxQ)				//insert an element only if the queue isnt full
		return false;						//return false if the queue is full
	queue.push_back(val);
	return true;							//return true if the element added successfully
}
bool myQueue::deQueue()
//remove the top element of the queue. return true if success, false if failed
{
	if (queue.empty())						//remove the top element only if the queue isnt empty
		return false;						//return false if the queue is empty
	queue.erase(queue.begin());
	return true;							//return true if the element removed successfully
}
bool myQueue::isEmpty() const
//check if the queue is empty
{
	return queue.empty();
}

int myQueue::peek() const
//return the first element in the queue, -1 if empty
{
	if (this->isEmpty())					//if the qeueue is empty, return -1 
		return -1;
	return queue.front();					//else return the top element in the queue
}

ostream& operator<<(ostream& os, const myQueue& other)
//oparator << (print) constructor
{
	for (auto it = other.queue.begin(); it != other.queue.end()-1; it++)
		os << *it << " <- ";
	os << *(other.queue.end()-1);
	return os;
}