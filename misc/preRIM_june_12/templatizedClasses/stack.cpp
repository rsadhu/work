#include<iostream>
using namespace std;
#define SIZE 512

#ifndef LOG
#define  LOG(x) cout<<x;
#endif

template < class T > class MyStack
{
public:
  MyStack ();
  MyStack & operator < (const T &);
  void push (const T &);
  T & pop ();
  T & peek ();
  inline bool isEmpty ()
  {
    return (m_index == -1 ? true : false);
  }
  inline bool isFull ()
  {
    return (m_index == SIZE - 1 ? true : false);
  }
private:
  T m_data[SIZE];
  int m_index;
};



template < class T > MyStack < T >::MyStack ():m_index (-1)
{
  //memset(&m_data,SIZE,0);
}


template < class T > MyStack < T > &MyStack < T >::operator< (const T & d)
{
  push (d);
  return *this;
}



template < class T > void MyStack < T >::push (const T & d)
{
  if (!isFull ())
    m_data[++m_index] = d;
}

template < class T > T & MyStack < T >::pop ()
{
  if (!isEmpty ())
    return m_data[m_index--];
}



template < class T > T & MyStack < T >::peek ()
{
  if (!isEmpty ())
    return m_data[m_index];
}


int
main (int argc, char *argv[])
{
  MyStack < int >*s = new MyStack < int >;
  s->push (9);
  *s < 8 < 7 < 6 < 5 < 4 < 3 < 2 < 1;
  while (!s->isEmpty ())
    {
      cout << " data  " << s->pop ()<<endl;
    }

  delete s;
  return 0;
}
