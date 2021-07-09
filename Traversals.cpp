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


//Postorder
void BST::recursivePostorder() const
{
	recursivePostorder(root);
}


void BST::recursivePostorder(Node* ptr) const //private
{
	if (ptr != nullptr)
	{
		recursivePostorder(ptr->llink);
		recursivePostorder(ptr->rlink);
		cout << ptr->data << " ";
	}
}

void BST::nonRecursivePostorder() const 
{
	stack<Node*> nodeStack1, nodeStack2;
	Node* currentNode = root;
	nodeStack1.push(root);

	while (!nodeStack1.empty())
	{
		currentNode = nodeStack1.top();
		nodeStack1.pop();
		nodeStack2.push(currentNode);

		if (currentNode->llink)
			nodeStack1.push(currentNode->llink);
		if (currentNode->rlink)
			nodeStack1.push(currentNode->rlink);
	}

	while (!nodeStack2.empty())
	{
		currentNode = nodeStack2.top();
		nodeStack2.pop();
		cout << currentNode->data << ' ';
	}
}


//LevelOrder
void BST::recursiveLevelorder() const
{
	//recursiveLevelorder(root);
}

void BST::recursiveLevelorder(Node* ptr) const
{
	
}


void BST::nonRecursiveLevelorder() const
{
	queue<Node*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		Node* currentNode = nodeQueue.front();
		cout << currentNode->data << ' ';
		nodeQueue.pop();

		if (currentNode->llink)
			nodeQueue.push(currentNode->llink);
		if (currentNode->rlink)
			nodeQueue.push(currentNode->rlink);
	}
 }