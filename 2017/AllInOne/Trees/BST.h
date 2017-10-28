#pragma once

#include<vector>
#include<iostream>
#include<stack>
#include<queue>


//class  BinaryTree
//{
//	Node *mRoot = nullptr;
//public:
//	void addNode(int d);
//	void display()
//	{
//		inOrderDisplay(mRoot);
//	}
//	static void inOrderDisplay(Node *);
//	bool mLeft = true;
//};


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
	TOPVIEW,
	REVERSE_LEVELORDER
};


class BST
{
public:
	BST();
	~BST(); // need to clean this 
	void add(int);	 // iterative way 
	BST & operator<(int d); // ease to add items
	void display(TYPE t); 
	int max();
	int min();	
	int height();
	int depth(int);
	int count();
	bool isBST(); // needs reimplemented
	void printAllPaths(); 
	void printLargestSumPath();
	void printSmallestSumPath();
	void deleteItem(int); // todo : not done yet
	bool areTreesSame(Node *, Node *);
	Node *root(){ return mRoot; }
private:
	static void inOrderR(Node *);
	static void preOrderR(Node *);
	static void postOrderR(Node *);
	static void inOrderI(Node *);
	static void preOrderI(Node *);
	static void postOrderI(Node *);
	static void bfs(Node *);
	static void spiral(Node *);
	static void levelOrder(Node *);
	static void reverseLevelOrder(Node *);
	static void topView(Node *);
	static void mirror(Node *);
	static int findHeight(Node *);
	static int depth(Node *,int);
	static void printPathsRec(Node *root, std::vector<int> );
	static Node* deleteAnItem(Node *, int);
protected:
	static  Node *add(Node *, int);
	Node *mRoot = nullptr;
};

