#include "LinkedList.h"
#include "PriorityQueue.h"
#include <iostream>
#include <ostream>

int main()
{
	pQueue<char> pq;
	pq.enqueue('c', 10);
	pq.enqueue('f', 15);
	pq.enqueue('h', 19);
	pq.enqueue('w', 11);
	pq.enqueue('x', 100);
	pq.enqueue('y', 5);


	pq.getQueue().print();
}
