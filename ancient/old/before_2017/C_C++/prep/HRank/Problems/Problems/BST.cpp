#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
using namespace TREES;

BST::BST() : mRoot(0)
{
}

BST::~BST()
{
}

BST &BST::operator<(int d)
{
	// addElement(d); //iterative method of Adding Elements
	mRoot = appendElement(mRoot, d); // recursive method of adding elements
	return *this;
}

void BST::addElement(int d)
{
	if (!mRoot)
	{
		mRoot = new Node(d);
	}
	else
	{
		Node *tra(mRoot);

		while (tra)
		{

			if (d < tra->mData)
			{
				if (tra->left)
					tra = tra->left;
				else
				{
					tra->left = new Node(d);
					break;
				}
			}
			else if (d > tra->mData)
			{
				if (tra->right)
				{
					tra = tra->right;
				}
				else
				{
					tra->right = new Node(d);
					break;
				}
			}
		}
	}
}

Node *BST::appendElement(Node *root, int data)
{
	if (root)
	{
		if (data > root->mData)
			root->right = appendElement(root->right, data);
		else if (data < root->mData)
			root->left = appendElement(root->left, data);
	}
	else
	{
		return new Node(data);
	}
	return root;
}

void BST::display(TYPE t)
{
	cout << "\n";
	switch (t)
	{
	case INORDER_REC:
		inOrderRec(mRoot);
		break;
	case PREORDER_REC:
		preOrderRec(mRoot);
		break;
	case POSTORDER_REC:
		postOrderRec(mRoot);
		break;
	case INORDER_ITER:
		inOrderIter(mRoot);
		break;
	case PREORDER_ITER:
		preOrderIter(mRoot);
		break;
	case POSTORDER_ITER:
		postOrderIter(mRoot);
		break;
	case BFS:
		bfs(mRoot);
		break;
	case DFS:
		dfs(mRoot);
		break;
	case SPIRAL:
		spiralOrder(mRoot);
		break;
	case PRINTALLPATHS:
		printAllPaths(mRoot);
		break;
	default:
		inOrderRec(mRoot);
		break;
	}
}

void BST::inOrderRec(Node *root)
{
	if (root)
	{
		inOrderRec(root->left);
		cout << root->mData << " ";
		inOrderRec(root->right);
	}
}

void BST::preOrderRec(Node *root)
{
	if (root)
	{
		cout << root->mData << " ";
		preOrderRec(root->left);
		preOrderRec(root->right);
	}
}

void BST::postOrderRec(Node *root)
{
	if (root)
	{
		postOrderRec(root->left);
		postOrderRec(root->right);
		cout << root->mData << " ";
	}
}

void BST::inOrderIter(Node *root)
{
	stack<Node *> st;
	// Node *root = mRoot;

	while (root || !st.empty())
	{
		if (root)
		{
			st.push(root);
			root = root->left;
		}
		else
		{
			root = st.top();
			cout << root->mData << " ";
			st.pop();
			root = root->right;
		}
	}
}

void BST::preOrderIter(Node *root)
{
	stack<Node *> st;
	// Node *root = mRoot;
	st.push(root);

	while (!st.empty())
	{
		root = st.top();
		cout << root->mData << " ";
		st.pop();
		if (root->right)
			st.push(root->right);
		if (root->left)
			st.push(root->left);
	}
}

void BST::postOrderIter(Node *root)
{
	stack<Node *> st1, st2;
	// Node *root = mRoot;
	st1.push(root);

	while (!st1.empty())
	{
		st2.push(st1.top());
		Node *root = st1.top();
		st1.pop();
		if (root->left)
			st1.push(root->left);
		if (root->right)
			st1.push(root->right);
	}

	while (!st2.empty())
	{
		cout << st2.top()->mData << " ";
		st2.pop();
	}
}

void BST::spiralOrder(Node *root)
{
	queue<Node *> q1, q2;
	// Node *root = mRoot;
	q1.push(root);
	while (!q1.empty() || q2.empty())
	{
	}
}

void BST::dfs(Node *root)
{
}

void BST::bfs(Node *root)
{
	queue<Node *> q;
	// Node *root = mRoot;
	q.push(root);
	while (!q.empty())
	{
		root = q.front();
		if (root)
			cout << root->mData << " ";
		q.pop();

		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
	}
}

int arr[1000] = {0};
int cnt = 0;
void BST::printAllPaths(Node *root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else if (root)
	{
		arr[cnt++] = root->mData;
		printAllPaths(root->left);
		printAllPaths(root->right);
	}
}

void BST::deleteNode(int data)
{
	Node *par = mRoot;
	Node *act = 0;
	if (par->mData > data)
		act = par->left;
	else if (par->mData < data)
		act = par->right;
	while (par)
	{
		if (par->mData == data)
		{
		}
		else if (data > par->mData)
		{
			act = par->right;
		}
		else
		{
			act = par->left;
		}
	}
}