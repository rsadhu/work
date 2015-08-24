#include"stdafx.h"
#include<queue>
#include<iostream>
using namespace std;

#include "BST.h"



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
		 //mRoot 
			//Node *tmp = addItemRec(mRoot,d);
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

Node * BST::addItemRec(Node *root,int data)
{
	if(!root)
		return new Node(data);
	else{
		if(data < root->data)
		{
			root->left = addItemRec(root->left,data);
		}
		else
		{
			root->right = addItemRec(root->right,data);
		}
	}
}

void BST:: display(Type t)
{
	cout<<endl;
	switch(t)
	{
	case LEVEL_ORDER:
		levelOrder(mRoot);
		break;
	case I_INORDER:
		inOrderIter(mRoot);
		break;
	case I_PREORDER:
		preOrderIter(mRoot);
		break;
	case I_POSTORDER:
		inOrderIter(mRoot);
		break;
	case R_INORDER:
		inOrder(mRoot);
		break;
	case R_PREORDER:
		inOrder(mRoot);
		break;
	case R_POSTORDER:
		inOrder(mRoot);
		break;
	default:
		inOrder(mRoot);
		break;
	}
}

void BST::inOrderIter(Node *root)
{

}

void BST::preOrderIter(Node *root)
{

}

void BST::postOrderIter(Node *root)
{

}

void BST::levelOrder(Node *root)
{
	queue<Node *>q;
	q.push(root);
	while(root && !q.empty())
	{
		root = q.front();
		cout<<root->data<<" ";
		q.pop();

		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);			
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

void BST:: preOrder(Node *root)
{
	if(root)
	{
		cout<<root->data<<" " ;
		inOrder(root->left);	
		inOrder(root->right);
	}
}


void BST:: postOrder(Node *root)
{
	if(root)
	{	
		inOrder(root->left);	
		inOrder(root->right);
		cout<<root->data<<" " ;
	}
}




int main(void)
{
	BST t;
	t<9<5<13<11<15<7<3;
	//t.display(R_INORDER);
	for(int i=0;i<7;i++)
	t.display((Type)i);
	return 0;
}