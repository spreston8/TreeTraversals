#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <stack>

class Node
{
	friend class BST;
public:
	Node() : data(0), rlink(nullptr), llink(nullptr) {}
	~Node() {}
private:
	int data;
	Node* rlink, * llink;
};

class BST
{
public:

	BST() : root(nullptr), count(0) {}

	int totalNodes() const { return count; }
	bool isEmpty() const { return (root == nullptr);  }

	void recursiveInsert(int);
	void nonRecursiveInsert(int);
	void emptyBST();

	//Inorder
	void recursiveInorder() const;
	void nonRecursiveInorder() const;

	//Preorder
	void recursivePreorder() const;
	void nonRecursivePreorder() const;
	
	~BST();

private:
	void recursiveInsert(Node*&, int);
	void deleteBST(Node*&);

	void recursiveInorder(Node*) const;
	void recursivePreorder(Node*) const;

	Node* root; //pointer to the root
	int count;  //number of nodes
};

#endif

