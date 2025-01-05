#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T>
void LinkedList<T>::clear()
{
	listNode<T> trash; 
	while(head != NULL)
	{
		trash = head;
		head = head->next();
		delete trash;
	}
}
