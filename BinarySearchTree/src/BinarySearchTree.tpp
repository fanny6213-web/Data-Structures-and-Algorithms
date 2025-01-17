#ifndef BINARYSEARCHTREE_TPP
#define BINARYSEARCHTREE_TPP

#include "BinarySearchTree.h"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <ostream>
#include <iostream>
#include <stdexcept>

void DUPLICATED_ENTITY()
{
	throw std::runtime_error("Element already exists in the tree");
}

template <typename T>
void treeSet<T>::insert(treeNode<T>*& data, treeNode<T>*& rootCpy)
{
	if(rootCpy == NULL)
	{
		rootCpy = data;
	}
	else if(data->data > rootCpy->data)
	{
		insert(data, rootCpy->right);
	}
	else if(data->data < rootCpy->data)
	{
		insert(data, rootCpy->left);
	}
	else
	{
		try
		{
			DUPLICATED_ENTITY();
		} catch (const std::exception e)
		{
			std::cerr<<"Error: "<<e.what()<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

template <typename T>
void treeSet<T>::insert(T data)
{
	treeNode<T>* toInsert = new treeNode(data);

	if(root == NULL)
	{
		root = toInsert;
	}

	else
	{
		treeNode<T>* rootCpy = root;
		insert(toInsert, rootCpy);
	}
}

template <typename T>
void treeSet<T>::printSideways(treeNode<T>*& rootCpy, std::string prefix)
{
	if(rootCpy == NULL)
	{
		return;
	}
	else
	{
		printSideways(rootCpy->right, prefix+"    ");
		std::cout<<prefix<<rootCpy->data<<std::endl;
		printSideways(rootCpy->left, prefix+"    ");
	}
}

template <typename T>
void treeSet<T>::printSideways()
{
	treeNode<T>* rootCpy =  root;
	printSideways(rootCpy);
}

#endif
