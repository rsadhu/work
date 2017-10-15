#include "stdafx.h"
#include "BST.h"
#include<iostream>


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

Node *BST::add(Node *, int)
{
	return nullptr;
}


void BST::display(TYPE t)
{
	switch (t)
	{
	case TYPE::INORDER_R:
		inOrderR(mRoot);
		break;
	}
}

void BST::inOrderR(Node *root)
{
	if (root)
	{
		inOrderR(root->left);
		std::cout << root->mData<<"  ";
		inOrderR(root->right);
	}
}