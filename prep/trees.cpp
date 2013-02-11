#include<iostream>
using namespace std;

class Node
{
 public:
 Node(int d):data(d),left(0),right(0){}
 int data;
 Node *left,*right;
};

class BST
{
public:
BST():m_root(NULL){}
BST& operator<(int d);

void display();

private:
Node * createTree(Node *,int d );
void inOrderRec(Node *);
void bfs();
void dfs();

Node *m_root;
};



Node * BST::createTree(Node *head,int d)
{
 if(head)
 {
	if(d > head->data)
		head->right = createTree(head->right,d);
	else if(d < head->data)
		head->left = createTree(head->left,d);
 }
 
 return  new Node(d);
}

BST & BST::operator<(int d)
{
#ifdef R
 if(!m_root)
  m_root = new Node (d);
 else 
 {
  Node *tra = m_root;
  while(tra)
  {
   if(d > tra->data)
   {
     if(tra->right)
	  tra =  tra->right;
	 else
	 {
	  tra->right =  new Node (d);
	  break;
	 }
   }   
   else if(d < tra->data)
   {
    if(tra->left)
	 tra=  tra->left;
	 else
	 {
	  tra->left =  new Node (d);
	  break;
	 }
   }
  }  
 }
 #endif
 m_root =  createTree(m_root,d);
 return *this;
}

void BST::inOrderRec( Node *root)
{

if(root){
inOrderRec(root->left);
cout<<root->data << " ";
inOrderRec(root->right);
}
}


void BST::display()
{
 inOrderRec(m_root);
}
int main(void)
{
 BST bt;
 bt<20<30<35<25<10<15<5;
 bt.display();
 return 0;
}