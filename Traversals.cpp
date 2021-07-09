#include "BST.h"

using namespace std;

//Inorder
void BST::recursiveInorder() const
{
	recursiveInorder(root);
}

void BST::recursiveInorder(Node* ptr) const //private
{
	if (ptr != nullptr)
	{
		recursiveInorder(ptr->llink);
		cout << ptr->data << " ";
		recursiveInorder(ptr->rlink);
	}
}

void BST::nonRecursiveInorder() const
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


//Preorder
void BST::recursivePreorder() const
{
	recursivePreorder(root);
}

void BST::recursivePreorder(Node* ptr) const //private
{
	if (ptr != nullptr)
	{
		cout << ptr->data << " ";
		recursivePreorder(ptr->llink);
		recursivePreorder(ptr->rlink);
		
	}
}

void BST::nonRecursivePreorder() const
{
	stack<Node*> nodeStack;
	Node* currentNode = root;

	while (currentNode != nullptr || !nodeStack.empty())
	{
		while (currentNode != nullptr)
		{
			cout << currentNode->data << ' ';

			if (currentNode->rlink)
				nodeStack.push(currentNode->rlink);

			currentNode = currentNode->llink;
		}

		if (!nodeStack.empty()) 
		{
			currentNode = nodeStack.top();
			nodeStack.pop();
		}
	}
}