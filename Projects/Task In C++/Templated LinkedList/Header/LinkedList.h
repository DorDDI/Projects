/* Assignment C++: 3
   Author: Dor Lasry, ID: 314977851
   Author: Tomer Golan, ID: 208787366
*/
#ifndef __LINKEDLIST_H					//define only once
#define __LINKEDLIST_H

#include <iostream>
#include <cstring>
#include <typeinfo>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
	Node<T>* head;
public:
	LinkedList();					//override the defult constructor
	~LinkedList();					//override the default destractor
	void insert(const T&);			//func that insert an T element to the top of the list
	T deleteNode();					//func that delete the first node in the list
	T deleteNode(const T&);		//func that delete the T data node in the list
	bool search(const T&);			//func that check if the T data node is in the list
	const bool  IsEmpty() const;	//func that check if the list is empty
	const T& getTop() const;		//return the head data (top element)
	Node<T>* GetHead() const;		//return the head node pointer
	template <class U>
	friend ostream& operator<<(ostream&, const LinkedList<U>&);	//oparator << (print) constructor
};

template <class T>
LinkedList<T>::LinkedList()
//override the defult constructor
{
	head = nullptr;						//init the head to be nullptr
}

template <class T>
LinkedList<T>::~LinkedList()
//override the default destractor
{
	if (IsEmpty())						//check if the list is empty
		return;							//if empty do nothing
	Node<T>* current_ptr = head;				//pointer to the current node
	Node<T>* next_ptr = head->GetNextNode();	//pointer to the next node
	while (next_ptr != nullptr)					//run until we arrive to one before the last node
	{
		delete current_ptr;						//delete the node itself		
		current_ptr = next_ptr;					//set the current pointer to be the next pointer
		next_ptr = current_ptr->GetNextNode();	//set the next pointer to be the next node of the next pointer
	}											//we arrive to the last varible
	delete current_ptr;							//delete the last node itself	
}

template <class T>
const bool  LinkedList<T>::IsEmpty() const
//func that check if the list is empty
{
	return (head == nullptr);					//if the head == nullptr, the list is empty and return true, else return false
}

template <class T>
void LinkedList<T>::insert(const T& data)
//func that insert an T element to the top of the list
{
	Node<T>* temp;
	temp = new Node<T>(data);
	temp->SetNextNode(head);
	head = temp;
}

template <class T>
T LinkedList<T>::deleteNode()
//func that delete the first node in the list
{

	if (IsEmpty())						//if the list is empty, throw exeption
		throw - 1;
	Node<T>* temp;
	temp = head->GetNextNode();			//delete the first element
	T data = head->GetDataNode();
	delete head;
	head = temp;
	return data;						//return the deleted element
}

template <class T>
Node<T>* LinkedList<T>::GetHead() const
//return the head node pointer
{
	return head;
}

template <class T>
T LinkedList<T>::deleteNode(const T& data)
//func that delete the T data node in the list
{
	if (IsEmpty())						//if the list is empty, throw exeption
		throw - 1;

	if (head->GetDataNode() == data)		//check if the data we want to delete is in the head
	{
		Node<T>* temp;					//delete the node
		temp = head->GetNextNode();
		T data = head->GetDataNode();
		delete head;
		head = temp;
		return data;					//return the deleted data
	}

	Node<T>* ptr = head;
	Node<T>* temp;
	while (ptr->GetNextNode() != nullptr)				//run on all the nodes and check if the data is in the node
	{
		if (ptr->GetNextNode()->GetDataNode() == data)	//if the data is in the node, delete it
		{
			T data = ptr->GetNextNode()->GetDataNode();
			temp = head->GetNextNode();
			ptr->SetNextNode(ptr->GetNextNode()->GetNextNode());
			delete temp;
			return data;
		}
		ptr = ptr->GetNextNode();
	}

	throw "Exception: the data not found";				//throw exeption if we didnt find the data in the list

}

template <class T>
bool LinkedList<T>::search(const T& data)
//func that check if the T data node is in the list
{
	Node<T>* ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->GetDataNode() == data)
			return true;
		ptr = ptr->GetNextNode();
	}
	return false;
}

template <class T>
const T& LinkedList<T>::getTop() const
//return the head data (top element)
{
	if (IsEmpty())							//if the list is empty, throw exception
		throw - 1;
	return head->GetDataNode();				//else retun the data of the head
}

template <class U>
ostream& operator<<(ostream& os, const LinkedList<U>& other)
//oparator << (print) constructor
{
	Node<U>* ptr = other.GetHead();
	if (other.IsEmpty() == true)			//check if the list is empty
	{
		os << "empty";						//return empty
		return os;
	}
	os << ptr->GetDataNode();				//else print the nodes with "->" between them
	while (ptr->GetNextNode() != nullptr)
	{
		os << "->" << ptr->GetNextNode()->GetDataNode();
		ptr = ptr->GetNextNode();
	}
	return os;
}
#endif //__LINKEDLIST_H