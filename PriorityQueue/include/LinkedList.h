#pragma once
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

template <class T>
class LinkedList
{
	private:
		listNode<T>* head;
		int size = 0;
	public:
		void Add(T data);
		void Remove(T data);
		int getSize() {return size;}
		listNode<T>* getHead() {return head;}
		void print();
		bool contains(T data);
		void insert(int index, T data);
};

#include "../src/LinkedList.tpp"
#endif
