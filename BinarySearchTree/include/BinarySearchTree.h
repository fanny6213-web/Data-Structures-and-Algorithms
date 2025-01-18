#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cstddef>
#include <string>

template <class T>
struct treeNode
{
	//default constructor
	treeNode<T>(){};
	//constructor
	treeNode<T>(T data, treeNode<T>* right = NULL, treeNode<T>* left = NULL): data(data), right(right), left(left){};
	
	T data;
	treeNode<T>* left;
	treeNode<T>* right;
};

template <class T>
class treeSet
{
	public:
		//default constructor
		treeSet<T>(){root = NULL;};
		//constructor
		treeSet<T>(treeNode<T> root) : root(root) {}; 

	private:
		treeNode<T>* root;
		void insert(treeNode<T>*& data, treeNode<T>*& rootCpy);
		void printSideways(treeNode<T>*& rootCpy, std::string prefix="");
		void remove(treeNode<T>*& rootCpy, T data);
		treeNode<T>*& getMin(treeNode<T>*& rootCpy);
	public:
		void insert(T data);
		void printSideways();
		treeNode<T>*& getMin();
		treeNode<T>* getRoot(){return root;};
		void remove(T data);
};

#include "../src/BinarySearchTree.tpp"

#endif
