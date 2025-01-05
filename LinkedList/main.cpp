#include "LinkedList.h"
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

int main()
{
	LinkedList<int> arr(1);

	arr.addFirst(3243);
	arr.addLast(99);
	arr.insert(3,342);

	arr.print();

	arr.remove(0);

	arr.print();

}
