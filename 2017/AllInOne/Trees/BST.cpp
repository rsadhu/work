#include "stdafx.h"
#include "BST.h"
#include<iostream>
#include<stack>
#include<queue>


BST::BST()
{
}


BST::~BST()
{
}



void BST::add(int d)
{
	if (!mRoot)
	{
		mRoot = new Node(d);
	}
	else
	{
		Node *tra = mRoot;
		while (tra)
		{
			if (d < tra->mData)
			{
				if (!tra->left)
				{
					tra->left = new Node(d);
					break;
				}
				else
				{
					tra = tra->left;
				}
			}
			else
			{
				if (!tra->right)
				{
					tra->right = new Node(d);
					break;
				}
				else
				{
					tra = tra->right;
				}
			}
		}
	}
}

BST & BST::operator<(int d)
{
	mRoot = add(mRoot, d);
	return *this;
}

Node *BST::add(Node *root, int d)
{
	if (!root)
		return new Node(d);
	else
	{
		if (d < root->mData)
			root->left = add(root->left, d);
		else
			root->right = add(root->right, d);
	}
	return root;
}


void BST::display(TYPE t)
{
	switch (t)
	{
	case TYPE::INORDER_R:
		inOrderR(mRoot);
		break;
	case TYPE::PREORDER_R:
		preOrderR(mRoot);
		break;
	case TYPE::POSTORDER_R:
		postOrderR(mRoot);
		break;
	case TYPE::INORDER_I:
		inOrderI(mRoot);
		break;
	case TYPE::PREORDER_I:
		preOrderI(mRoot);
		break;
	case TYPE::POSTORDER_I:
		postOrderI(mRoot);
		break;
	case TYPE::BFS:
		bfs(mRoot);
		break;
	case TYPE::SPIRAL:
		spiral(mRoot);
		break;
	}
	std::cout << "\n";
}

void BST::preOrderR(Node *root)
{
	if (root)
	{
		std::cout << root->mData << "  ";
		preOrderR(root->left);
		preOrderR(root->right);
	}
}


void BST::postOrderR(Node *root)
{
	if (root)
	{
		postOrderR(root->left);
		postOrderR(root->right);
		std::cout << root->mData << "  ";
	}
}

void BST::inOrderR(Node *root)
{
	if (root)
	{
		inOrderR(root->left);
		std::cout << root->mData << "  ";
		inOrderR(root->right);
	}
}




void BST::bfs(Node *root)
{

}


void BST::mirror(Node*root)
{

}

void BST::topView(Node *root)
{


}


void BST::spiral(Node *root)
{
	std::stack<Node*> st1, st2;
	if (root)
	{
		st1.push(root);
		Node *tmp;
		while (!st1.empty() || !st2.empty())
		{
			while (!st1.empty())
			{
				tmp = st1.top();
				std::cout << tmp->mData << "  ";
				st1.pop();
				if (tmp->left)
					st2.push(tmp->left);
				if (tmp->right)
					st2.push(tmp->right);
			}
			while (!st2.empty())
			{
				tmp = st2.top();
				st2.pop();
				std::cout << tmp->mData << "  ";
				if (tmp->right)
					st1.push(tmp->right);
				if (tmp->left)
					st1.push(tmp->left);
			}
		}
	}
}


void BST::levelOrder(Node *root)
{
	std::queue<Node *>q;
	if (root)
		q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		std::cout << root->mData << " ";
		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
	}
}

void BST::preOrderI(Node *root)
{
	std::stack<Node *>st;
	st.push(root);

	while (!st.empty())
	{
		root = st.top();
		std::cout << root->mData << " ";
		st.pop();
		if (root->right)
			st.push(root->right);
		if (root->left)
			st.push(root->left);
	}
}


void BST::postOrderI(Node *root)
{
	if (root)
	{

	}
}

void BST::inOrderI(Node *root)
{
	std::stack<Node *> st;
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
			std::cout << root->mData << " ";
			st.pop();
			root = root->right;
		}
	}
}