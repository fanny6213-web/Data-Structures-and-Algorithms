#include "LinkedList.h"
#include "PriorityQueue.h"
#include <iostream>
#include <ostream>

int main()
{
	pQueue<char> pq;

	pq.enqueue('c', 10);
	pq.enqueue('f', 15);
	pq.enqueue('s', 18);
	pq.enqueue('h', 19);
	pq.enqueue('w', 11);

	listNode<queueNode<char>>* node = pq.peek();
	
	std::cout<<node->data.data<<":"<<node->data.priority<<std::endl;

}
