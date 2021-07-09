#include "BST.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

		cout << "*********TESTING INSERTING FUNCTIONS*********\n\n";

		vector<int> v1 = { 49, 35, 89, 24, 15, 16, 45, 67 };
		int vSize1 = static_cast<int>(v1.size());

		BST tree;
		cout << "Inserting { ";
		for (const int& i : v1)
			cout << i << ", ";
		cout << "} recursively...\n\n";

		for (const int& i : v1)
			tree.recursiveInsert(i);

		vector<int> v2 = { 59, 46, 58, 59, 25, 12, 76, 59, 12 };
		int vSize2 = static_cast<int>(v2.size());

		BST tree2;
		cout << "Inserting { ";
		for (const int& i : v2)
			cout << i << ", ";
		cout << "} non-recursively...\n";

		for (const int& i : v2)
			tree2.nonRecursiveInsert(i);
		cout << endl;


		cout << "*********TESTING INORDER FUNCTIONS*********\n\n";

		//Recursive
		cout << "Inorder traversal (recursive):\n      ";
		if (!tree.isEmpty())
			tree.recursiveInorder();
		else
			cerr << "BST is empty.";
		cout << "\n";

		//Non-recursive
		cout << "\nInorder traversal (non-recursive):\n      ";
		if (!tree2.isEmpty())
			tree2.nonRecursiveInorder();
		else
			cerr << "BST is empty.";
		cout << "\n\n";


		cout << "*********TESTING PREORDER FUNCTIONS*********\n\n";

		//Recursive
		cout << "Preorder traversal (recursive):\n      ";
		if (!tree.isEmpty())
			tree.recursivePreorder();
		else
			cerr << "BST is empty.";
		cout << "\n";




	return 0;
}
