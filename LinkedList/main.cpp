#include "LinkedList.h"
#include <ios>
#include <iostream>
#include <ostream>

int main()
{
	LinkedList<int> arr;

	arr.Add(12);
	arr.Add(324);
	arr.Add(34);
	arr.Add(130);
	arr.Add(123);

	arr.print();
	std::cout<<"\n";
	std::cout<<"Remove 34 from the list:"<<std::endl;
	arr.Remove(34);

	arr.print();

	std::cout<<"\n";
	std::cout<<"Is 324 present in the list?"<<std::endl;
	std::cout<<std::boolalpha;
	std::cout<<arr.contains(324)<<std::endl;
	
	std::cout<<"\n";
	std::cout<<"Insert 0 at index 0"<<std::endl;
	arr.insert(0, 0);
	std::cout<<"Insert 15 at index 3"<<std::endl;
	arr.insert(3, 15);

	arr.print();
}
