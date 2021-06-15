#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <stack>

class Node
{
	friend class Tree;
public:
	Node() : data(0), rlink(nullptr), llink(nullptr) {}
	~Node() {}
private:
	int data;
	Node* rlink, * llink;
};

class Tree
{
public:

	Tree();

	int totalNodes() const;
	bool isEmpty() const;
	void emptyTree();

	~Tree();

	//Inorder
	void recursiveInsert(int);
	void recursiveInorder() const;

	void nonRecursiveInsert(int);
	void nonRecursiveInorder() const;

private:
	void clearTree(Node*&);

	//Inorder
	void recursiveInsert(Node*&, int);
	void recursiveInorder(Node*) const;

	Node* root; //pointer to the root
	int count;  //number of nodes
};

#endif

