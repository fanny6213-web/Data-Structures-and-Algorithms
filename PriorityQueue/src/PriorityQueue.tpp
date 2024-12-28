template <typename T>
void pQueue<T>::enqueue(T data, int priority)
{
	queueNode<T> toAddData(data, priority); 

	if(queue.size == 0)
	{
		listNode<queueNode<T>>* toAdd = new listNode<queueNode<T>>(toAddData);
		queue.Add(toAddData);
	}
	else
	{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		int insertIndex = 0;

		while(priority < headCpy->next->data.priority)
		{
			headCpy = headCpy->next;
			insertIndex++;
		}
		
		queue.insert(insertIndex, data);
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
	if(queue.size <= 0)
	{
		return;
	}
	else{
		listNode<queueNode<T>>* headCpy = queue.getHead();
		if(queue.size == 1)
		{
			delete headCpy;
		}
		else
		{
			listNode<queueNode<T>>* trash = headCpy;

			headCpy = headCpy->next;
			delete trash;
		}
	}
}

template <typename T>
bool operator==(const queueNode<T>& first, const queueNode<T>& second)
{
	return(first.data == second.data);
}
