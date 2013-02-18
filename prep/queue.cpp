#include<iostream>
using namespace std;

template<typename T>

class SQueue
{
 public:
 SQueue(){ m_data = new T[m_size=100];front=rear=0;}
 T *operator[](int index);
 SQueue & operator<(T &);
 
 inline bool isEmpty(){ bool ret(false);if(front == rear)ret=true;return ret;}
 inline bool isFull(){ bool ret(false);if(rear == m_size-1) ret = true; return ret;}
 protected:
 void push(T &);
 T &pop(); 
 private:
 T *m_data;
 unsigned m_size;
 unsigned int front ,rear;
};

SQueue & SQueue::operator<(T &d)
{
 if(!isFull())
  push(d);
  return *this;
}


T * SQueue::operator[](unsigned int i)
{
 if(i >=front && i <= rear)
 {
  return m_data[i];
 }
 else
 {
	return NULL;
 } 
}


T & SQueue::pop()
{
 
 return *this;
}

