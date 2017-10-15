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
	LEVELORDER,
	TOPVIEW
};

class BST
{
public:
	BST();
	~BST();
	void add(int);
	BST & operator<(int d);
	void display(TYPE t);
	static void inOrderR(Node *);
	static void preOrderR(Node *);
	static void postOrderR(Node *);
	static void inOrderI(Node *);
	static void preOrderI(Node *);
	static void postOrderI(Node *);
	static void bfs(Node *);
	static void spiral(Node *);
	static void levelOrder(Node *);
	static void topView(Node *);
	static void mirror(Node *);
protected:
	static  Node *add(Node *, int);
	Node *mRoot = nullptr;
};
