#include <iostream>
#include <ostream>
#include "BinarySearchTree.h"

int main()
{
	treeSet<int> test;

	test.insert(32);
	treeNode<int>* root = test.getRoot();
	test.insert(64);
	test.insert(63);
	test.insert(66);
	test.insert(65);
	test.insert(67);
	test.insert(14);
	test.insert(13);
	test.insert(12);

	test.remove(64);
	
	test.printSideways();

}
