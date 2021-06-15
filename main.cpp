#include "Tree.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

	{
		cout << "*********TESTING PREORDER FUNCTIONS*********\n\n";

		//Recursive, 1


	}

	{
		cout << "*********TESTING INORDER FUNCTIONS*********\n\n";

		//Recursive, 1
		vector<int> v1 = { 49, 35, 89, 24, 15, 16, 45, 67 };
		int vSize1 = static_cast<int>(v1.size());

		Tree tree1;
		cout << "Inserting { ";
		for (const int& i : v1)
			cout << i << ", ";
		cout << "} recursively...\n\n";

		for (const int& i : v1)
			tree1.recursiveInsert(i);

		cout << "Inorder traversal (recursive):\n      ";
		if (!tree1.isEmpty())
			tree1.recursiveInorder();
		else
			cerr << "Tree is empty.";
		cout << "\n\n";

		//Non-recursive, 2
		vector<int> v2 = { 59, 46, 58, 59, 25, 12, 76, 59, 12 };
		int vSize2 = static_cast<int>(v2.size());

		Tree tree2;
		cout << "Inserting { ";
		for (const int& i : v2)
			cout << i << ", ";
		cout << "} non-recursively...\n";

		for (const int& i : v2)
			tree2.nonRecursiveInsert(i);

		cout << "\nInorder traversal (non-recursive):\n      ";
		if (!tree2.isEmpty())
			tree2.nonRecursiveInorder();
		else
			cerr << "Tree is empty.";
		cout << endl;
	}

	return 0;
}
