#include <iostream>
using namespace std;

template <typename T>
class auto_ptr
{
public:
  auto_ptr(T *obj)
  {
    ptr = obj;
  }
  T *operator->()
  {
    return ptr;
  }
  T &operator*()
  {
    cout << "auto_ptr:: operator *\n";
    return *ptr;
  }
  ~auto_ptr()
  {
    delete ptr;
  }

private:
  T *ptr;
};

class A
{
public:
  A()
  {
    cout << "A::A\n";
    m_data = 9;
  }
  ~A()
  {
    cout << "A::~A\n";
  }
  void display()
  {
    cout << " A:: display\n";
  }
  bool operator>(const A &rhs)
  {
    cout << " operator > :: A\n";
    if (m_data > rhs.m_data)
      return true;
    return false;
  }

private:
  int m_data;
};

int main(void)
{

  auto_ptr<A> obj1(new A);
  auto_ptr<A> obj2(new A);
  if (*obj1 > *obj2)
  {
    cout << " greateer :: \n";
  }
  else
  {
    cout << "lesser than\n";
  }

  return 0;
}
