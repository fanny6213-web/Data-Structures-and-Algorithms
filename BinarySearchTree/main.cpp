#include <iostream>
#include <ostream>
#include "BinarySearchTree.h"

int main()
{
	treeSet<int> test;

	test.insert(32);
	treeNode<int>* root = test.getRoot();
	test.insert(64);
	test.insert(12);
	test.printSideways();
}
