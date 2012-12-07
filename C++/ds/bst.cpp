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
private:
Node *m_root;
};

BST & BST::operator<(int d)
{
   Node *tmp  = m_root;
   if(!m_root)
   m_root = new Node(d);
   
}


int main(void)
{
 BST bst;
 bst<10<5<15<8<12<3<18;
 return 0;
}