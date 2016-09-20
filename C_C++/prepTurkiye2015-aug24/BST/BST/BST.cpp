#include"stdafx.h"
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

#include "BST.h"

#define __HR__ 1
#ifdef __HR__

int hackerRank_stick();
void caeserString();
void cavityMap();
void matrixMan();
void anagram();
void twoStrings();
void mcqs();
void testChar();
void anagramZpalindrome();

#elif __HR__


BST::BST(void):mRoot(0)
{

}

BST::~BST(void)
{

}


BST & BST:: operator <(int d)
{
	if(!mRoot)
		mRoot  = new Node(d);	
	else
		addItemRec1(&mRoot,d);	
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

double BST::highBranch()
{
	stack<Node*>st;
	vector<int>v;
	Node *tra =  mRoot;
	double sum=0;
	while(tra || !st.empty())
	{
		if(tra)
		{
			st.push(tra);
			//v.push_back(tra->data);
			sum+=tra->data;
			tra =  tra->left;
		}
		else
		{
			tra =  st.top();
			sum-=tra->data;
		}
	}	

	//double sum=0;
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
		sum+=*it;
	return sum;
}

double BST::sumOfNodes()
{
	stack<Node *> st;
	Node *tra=mRoot;
	double sum=0;
	while(tra ||!st.empty())
	{
		if(tra)
		{
			st.push(tra);
			tra = tra->left;
		}
		else
		{
			tra = st.top();
			sum+=tra->data;
			st.pop();
			tra =  tra->right;			
		}
	}
	return sum;
}
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
	case SPIRAL_ORDER:
		spiralOrder(mRoot);
		break;
	case PRINTALLPATHS:
		printAllPaths(mRoot);
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
	stack<Node *>st1;
	stack<Node *>st2;
	st1.push(root);
	while(!st1.empty()|| !st2.empty())
	{		
		Node *tmp;

		while(!st1.empty())
		{
			tmp =  st1.top();
			cout<<tmp->data<<" ";
			st1.pop();
			if(tmp->left)
				st2.push(tmp->left);
			if(tmp->right)
				st2.push(tmp->right);
		}

		while(!st2.empty())
		{
			tmp =  st2.top();
			cout<<tmp->data<<" ";
			st2.pop();

			if(tmp->right)
				st1.push(tmp->right);
			
			if(tmp->left)
				st1.push(tmp->left);
		}
	}

}




int  isBST(Node *root)
{
	static Node* prev  = NULL;

  if(root==NULL)
    return 1;

  if(!isBST(root->left))
    return 0;

  if(prev!=NULL && root->data<=prev->data)
    return 0;

  prev = root;
  return isBST(root->right);
}


bool BST::isBST()
{

	if(::isBST(mRoot)==0)
	{
		return 0;
	}
	else
		return 1;

	//bool ret(false);
	queue<int> q;
	stack<Node*> st;
	Node *tra =  mRoot;
	while(tra || !st.empty())
	{
		if(tra)
		{
			st.push(tra);
			tra =  tra->left;
		}
		else
		{
			tra =  st.top();
			//cout<<tra->data<<" ";
			q.push(tra->data);
			tra = tra->right;
			st.pop();
		}
	}

	cout<<endl;
	int size =  q.size();
	while(1){
		int a,b;
		if(!q.empty())
		{
			a =  q.front();
			q.pop();
		}
		else
			break;
		if(!q.empty())
		{
			b  = q.front();
			q.pop();
		}
		else
			break;
		if(a>b)
			return false;		
	}
	return true;
}


void BST::printAllPaths(Node *root)
{

}

#endif

int main(void)
{	
#ifndef __HR__
	BST t;
	
	t<9<5<13<11<15<7<3;
	t.display(PRINTALLPATHS);

	//t.display(I_INORDER);
	//t.display(R_PREORDER);
	//t.display(I_PREORDER);
	//for(int i=0;i<7;i++)
	//t.display((Type)i);
	//t.display(SPIRAL_ORDER);
	//cout<<t.isBST()<<endl;	
	//cout<<endl<<"sum of nodes :: "<<t.sumOfNodes()<<endl;
#elif __HR__	
	//hackerRank_stick();
	//caeserString();
	//cavityMap();
	//matrixMan();
	//anagram();
	//twoStrings();
//	mcqs();
//	 testChar();
	 anagramZpalindrome();
#endif

	return 0;
}