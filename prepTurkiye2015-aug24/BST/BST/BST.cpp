#include"stdafx.h"
#include<queue>
#include<stack>
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
		//addItem(d);
		addItemRec1(&mRoot,d);
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

/*
 t<9<5<13<11<15<7<3; 
*/

void BST::addItemRec1(Node **root,int d)
{
	if(!(*root))
		*root =  new Node (d);
	else
	{
		if(d < (*root)->data)
		{
			addItemRec1(&((*root)->left),d);
		}
		else
		{
			addItemRec1(&((*root)->right),d);
		}
	}
}

/* Below code needs change to mk it wrk */

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
		preOrder(mRoot);
		break;
	case R_POSTORDER:
		postOrder(mRoot);
		break;
	default:
		inOrder(mRoot);
		break;
	}
}

void BST::inOrderIter(Node *root)
{
	stack<Node *>st;
	
	while(root ||!st.empty())
	{
		if(root){			
			st.push(root);
			root=root->left;
		}
		else
		{			
			root =  st.top();
			cout<<root->data<<" ";
			st.pop();		
			root = root->right;
		}		
	}
}

void BST::preOrderIter(Node *root)
{

	stack<Node *>st;	
	st.push(root);

	while(!st.empty())
	{
		root =  st.top();
		cout<<root->data<<" ";
		st.pop();
		if(root->right)
			st.push(root->right);
		if(root->left)
			st.push(root->left);
	}
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


void BST::spiralOrder(Node *root)
{

}


//#define __HR__  1

#ifdef __HR__
int hackerRank_stick();
void caeserString();
void cavityMap();
void matrixMan();
#endif

int main(void)
{	
#ifndef __HR__
	BST t;
	//jhj
	t<9<5<13<11<15<7<3;
	//t.display(I_INORDER);
	t.display(R_PREORDER);
	t.display(I_PREORDER);
	//for(int i=0;i<7;i++)
//	t.display((Type)i);
#elif __HR__
	jkjk
	//hackerRank_stick();
	//caeserString();
	//cavityMap();
	matrixMan();
#endif

	return 0;
}