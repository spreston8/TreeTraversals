#include "Tree.h"

using namespace std;

//recursiveInsert
void Tree::recursiveInsert(int elemToInsert)
{
	recursiveInsert(root, elemToInsert);
}

//recursiveInsert (private)
void Tree::recursiveInsert(Node*& ptr, int elemToInsert)
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

//recursiveInorder
void Tree::recursiveInorder() const
{
	recursiveInorder(root);
}

//recursiveInorder (private)
void Tree::recursiveInorder(Node* ptr) const
{
	if (ptr != nullptr)
	{
		recursiveInorder(ptr->llink);
		cout << ptr->data << " ";
		recursiveInorder(ptr->rlink);
	}
}

//nonRecursiveInsert
void Tree::nonRecursiveInsert(int elemToInsert)
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
				cerr << "The item to insert is already in the list. "
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

//nonRecursiveInorder
void Tree::nonRecursiveInorder() const
{
	stack<Node*> nodeStack;
	Node* currentNode = root;

	while (currentNode != nullptr || !nodeStack.empty())
	{
		while (currentNode != nullptr)
		{
			nodeStack.push(currentNode);
			currentNode = currentNode->llink;
		}

		Node* poppedNode = nodeStack.top();
		cout << poppedNode->data << ' ';
		nodeStack.pop();
		currentNode = poppedNode->rlink;
	}
}