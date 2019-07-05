#include<iostream>
using namespace std;
#include"BinaryTree.h"

int main()
{
	BinaryTree<int> T;
	T.setRoot(17);
	T.insert(15);
	T.insert(25);
	T.insert(14);
	T.insert(16);
	T.insert(23);
	T.insert(24);
	T.insert(21);
//	T.insert(12);
	T.insert(26);
//	T.inOrderTraversal();
//	cout << endl;
//	T.postOrderTraversal();
//	cout << endl;
	T.preOrderTraversal();
	cout << endl;
//	cout << T.getParent(21) << endl;
//	cout << T.countNodes() << endl;
//	cout << T.minValue() << endl;
//	cout << T.countLeafNodes() << endl;
	cout << T.isComplete() << endl;
}