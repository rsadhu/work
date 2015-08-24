#include "stdafx.h"
#include "BST.h"
#include<iostream>
using namespace std;


BST::BST(void):mRoot(0)
{

}

BST::~BST(void)
{

}

BST & BST:: operator <(int d)
{
	if(!mRoot)
	{
		mRoot  = new Node(d);
	}
	else
	{
		addItem(d);
	}
	return  *this;
}

void BST:: addItem(int d)
{
	Node *tra = mRoot;
	while(tra)
	{
     	if(d < tra->data)
		{
			if(tra->left)
				tra=tra->left;
			else
			{
				tra->left = new Node(d);
				break;
			}
		}
		else	
		{
			if(tra->right)
				tra=tra->right;
			else
			{
				tra->right =  new Node (d);
				break;
			}
		}

	}
}

void BST::addItemRec(Node **root,int data)
{
	if(*root)
	{
		if(data<(*root)->data)
		{
			addItemRec(&((*root)->left),data);
		}
		else
		{
			addItemRec(&((*root)->right),data);
		}
	}
}

void BST:: display(Type t)
{
	switch(t)
	{
	default:
		inOrder(mRoot);
		break;
	}
}

void BST:: inOrder(Node *root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" " ;
		inOrder(root->right);
	}
}

void BST:: preOrder(Node *)
{

}


void BST:: postOrder(Node *)
{

}