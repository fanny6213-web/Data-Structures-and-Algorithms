#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "LinkedList.h"

template <class T>
struct queueNode
{
	//constructor
	queueNode(T data, int priority = 0): data(data), priority(priority) {};

	int priority;
	T data;
};

template <class T>
class pQueue
{
	private:
		LinkedList<queueNode<T>> queue;
	public:
		LinkedList<queueNode<T>> getQueue() {return queue;}
		void enqueue(T data, int priority = 0);
		bool empty();
		int size();
		listNode<queueNode<T>>* top();
		void dequeue();
		void clear();
		~pQueue(){clear();}
};

#include "../src/PriorityQueue.tpp"
#endif
