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
		LinkedList<T>() : head(NULL){};
		LinkedList<T>(T data) {listNode<T>* HEAD = new listNode<T>(data); head=HEAD; size++;}
		void addFirst(T data);
		void addLast(T data);
		void insert(int index, T data);
		void remove(int index);
		int getSize() {return size;}
		listNode<T>* getHead() {return head;}
		void print();

		bool contains(T data);
		bool isEmpty();
};

#include "../src/LinkedList.tpp"
#endif
