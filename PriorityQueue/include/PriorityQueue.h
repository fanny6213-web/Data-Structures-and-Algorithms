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
		void enqueue(T data, int priority = 0);
		void dequeue();
		listNode<queueNode<T>>* peek();
		LinkedList<queueNode<T>> getQueue() {return queue;}
};

#include "../src/PriorityQueue.tpp"
#endif
