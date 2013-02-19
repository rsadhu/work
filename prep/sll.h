#ifndef _SLL_
#define _SLL_
#include<iostream>
using namespace std;


typedef 
enum type
{
		ITER,
		REC
}Type;

template<typename T>	
class Node
{
	public:
	Node(T d):next(NULL),data(d){}
	~Node(){ next = NULL;cout<<"\n Node::~Node\n";}
	Node *next;
	T data;		
};

template<typename T>
class SLL
{	
	Node<T> *m_head;	
	public:
	SLL():m_head(NULL){}
	~SLL();
	SLL &operator<(T );
	void display(void);
	void reverse(Type t);	

	private:		
	void inOrder();	
	void reverseList();
	Node<T> * reverseListRec(Node<T> *,Node<T>*);		
};
template<typename T>
SLL<T>::~SLL()
{
	Node<T> *tra;
	while(m_head)
	{
		 tra= m_head;
    	 m_head= m_head->next;
		 delete tra;
	}
}

template<typename T>
SLL<T> &SLL<T>::operator<(T d)
{
	 if(!m_head)
		m_head = new Node<T>(d);
	 else{
	   Node<T> *tra=m_head;
		for(;tra->next!=NULL;tra=tra->next);
		tra->next = new Node<T> (d);
	 }
	 return *this;
}

template<typename T>
void SLL<T>::display() // using inOrder traversal here 
{
cout<<"\n";
  Node<T> *tra= m_head;
  while(tra)
  {
	  cout<< tra->data <<" " ;
	  tra= tra->next;
  }
cout<<"\n";
}


template<typename T>
void SLL<T>::reverse(Type t)
{ 
	switch(t)
	{
		 case ITER:
		 reverseList();
		 break;
		 case REC:
		 {
		  Node<T> *tra = m_head->next;
	      m_head  = reverseListRec(m_head,tra);
		  cout<<"\n";		  
		 }
		 break;
		 default:
		 break;
	}
}

template<typename T>
void SLL<T>::reverseList()
{
cout<<"\n ReverseList::Iter\n";
	Node<T> *cur,*pre,*tmp;
	pre = m_head;
	cur = pre->next;
	tmp =  NULL;
	while(cur)
	{
		pre->next = tmp;
		tmp = pre;
		pre = cur;
	}
		cur = cur->next;	
	pre->next = tmp;
    tmp = pre;
	m_head = tmp;
}


template<typename T>
Node<T>* SLL<T>::reverseListRec(Node<T> *tra,Node<T> *tail)
{	
	
}

#endif //
