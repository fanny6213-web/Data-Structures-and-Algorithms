#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T>
void pQueue<T>::enqueue(T data, int priority)
{
	queueNode<T> toAddData(data, priority); 

	if(queue.getSize() > 1)
	{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		int insertIndex = 0;

		for(int i = 0; i <= queue.getSize(); i++)
		{
			if(priority > headCpy->data.priority)
			{
				queue.insert(i, toAddData);
				return;
			}
			if(headCpy->next == NULL)
			{
				queue.insert(queue.getSize()-1, toAddData);
			}
			if(priority > headCpy->next->data.priority)
			{
				queue.insert(i+1, toAddData); 
				return;
			}
			headCpy = headCpy->next;
		}
	}
	else
	{
		if(queue.getSize() == 0)
		{
			queue.Add(toAddData);
		}
		else
		{
			if(queue.getHead()->data.priority < priority)
			{
				queue.insert(0, toAddData);
			}
			else
			{
				queue.Add(toAddData);
			}
		}
	}
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
