#include<iostream>
#include<string.h>

using namespace std;

#define SIZE 512
template < class T > class MyQueue
{
public:
  MyQueue ();
  T deQueue ();
  bool enQueue (const T &);
  MyQueue & operator < (const T &d){ enQueue (d); return *this;}
  inline bool isFull ()
  {
    return (m_index == SIZE - 1 ? true : false);
  }
  inline bool isEmpty ()
  {
    return (m_index == -1 ? true : false);
  }
private:
  T m_data[SIZE];
  int m_index;
};


template < class T > MyQueue < T >::MyQueue ()
{
  memset (m_data, 0,SIZE );
  m_index = -1;
}


template < class T > T MyQueue < T >::deQueue ()
{
  if (!isEmpty ())
    return m_data[m_index--];
}


template < class T > bool MyQueue < T >::enQueue (const T & d)
{
  if (!isFull ())
    return m_data[++m_index] = d;
}


int main(int argc, char *argv[])
{
	MyQueue <int > *que  =  new MyQueue <int>;

	*que <1<2<3<4<5<6<7<8<9;
	while(!que->isEmpty())
	{
		cout<<" data  :: "<<que->deQueue()<<endl;
	}
	return 0;
}
