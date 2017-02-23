#pragma once

class Node
{
public:
	Node(int d = 0): left(nullptr), right(nullptr), mData(d)
	{

	}

	Node *left, *right;
	int mData;
};

class BST
{
public:
	BST();
	~BST();
	BST &operator <(int d);
	bool isBST(Node *);
	//friend Node* giveMeRoot();
private:
	Node *mRoot;
};

