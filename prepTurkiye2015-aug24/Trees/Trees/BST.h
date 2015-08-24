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
 I_INORDER,
 I_PREORDER,
 I_POSTORDER,
 R_INORDER,
 R_PREORDER,
 R_POSTORDER
};

class BST
{
public:
	BST(void);
	~BST(void);
	BST & operator <(int d);
	void display(Type t);
protected:
	void addItem(int d);
	static void addItemRec(Node **root,int d);
	static void inOrder(Node *);
	static void preOrder(Node *);
	static void postOrder(Node *);
private:
	Node *mRoot;
};

