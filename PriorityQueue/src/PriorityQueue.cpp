#include "PriorityQueue.h"
#include "LinkedList.h"

template <typename T>
void pQueue<T>::enqueue(T data, int priority)
{
	queueNode<char> toInsert(data, priority);
	if(queue.getSize() == 0)
	{
		queue.addFirst(toInsert);
	}
	else
	{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		int size = queue.getSize();

		if(priority > headCpy->data.priority)
		{
			queue.addFirst(toInsert);
		}
		else
		{
			for(int i = 0; i < size; i++)
			{
				if(priority < headCpy->data.priority)
				{
					std::cout<<"set"<<std::endl;
					queue.insert(i++, toInsert);
				}
				else
				{
					headCpy = headCpy->next;
				}
			}
		}

	}
}
