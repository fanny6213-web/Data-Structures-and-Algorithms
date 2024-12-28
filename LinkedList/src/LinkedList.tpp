#ifndef LINKEDLIST_TPP_INCLUDED
#define LINKEDLIST_TPP_INCLUDED

#include <iostream>
#include <ostream>

template <typename T>
void LinkedList<T>::Add(T data)
{
	listNode<T>* toAdd = new listNode<T>(data);

	listNode<T>* headCpy = head;

	//checking if the list is empty
	if(size == 0)
	{
		head = toAdd;
		size ++;
		return;
	}

	//traversing till end
	while(headCpy->next != NULL)
	{
		if(headCpy->data == toAdd->data)
		{
			std::cout<<"Element already exists"<<std::endl;
			return;
		}
		headCpy = headCpy->next;
	}

	//adding the element
	size++;
	headCpy->next = toAdd;
}

template <typename T>
void LinkedList<T>::Remove(T data)
{
	if(head == NULL)
	{
		std::cout<<"List is empty"<<std::endl;
		return;
	}

	listNode<T>* headCpy = head;

	while(headCpy->next->data != data)
	{
		if(headCpy->next == NULL)
		{
			std::cout<<"No such element in the list"<<std::endl;
			return;
		}
		headCpy = headCpy->next;
	}

	listNode<T>* trash = headCpy->next;
	headCpy->next = headCpy->next->next;

	size--;
	delete trash;
}

template <typename T>
void LinkedList<T>::print()
{
	if(head == NULL)
	{
		std::cout<<"List is empty"<<std::endl;
		return;
	}

	listNode<T>* headCpy = head;
	
	while(headCpy->next != NULL)
	{
		std::cout<<headCpy->data<<"->";
		headCpy = headCpy->next;
	}
	std::cout<<headCpy->data<<std::endl;
}

template <typename T>
bool LinkedList<T>::contains(T data)
{
	listNode<T>* headCpy = head;

	if(head == NULL)
	{
		std::cout<<"List is empty"<<std::endl;
		return false;
	}

	while(headCpy->next != NULL)
	{
		if(headCpy->data == data)
		{
			return true;
		}
		headCpy = headCpy->next;
	}
	return false;
}

template <typename T>
void LinkedList<T>::insert(int index, T data)
{
	listNode<T>* headCpy = head;
	listNode<T>* toInsert = new listNode<T>(data);

	if(index == 0)
	{
		toInsert->next = head;
		head = toInsert;
		return;
	}

	for(int i = 0; i < index-1; i++)
	{
		headCpy = headCpy->next;
	}

	toInsert->next = headCpy->next;
	headCpy->next = toInsert;
}

#endif
