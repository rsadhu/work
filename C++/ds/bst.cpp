/*
Author:rsadhu
Date:07/12/2012
Completely for learning purposes.
*/
#include<iostream>
using namespace std;

struct  Node
{
 Node *left,*right;
 int data;
 Node(int d):left(0),right(0),data(d){}
};

class BST
{
public:
BST & operator<(int d);
void displayAll()
{
cout<<"\nINORDER\n";
 inOrderRec(m_root);
 cout<<"\nPREORDER\n";
 preOrderRec(m_root);
 cout<<"\nPOSTORDER\n";
 postOrderRec(m_root);
 cout<<"\n";
}
protected:
void inOrderRec(Node *node);
void preOrderRec(Node *node);
void postOrderRec(Node *node);
private:
Node *m_root;
};

void BST::inOrderRec(Node *n)
{
 if(n!=NULL){
 inOrderRec(n->left);
 cout<<n->data<<"  ";
 inOrderRec(n->right);
}
}

void BST::preOrderRec(Node *n)
{
 if(n!=NULL){
 cout<<n->data<<"  ";
 preOrderRec(n->left);
 preOrderRec(n->right);
}
}


void BST::postOrderRec(Node *n)
{
 if(n!=NULL){
 postOrderRec(n->left); 
 postOrderRec(n->right);
 cout<<n->data<<"  ";
}
}


BST & BST::operator<(int d)
{  
   if(!m_root){
   m_root = new Node(d);
  }
  else{   
   Node *tmp  = m_root;   
   
   while(tmp)
   {    
    if(d > tmp->data ){		
		if(tmp->right == NULL){
			tmp->right =  new Node(d);		
			break;		
		}
		else
			tmp= tmp->right;		
		}
	else if(d < tmp->data)
	{		
		if( tmp->left == NULL){
			tmp->left =  new Node(d);			
			break;
		}
		else 
		tmp = tmp->left;
	}		
   }
   }
   return *this;   
}





int main(void)
{
 BST bst;
 bst<10<5<15<8<12<3<18;
 bst.displayAll();
 return 0;
}