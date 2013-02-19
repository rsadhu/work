#ifndef _SLL_
#define _SLL_
#include<iostream>
using namespace std;

//enum for iterative and recursive reversal function
typedef 
enum type
{
	ITER,
	REC
}Type;

//Link List Class
template<typename T>	
class Node
{
	public:
	Node():next(NULL){}
	Node(T d):next(NULL),data(d){}
	~Node(){ next = NULL;}
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
	Node<T> * reverseListRec(Node<T> *);		
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
        	 m_head = reverseListRec(m_head);
	         cout<<"\n";		  
	 }
	 break;
	 default:
         cout<<"	default  entered : try again\n";
	 break;
	}
}

template<typename T>
void SLL<T>::reverseList()
{
	Node<T> *cur,*pre,*tmp;
	pre = m_head;
	cur = pre->next;
	tmp =  NULL;
	while(cur)
	{
		pre->next = tmp;
		tmp = pre;
		pre = cur;
		cur = cur->next;	
        }
	pre->next = tmp;
        tmp = pre;
	m_head = tmp;
}


template<typename T>
Node<T>* SLL<T>::reverseListRec(Node<T> *tra)
{	
    Node<T>* result;
    if(!(tra && tra->next)) 
        return tra;

    result = reverseListRec(tra->next);
    tra->next->next = tra;
    tra->next = NULL;
    return result;
}

#endif //
