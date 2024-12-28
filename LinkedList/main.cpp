#include "LinkedList.h"

int main()
{
	LinkedList<int> arr;

	arr.Add(12);
	arr.Add(324);
	arr.Add(34);
	arr.Add(130);
	arr.Add(123);

	arr.print();

	arr.Remove(34);

	arr.print();
}
