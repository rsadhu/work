#include<iostream>
using namespace std;

class Node
{
public:
 Node(int d):data(d),next(NULL){}
 int data;
 Node *next;
};

class SLL
{
 public:
 SLL():m_head(NULL){}
 SLL &operator <(int d);
 inline Node *internal(){ return m_head;}
 void display();
 void insertAt(unsigned int i);
 void removeAt(unsigned int i); 
 void reverseList();
 private:
 void addIter(Node *,int );
 void addRec(Node *,int );
 void mergeTwo(Node *,Node *); 
 private:
 Node *m_head;
};



void SLL::addIter(Node *head,int d)
{
 while(head->next)
 {
  head =  head->next;
 }
 head->next =new Node (d);
}

void SLL::addRec(Node *head,int d)
{
if(head){
 if(head->next == NULL)
 {
   head->next = new Node(d);
 }
 addRec(head->next,d);
}
}



SLL & SLL::operator<(int d)
{
 if(!m_head)
 { 
	m_head = new Node(d);
 }
 else
 {
  addIter(m_head,d);  
 }
 return *this;
}

void SLL::display()
{
 Node *tra=m_head;
 while(tra)
 {
  cout<<tra->data<<" " ;
  tra = tra->next;
 }
 cout<<"\n";
}


int main(void)
{
 SLL sl;
 sl<1<2<3<4<5<6<7<8<9;
 sl.display();
 return 0;
}
