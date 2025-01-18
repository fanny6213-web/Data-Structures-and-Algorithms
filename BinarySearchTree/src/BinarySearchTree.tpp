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

void EMPTY_TREE_EXCEPTION()
{
	throw std::runtime_error("The tree is empty, nothing to remove");
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
		} catch (const std::exception& e)
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

template <typename T>
treeNode<T>*& treeSet<T>::getMin(treeNode<T>*& rootCpy)
{
	if(rootCpy->left == NULL)
	{
		return rootCpy;
	}
	else
	{
		return getMin(rootCpy->left);
	}
}

template <typename T>
treeNode<T>*& treeSet<T>::getMin()
{
	if(root == NULL)
	{
		try
		{
			EMPTY_TREE_EXCEPTION();
		} catch(std::exception& e)
		{
			std::cout<<"Error: "<<e.what()<<std::endl;
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		treeNode<T>* rootCpy = root;
		return getMin(rootCpy);
	}
}

template <typename T>
void treeSet<T>::remove(treeNode<T>*& rootCpy, T data)
{
	if(rootCpy == NULL)
	{
		return;
	}
	if(rootCpy->data == data)
	{
		treeNode<T>* trash;
		if(rootCpy->right == NULL and rootCpy->left == NULL)
		{
			rootCpy = NULL;
			delete rootCpy;
		}
		else if(rootCpy->right == NULL)
		{
			trash = rootCpy;
			rootCpy = rootCpy->left;
			delete trash;
		}
		else if(rootCpy->left == NULL)
		{
			trash = rootCpy;
			rootCpy = rootCpy->right;
			delete trash;
		}
		else
		{
			treeNode<T>* right = rootCpy->right;
			trash = getMin(right);
			rootCpy->data = trash->data;
			remove(rootCpy->right, trash->data);
		}
	}
	else
	{
		if(data > rootCpy->data)
		{
			remove(rootCpy->right, data);
		}
		else if(data < rootCpy->data)
		{
			remove(rootCpy->left, data);
		}
	}
}

template <typename T>
void treeSet<T>::remove(T data)
{
	if(root == NULL)
	{
		try
		{
			EMPTY_TREE_EXCEPTION();
		} catch(std::exception& e)
		{
			std::cout<<"Error: "<<e.what()<<std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		treeNode<T>* rootCpy = root;
		remove(rootCpy, data);
	}
}

#endif
