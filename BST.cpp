#include "BST.h"

using namespace std;

//recursiveInsert
void BST::recursiveInsert(int elemToInsert)
{
	recursiveInsert(root, elemToInsert);
}

//recursiveInsert (private)
void BST::recursiveInsert(Node*& ptr, int elemToInsert)
{
	if (ptr == nullptr)
	{
		Node* newNode = new Node;
		newNode->data = elemToInsert;
		ptr = newNode;
		++count;
	}
	else if (ptr->data == elemToInsert)
		cerr << "Element " << elemToInsert
		<< " is already in the list. "
		<< "Duplicates are not allowed." << endl;
	else if (ptr->data > elemToInsert)
		recursiveInsert(ptr->llink, elemToInsert);
	else
		recursiveInsert(ptr->rlink, elemToInsert);
}

//nonRecursiveInsert
void BST::nonRecursiveInsert(int elemToInsert)
{

	if (root == nullptr)
	{
		Node* nodeToInsert = new Node;
		nodeToInsert->data = elemToInsert;

		root = nodeToInsert;
	}
	else
	{
		Node* parentNode = nullptr;
		Node* currentNode = root;
		bool isDuplicate = false;

		while (currentNode != nullptr && !isDuplicate)
		{
			parentNode = currentNode;

			if (currentNode->data == elemToInsert)
			{
				cerr << "Element " << elemToInsert << " is already in the list. "
					<< "Duplicates are not allowed." << endl;

				isDuplicate = true;
			}
			else if (currentNode->data < elemToInsert)
			{
				currentNode = currentNode->rlink;
			}
			else
			{
				currentNode = currentNode->llink;
			}
		}

		if (!isDuplicate)
		{
			Node* nodeToInsert = new Node;
			nodeToInsert->data = elemToInsert;

			if (parentNode->data < elemToInsert)
			{
				parentNode->rlink = nodeToInsert;
			}
			else
			{
				parentNode->llink = nodeToInsert;
			}
		}
	}
}

//emptyBST
void BST::emptyBST()
{
	deleteBST(root);
	count = 0;
}

//clearBST
void  BST::deleteBST(Node*& ptr)
{
	if (ptr != nullptr)
	{
		deleteBST(ptr->llink);
		deleteBST(ptr->rlink);
		delete ptr;
		ptr = nullptr;
	}
}

//destructor
BST::~BST()
{
	deleteBST(root);
}