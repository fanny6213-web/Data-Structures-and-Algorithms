#ifndef LINKEDLIST_TPP_INCLUDED
#define LINKEDLIST_TPP_INCLUDED

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

void OUT_OF_INDEX_EXCEPTION(int size, int index)
{
	if(index > size)
	{
		throw std::runtime_error("LinkedList: Index out of range");
	}
}

void EMPTY_LIST_EXCEPTION(void* head)
{
	if(head==NULL)
	{
		throw std::runtime_error("LinkedList: Can't operate on an empty list");
	}
}

void ELEMENT_NOT_FOUND_EXCEPTION()
{
	throw std::runtime_error("Error: LinkedList: No such element found in the list");
}

template <typename T>
void LinkedList<T>::addFirst(T data)
{
	listNode<T>* toInsert = new listNode<T>(data); 
	if(head == NULL)
	{
		head = toInsert;
	}
	else
	{
		toInsert->next = head;
		head = toInsert;
	}
	size++;
}

template <typename T>
void LinkedList<T>::addLast(T data)
{
	listNode<T>* toInsert = new listNode<T>(data);

	if(head == NULL)
	{
		head = toInsert;
	}
	else
	{
		listNode<T>* headCpy = head;

		while(headCpy->next != NULL)
		{
			headCpy = headCpy->next;
		}

		headCpy->next = toInsert;
	}
	size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data)
{
	try
	{
		OUT_OF_INDEX_EXCEPTION(size, index);
	} catch (const std::exception& e) {
		std::cerr<<"Error: "<<e.what()<<std::endl;
		exit(EXIT_FAILURE);
	}

	listNode<T>* headCpy = head;

	if(index == 0)
	{
		this->addFirst(data);
	}
	else
	{
		listNode<T>* toInsert = new listNode<T>(data);

		for(int i = 0; i < index-1; i++)
		{
			headCpy = headCpy->next;
		}

		toInsert->next = headCpy->next;
		headCpy->next = toInsert;
	}
	size++;
}


template <typename T>
void LinkedList<T>::print()
{
	if(head == NULL)
	{
		try
		{
			EMPTY_LIST_EXCEPTION(head);
		} catch (const std::exception& e) {
			std::cout<<"Error : "<<e.what()<<std::endl;
			std::exit(EXIT_FAILURE);
		}
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
		try
		{
			EMPTY_LIST_EXCEPTION(head);
		} catch (const std::exception& e) {
			std::cout<<"Error : "<<e.what()<<std::endl;
			std::exit(EXIT_FAILURE);
		}
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
void LinkedList<T>::remove(int index)
{
	try
	{
		OUT_OF_INDEX_EXCEPTION(size, index);
	} catch (const std::exception& e) {
		std::cerr<<"Error: "<<e.what()<<std::endl;
		exit(EXIT_FAILURE);
	}

	listNode<T>* headCpy = head;
	for(int i = 0; i < index-1; i++)
	{
		headCpy = headCpy->next;
	}

	if(headCpy->next == NULL)
	{
		delete headCpy;
	}
	else
	{
		listNode<T>* trash = headCpy->next;
		headCpy->next = headCpy->next->next;
		delete trash;
	}
	size --;
}

#endif
