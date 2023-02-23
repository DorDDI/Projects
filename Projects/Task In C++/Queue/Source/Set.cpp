
#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
//override the defult constructor
{
	this->maxSize = 1000;						//init the maxSize with 1000 as defult
	arr = new int[maxSize];						//init the arr as array with size of 1000 as defult
	currentSize = 0;							//init the currentSize counter to 0
}
Set::Set(int maxSize)
//constructor with int input
{
	this->maxSize = maxSize;					//init the maxSize with maxSize input value
	arr = new int[maxSize];						//init the arr as array with size of maxSize input
	currentSize = 0;							//init the currentSize counter to 0
}
Set::Set(const Set& other)
//copy constructor
{
	int i;
	maxSize = other.maxSize;					//init the maxSize with tghe other maxSize 
	arr = new int[other.maxSize];				//init the arr as array with size of other maxSize
	for (i = 0; i < maxSize; i++)				//copy the values of other to arr
		arr[i] = other.arr[i];
	currentSize = other.currentSize;			//init the currentSize counter to other currentSize

}
Set::~Set()
//override the defult destructor
{
	delete []arr;								//delete the dinamic array we created
}
bool Set::isEmpty() const
//check if the arr is empty
{
	return (currentSize == 0);
}
void Set::operator=(const Set& other)
//oparator = constructor	
{
	delete[]arr;								//delete the dinamic array we created end recreate it after
	int i;
	maxSize = other.maxSize;
	arr = new int[other.maxSize];
	for (i = 0; i < maxSize; i++)
		arr[i] = other.arr[i];
	currentSize = other.currentSize;
}

void Set::operator+=(int other)
//oparator += constructor with int varieble
{
	if (currentSize < maxSize)					//check if the number of elements in the array less then the size
	{
		int i;
		for (i = 0; i < currentSize; i++)		//add the number only if its not in the array
		{
			if (arr[i] == other)				//the number was in the array
				return;
		}
		arr[currentSize] = other;				//the number wasnt in the array and we add it in the end 
		currentSize++;
	}
	else                                        //the number of elements are the same as the size
	{
		int i;
		int* temp = new int(maxSize+1);			//create bigger dynamic array and save its pointer to arr
		for (i = 0; i < maxSize; i++)
			temp[i] = arr[i];
		temp[maxSize] = other;
		delete[] arr;
		arr = temp;
	}
}

Set operator+(int number, const Set& other)
//oparator + constructor with int varieble that can be use with int class
{
	int i;
	for (i = 0; i < other.currentSize; i++)		//check if the number are in the Set array
	{
		if (other.arr[i] == number)
			return other;						//if in the array, do nothing
	}

	if (other.currentSize < other.maxSize)		//else check if the number of elements in the array less then the size
	{
		Set temp(other.maxSize);				//if they less then the max, add to the end and return the temp
		for (i = 0; i < other.currentSize; i++)
			temp.arr[i] = other.arr[i];
		temp.arr[other.currentSize] = number;
		temp.currentSize++;
		return temp;
	}
	else                                        //else, make a bigger size of array and add it to the end
	{
		Set temp(other.maxSize + 1);
		for (i = 0; i < other.maxSize; i++)
			temp.arr[i] = other.arr[i];
		temp.arr[other.maxSize] = number;
		temp.currentSize++;
		return temp;
	}

}

Set Set::operator+(const Set& other) const
//oparator + constructor with Set varieble
{
	int j;
	Set temp(other.maxSize+maxSize);				//save one of the Set varieble in temp
	for (j = 0; j < currentSize; j++)
		temp += arr[j];
	for (j = 0; j < other.currentSize; j++)			//use the += operator to add the other Set varieble for each arr value
		temp += other.arr[j];
	return temp;
}
bool Set::operator>(const Set& other) const
//oparator > constructor
{
	return (currentSize > other.currentSize);		//return true if the first Set varieble have more elements then the second
}

int& Set::operator[](int index) const
//oparator [] constructor
{
	return arr[index];
}

ostream& operator<<(ostream& os, const Set& other)
//oparator << (print) constructor
{
	int i;
	os << "{";
	for (i = 0; i < other.currentSize-1; i++)
		os << other.arr[i] << ", ";
	os << other.arr[other.currentSize - 1] << "}";
	return os;
}



