#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstddef>

template <typename T>
struct listNode
{
	//constructor:
	listNode(T data, listNode* next=NULL) : next(next), data(data) {};

	listNode* next;
	T data;
};

template <typename T>
class LinkedList
{
	private:
		listNode<T>* head;
	public:
		int size = 0;
		void Add(T data);
		void Remove(T data);
		int getSize() {return size;}
		listNode<T>* getHead() {return head;}
		void print();
};

#include "../src/LinkedList.tpp"
#endif
