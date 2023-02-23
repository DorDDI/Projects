
#ifndef __SET_H						//define only once
#define __SET_H
#include <iostream>
using namespace std;

class Set
{
	int maxSize;								//maximal number of elements
	int currentSize;							//current number of elements.
	int* arr;									//arr of the elements
public:
	Set();										//override the defult constructor
	Set(int);									//constructor with int input
	Set(const Set& );							//copy constructor
	~Set();										//override the defult destructor
	bool isEmpty() const;						//check if the arr is empty
	void operator=(const Set& );				//oparator = constructor		
	void operator+=(int );						//oparator += constructor with int varieble
	Set operator+(const Set& ) const;			//oparator + constructor with Set varieble
	friend Set operator+(int , const Set& );	//oparator + constructor with int varieble that can be use with int class
	bool operator>(const Set& ) const;			//oparator > constructor
	int& operator[](int ) const;				//oparator [] constructor
	friend ostream& operator<<(ostream&, const	Set&);   //oparator << (print) constructor
};

#endif // __SET_H

