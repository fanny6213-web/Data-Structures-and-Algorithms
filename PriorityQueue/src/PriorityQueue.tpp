#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T>
void pQueue<T>::enqueue(T data, int priority)
{
	queueNode<char> toInsert(data, priority);
	//Insert at first if the queueSize is 0 (insert in a empty queue())
	if(queue.getSize() == 0)
	{
		queue.addFirst(toInsert);
		return;
	}
	else
	{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		int size = queue.getSize();

		//Insert at first if the priority of first node is lesser than the InsertionNode
		if(priority > headCpy->data.priority)
		{
			queue.addFirst(toInsert);
			return;
		}
		//Normal traversal insertion
		else
		{
			for(int i = 0; i < size; i++)
			{
				if(priority > headCpy->data.priority)
				{
					queue.insert(i, toInsert);
					return;
				}
				else
				{
					headCpy = headCpy->next;
				}
			}
		}
	}
	//Insert at the end if we reach the end of the queue;
	queue.insert(queue.getSize(), toInsert);
	return;
}












template <typename T>
listNode<queueNode<T>>* pQueue<T>::peek()
{
	return queue.getHead();
}

template <typename T>
void pQueue<T>::dequeue()
{
	if(queue.getSize() <= 0)
	{
		return;
	}
	else{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		if(queue.getSize() == 1)
		{
			delete headCpy;
		}
		else
		{
			queue.Remove(queue.getHead()->data);
		}
	}
}

template <typename T>
bool operator==(const queueNode<T>& first, const queueNode<T>& second)
{
	return(first.data == second.data);
}

template <typename T>
bool operator!=(const queueNode<T>& first, const queueNode<T>& second)
{
	return(first.data != second.data);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const queueNode<T>& obj)
{
	out << obj.data << ":" << obj.priority;	
	return out;
}
