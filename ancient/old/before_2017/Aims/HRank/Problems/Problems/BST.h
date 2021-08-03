#pragma once
#include"stdafx.h"

namespace TREES
{
	class Node
	{
	public:
		Node(int d) :mData(d), right(0), left(0)
		{

		}
		int mData;
		Node  *right, *left;
	};
	typedef enum
	{
		INORDER_REC,
		PREORDER_REC,
		POSTORDER_REC,
		INORDER_ITER,
		PREORDER_ITER,
		POSTORDER_ITER,
		BFS,
		DFS,
		SPIRAL
	}TYPE;

	class BST
	{
	public:
		BST();
		~BST();
		BST &operator<(int d);
		void display(TYPE t = INORDER_REC);

	protected:
		void addElement(int data); //iterative way
		Node * appendElement(Node *, int); // recursive way

		void inOrderRec(Node *);
		void preOrderRec(Node*);
		void postOrderRec(Node*);
		void inOrderIter();
		void preOrderIter();;
		void postOrderIter();
		void spiralOrder();
		void bfs();
		void dfs();

	private:

		Node *mRoot;
	};

}
