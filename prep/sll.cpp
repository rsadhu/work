#ifndef _SLL_
#define _SLL_
#include<iostream>
using namespace std;


typedef 
enum type
{
		UP,
		DOWN
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
	void reverseListRec();		
};
template<typename T>
SLL<T>::~SLL()
{
	Node<T> *tra;
	while(m_head)
	{
		 tra= m_head;
		 m_head= m_head;
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
  Node<T> *tra= m_head;
  while(tra)
  {
	  cout<< tra->data <<" " ;
	  tra= tra->next;
  }
}

template<typename T>
void SLL<T>::reverse(Type t)
{ 
	switch(t)
	{
		 case UP:
		 reverseList();
		 break;
		 case DOWN:
		 reverseListRec();
		 break;
		 default:
		 break;
	}
}

template<typename T>
void SLL<T>::reverseList()
{
	
}

template<typename T>
void SLL<T>::reverseListRec()
{
	
}


int main(void)
{
	 SLL<int> sl;
	 sl<1<2<3<4<5<6<7<8<9;
	 sl.display();
	 return 0;
}

#endif //
