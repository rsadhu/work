#include <iostream>
using namespace std;
#define SIZE 100
template <typename T>
class queue
{
  int m_index;
  T *m_array;
  bool m_empty;

public:
  queue() : m_index(-1)
  {
    m_array = new T[SIZE];
    m_empty = true;
  }
  void push(T &);
  void pop();
  T &front();
  bool empty()
  {
    if (m_index != -1)
      m_empty = false;
    return m_empty;
  }

  ~queue()
  {
    delete[] m_array;
  }
};

template <typename T>
void queue<T>::push(T &rhs)
{
  if (m_index < SIZE)
  {
    cout << "\nPushing the element :: " << (&rhs);
    m_array[++m_index] = rhs;
  }
  else
  {
    cout << "Queue is Full\n";
  }
}

template <typename T>
T &queue<T>::front()
{
  if (m_index > -1)
  {
    cout << "\nthe element :: " << &(m_array[m_index]);
    return m_array[m_index];
  }
  else
  {
    cout << " Queue is Empty\n";
  }
}

template <typename T>
void queue<T>::pop()
{
  if (m_index > -1)
  {
    m_index--;
  }
  else
  {
    cout << " QUeue is Empty\n";
  }
}

class Test
{
public:
  void display() { cout << "\n Test:: display\n"; }
};

int main(void)
{
  queue<Test> c;

  for (int i = 0; i < SIZE; i++)
    c.push(*(new Test));
  Test *tmp;
  for (int i = 0; i < SIZE; i++)
  {
    c.pop();
    tmp = &(c.front());
    tmp->display();
  }
  return 0;
}
