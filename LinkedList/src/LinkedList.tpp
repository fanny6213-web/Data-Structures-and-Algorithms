#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP

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
#endif
