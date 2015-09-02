#pragma once


class Node
{
public:
	Node(int d):data(d),left(0),right(0)
	{
	}
	int data;
	Node *left,*right;
};

enum Type
{
 I_INORDER=0,
 I_PREORDER,
 I_POSTORDER,
 R_INORDER,
 R_PREORDER,
 R_POSTORDER,
 LEVEL_ORDER,
 SPIRAL_ORDER
};

class BST
{
public:
	BST(void);
	~BST(void);
	BST & operator <(int d);
	void display(Type t);
	double sumOfNodes();
	double highBranch();
protected:
	void addItem(int d);
	static Node * addItemRec(Node *root,int d); //doesnt work , needs to change some logic in recursion... 
	static void addItemRec1(Node **root,int data); //works well
	static void inOrder(Node *);
	static void preOrder(Node *);
	static void postOrder(Node *);
	static void levelOrder(Node *);
	static void inOrderIter(Node *root);
	static void preOrderIter(Node *root);
	static void postOrderIter(Node *root);
	static void spiralOrder(Node *root);
private:
	Node *mRoot;
};

