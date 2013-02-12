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
void removeNode(int d);
protected:
void removeLeaf(Node **,int );
void createTree(Node *,Node *newN);
void inOrderRec(Node *);
void bfs(Node *);
void dfs(Node *);

private:
Node *m_root;

};



void BST::createTree(Node *head,Node * newN)
{
 if(head)
 {
	if(newN->data > head->data)
	{
		if(head->right== NULL)
			head->right =  newN;
		else
			createTree(head->right,newN);
     }
	else if(newN->data < head->data)
	{
		if(head->left == NULL)
			head->left =  newN;
		else
			createTree(head->left,newN);
    }
 }
}

//bt<20<30<35<25<10<15<5;
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
 if(!m_root)
	m_root = new Node(d);
else
{
 Node * tmp =  new Node (d);
 createTree(m_root,tmp);	  
 }
 return *this;
}

void BST::removeLeaf(Node **head,int d)
{
 if(*head)
 {
  if((*head)->data == d)
  {
   cout<<" deleted :: head"<<(*head)->data<<"\n";
   delete *head;
   *head = NULL;
  }
  else
  {
    if(d < (*head)->data){
		cout<<" take left :: "<<(*head)->data<<"\n";
		removeLeaf(&(*head)->left,d);
		}
	else if(d > (*head)->data){
		cout<<" take right :: "<<(*head)->data<<"\n";
		removeLeaf(&(*head)->right,d);		
		}
  }
  cout<<"\n if else end\n";
  }
  cout<<" end\n";
}

void BST::removeNode(int d)
{
 removeLeaf(&m_root,d);
}
void BST::inOrderRec( Node *root)
{

if(root){
inOrderRec(root->left);
cout<<root->data << " ";
inOrderRec(root->right);
}
}

void BST ::bfs(Node *head)
{
 
}
void BST::display()
{
 inOrderRec(m_root);
 cout<<"\n";
 bfs(m_root);
}
int main(void)
{
 BST bt;
 bt<20<30<35<25<10<15<5;
 bt.display();
 
 bt.removeNode(5);
 bt.display();
 return 0;
}
