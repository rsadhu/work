#pragma once

///template<typename T>
class Node
{
public:
	int mData;
	Node *left, *right;
	Node(int d) :mData(d), left(nullptr), right(nullptr)
	{}
};
enum class TYPE
{
	INORDER_I = 0,
	POSTORDER_I,
	PREORDER_I,
	INORDER_R,
	POSTORDER_R,
	PREORDER_R,
	BFS,
	DFS,
	SPIRAL,
	MIRROR,
	TOPVIEW
};

class BST
{
public:
	BST();
	~BST();
	void add(int);
	void display(TYPE t);
	static void inOrderR(Node *);
protected:
	static  Node *add(Node *, int);
	Node *mRoot = nullptr;
};

