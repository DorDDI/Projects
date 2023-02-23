/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/

#ifndef __NODE_H					//define only once
#define __NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
	T data;							//variable that store the T class data
	Node<T>* Next;					//variable that store the next T node pointer
public:
	Node(T data);					//constractor that get the data of the class
	Node();							//override the defult constructor
	~Node();						//override the default destractor
	void SetNextNode(Node<T>*);		//func that set the next varieble of the node
	Node<T>* GetNextNode() const;	//func that return the node in the next variable
	T& GetDataNode() ;				//func that return the data in the data varieble
};

template <class T>
Node<T>::Node(T data)
//constractor that get the data of the class
{
	this->data = data;				//init the data varieble 
	Next = nullptr;					//set the next to be nullptr
}

template <class T>
Node<T>::Node()
//override the defult constructor
{
	data = NULL;					//set the data to be null
	Next = nullptr;					//set the next to be nullptr
}

template <class T>
Node<T>::~Node()
//override the default destractor
{

}

template <class T>
void Node<T>::SetNextNode(Node<T>* Next)
//func that set the next varieble of the node
{
	this->Next = Next;
}

template <class T>
Node<T>* Node<T>::GetNextNode() const
//func that return the node in the next variable
{
	return Next;
}


template <class T>
T& Node<T>::GetDataNode() 
//func that return the data in the data varieble
{
	return data;
}

#endif //__NODE_H