#pragma once
#include "stdafx.h"

namespace TREES
{
	class Node
	{
	public:
		Node(int d) : mData(d), right(0), left(0)
		{
		}
		int mData;
		Node *right, *left;
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
		SPIRAL,
		PRINTALLPATHS
	} TYPE;

	class BST
	{
	public:
		BST();
		~BST();
		BST &operator<(int d);
		void display(TYPE t = INORDER_REC);
		void deleteNode(int data);

	protected:
		void addElement(int data);		  // iterative way
		Node *appendElement(Node *, int); // recursive way
	public:
		static void inOrderRec(Node *);
		static void preOrderRec(Node *);
		static void postOrderRec(Node *);
		static void inOrderIter(Node *);
		static void preOrderIter(Node *);
		static void postOrderIter(Node *);
		static void spiralOrder(Node *);
		static void bfs(Node *);
		static void dfs(Node *);
		static void printAllPaths(Node *);

	private:
		Node *mRoot;
	};

}
