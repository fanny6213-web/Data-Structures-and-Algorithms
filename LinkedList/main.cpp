#include "LinkedList.h"
#include <ios>
#include <iostream>
#include <ostream>

int main()
{
	LinkedList<int> arr(55);

	arr.remove(32);

	arr.print();
}
