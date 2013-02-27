#include<iostream>
using namespace std;

template<typename T>

class SQueue
{
 public:
 SQueue(){ m_data = new T[m_size=100];m_front=m_rear=0;}
 T *operator[](unsigned int index);
 SQueue & operator<(unsigned int );
 
 inline bool isEmpty(){ bool ret(false);if(m_front == m_rear)ret=true;return ret;}
 inline bool isFull(){ bool ret(false);if(m_rear == m_size-1) ret = true; return ret;}
 protected:
 void push(T &);
 T &pop(); 
 private:
 T *m_data;
 unsigned m_size;
 unsigned int m_front ,m_rear;
};


template<typename T>
SQueue<T> & SQueue<T>:: operator<(unsigned int )
{
return *this;
}

template<typename T>
T * SQueue<T>::operator[](unsigned int i)
{
 if(i >=m_front && i <= m_rear)
 {
  return m_data[i];
 }
 else
 {
	return NULL;
 } 
}


template<typename T>
T & SQueue<T>::pop()
{
 
 return *this;
}


int main(void)
{
    SQueue<int > q;
    q<1<2<3<4<5<6;
    return 0;
}
