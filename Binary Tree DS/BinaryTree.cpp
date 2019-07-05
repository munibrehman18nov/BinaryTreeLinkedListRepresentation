#include "BinaryTree.h"
#include<iostream>
using namespace std;


//void diplayAncestors(T nod);
//void displayDescendents(T nod);
//int heightOfTree();

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = 0;
}

template <class T> void BinaryTree<T>::setRoot(T val)
{
	root = new Node<T>(val);
}
template <class T>
bool BinaryTree<T>::isEmpty(Node<T>*t)
{
	if (t == nullptr)
		return true;
	return false;
}
template <class T>T BinaryTree<T>::findParent(Node<T>*t, T val)
{
	if (val <= t->info)
	{
		if (t->left != nullptr)
		{
			if (t->left->info == val)
				return t->info;
			return findParent(t->left, val);
		}
	}
	else if (val > t->info)
	{
		if (t->right != nullptr)
		{
			if (t->right->info == val)
				return t->info;
			return findParent(t->right, val);
		}
	}
	return -1;
}
template <class T>T BinaryTree<T>::getParent(T node)
{
	return findParent(root, node);
}
/*template <class T>bool BinaryTree<T>::remove(T nod)
{
	if (isNodeExist(nod))
	{
		Node<T>*t;
		t = searchNode(root, nod);

	}
}*/
template <class T>bool BinaryTree<T>::isNodeExist(T val)
{
	Node<T>*t;
	t= findNodePlace(root, val);
	if (t == nullptr)
		return false;
	return true;
}
template <class T>Node<T>*BinaryTree<T>::searchNode(Node<T>*t, T val)
{
	if (t->info == val)
	{
		return t;
	}
	else if (val <= t->info)
	{
		return searchNode(t->left, val);
	}
	else if (val > t->info)
	{
		return searchNode(t->right, val);
	}
}
template <class T>Node<T>*BinaryTree<T>::findNodePlace(Node<T>*t, T val)
{
	if (val <= t->info)
	{
		if (t->left == nullptr)
			return t;
		return findNodePlace(t->left, val);
	}
	else
	{
		if (t->right == nullptr)
			return t;
		return findNodePlace(t->right, val);
	}
}
template <class T>void BinaryTree<T>::insert(T val)
{
	Node<T>*n = new Node<T>(val);
	Node<T>*t = findNodePlace(root, val);
	if (val <= t->info)
	{
		t->left = new Node<T>;
		t->left->info = n->info;
		t->left->left = n->left;
		t->left->right = n->right;
	}
	else if (val > t->info)
	{
		t->right = new Node<T>;
		t->right->info = n->info;
		t->right->left = n->left;
		t->right->right = n->right;
	}
}
template<class T>void BinaryTree<T>::VLR(Node<T>*t)
{
	if (!isEmpty(t))
	{
		cout << t->info << " ";
		VLR(t->left);
		VLR(t->right);
	}
}
template<class T>void BinaryTree<T>::LVR(Node<T>*t)
{
	if (!isEmpty(t))
	{
		LVR(t->left);
		cout << t->info << " ";
		LVR(t->right);
	}
}
template<class T>void BinaryTree<T>::LRV(Node<T>*t)
{
	if (!isEmpty(t))
	{
		LRV(t->left);
		LRV(t->right);
		cout << t->info << " ";
	}
}
template<class T>int BinaryTree<T>::countLRnodes(Node<T>*t)
{
	int n = 1;
	if (t->left == nullptr)
		return n;
	n = n + countLRnodes(t->left);
	if (t->right == nullptr)
		return n;
	n = n + countLRnodes(t->right);
	return n;
}
template<class T>int BinaryTree<T>::countNodes()
{
	return countLRnodes(root);
}
template<class T>T BinaryTree<T>::findMinValue(Node<T>*t)
{
	while (t->left != nullptr)
		t = t->left;
	return t->info;
}
template<class T>T BinaryTree<T>::minValue()
{
	return findMinValue(root);
}

template<class T>int BinaryTree<T>::countLeafNodes()
{
	return findLeafNodes(root);
}
template<class T>int BinaryTree<T>::findLeafNodes(Node<T>*t)
{
	if (t == nullptr)
		return 0;
	if (t->left == nullptr && t->right == nullptr)
		return 1;
	return findLeafNodes(t->left) + findLeafNodes(t->right);
}
template <class T>bool BinaryTree<T>::checkComplete(Node<T>*t)
{
	if (t->left && t->right)
	{
		return checkComplete(t->left) && checkComplete(t->right);
	}
	else
	if (!t->left && !t->right)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class T>bool BinaryTree<T>::isComplete()
{
	return checkComplete(root);
}

template <class T>void BinaryTree<T>::preOrderTraversal()
{
	VLR(root);
}

template <class T>void BinaryTree<T>::inOrderTraversal()
{
	LVR(root);
}
template <class T>void BinaryTree<T>::postOrderTraversal()
{
	LRV(root);
}


template <class T>
BinaryTree<T>::~BinaryTree()
{
}

template BinaryTree<int>;