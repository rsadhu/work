#include <iostream>

using namespace std;

class Base
{
  int a;

public:
  int b;
  Base()
  {
    a = 10;
    b = 11;
  }
  virtual ~Base(){};
  friend class Derived;
};

class Derived : private Base
{
public:
  Derived()
  {
    cout << b << endl;
  }
  void p(Base b)
  {
    cout << b.a << endl;
  };
  virtual ~Derived(){};
};

int main()
{
  Base b;
  Derived d;
  d.p(b);
  return 0;
}
