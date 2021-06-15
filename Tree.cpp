#include "Tree.h"

using namespace std;

//default constructor
Tree::Tree() : root(nullptr), count(0) {}

//totalNodes
int Tree::totalNodes() const
{
	return count;
}

//isEmpty
bool Tree::isEmpty() const
{
	return (root == nullptr);
}

//emptyTree
void Tree::emptyTree()
{
	clearTree(root);
	count = 0;
}

//clearTree
void  Tree::clearTree(Node*& ptr)
{
	if (ptr != nullptr)
	{
		clearTree(ptr->llink);
		clearTree(ptr->rlink);
		delete ptr;
		ptr = nullptr;
	}
}

//destructor
Tree::~Tree()
{
	clearTree(root);
}