#include<iostream>
using namespace std;
template<typename T>

#define MAX 100
class Stack
{
T m_arr[MAX];
int m_top;
public:
Stack():m_top(-1){}
void push(T d);
T  pop();
bool isEmpty();
inline int size(){ return m_top;}
};

template<typename T>
void Stack<T>::push(T d)
{
if(m_top<MAX)
m_arr[++m_top]=d;
}

template<typename T>
T Stack<T>::pop()
{
if(m_top>-1)
return m_arr[m_top--];
}

template<typename T>
bool Stack<T>::isEmpty()
{
bool ret(false);
if(m_top==-1)
ret = true;
return ret;
}

void stackint()
{
 Stack<int> s;
 
 for(int i=0;i<10;i++)
  s.push(i);
  
 int sz = s.size();
 
 for(int i=0;i<sz;i++)
 cout<<s.pop()<<" " <<i<<endl; 
 cout<<"\n";  
}

void stackintptr()
{
 Stack<int *>sip;
 for(int i=0;i<10;i++)
  sip.push(&i);
  
 int sz = sip.size();
 
 for(int i=0;i<sz;i++)
 cout<<*sip.pop()<<" " <<i<<endl; 
 cout<<"\n";   
}

typedef 
struct node
{
int a;
double b;
node(int p,double q):a(p),b(q){}
}Node;

void stackObj()
{
 Stack<Node *> sn;
 for(int i=0;i<10;i++)
 {
  Node *tmp = new Node(i,10.3*i);
  sn.push(tmp);
 }
 int sz= sn.size();
 
 for(int i=0;i<sz;i++)
 {
  Node *tmp = sn.pop();
  if(tmp)
  {
	cout<< "\n Node:a =  "<<tmp->a<<"\n Node::b = "<<tmp->b<<"\n";
  }
 }
}

int main(void)
{
 stackint();
 stackintptr();
 stackObj();
 return 0;
}

