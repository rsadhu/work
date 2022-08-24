#include <iostream>

using namespace std;

class A
{
public:
  A() : p(NULL), start(9)
  {
    cout << " A::A\n";
    A(start);
  }
  A(int x)
  {
    cout << " A::A::para\n";
    p = new int;
    *p = start;
  }
  ~A()
  {
    delete p;
  }
  int &compute()
  {
    int q[30];

    for (int i = 2; i < 30; i++)
    {
      q[i] = q[i - 1] + q[i - 2];
    }
    if (!p)
      p = new int;
    *p = q[30];
    return *p;
  }

private:
  int *p;
  int start;
};

class Test
{
public:
  explicit Test() //: x(9)
  {
    x = 9;
    cout << " Test::Test\n";
    //    Test (x);
    Test(10);
  }
  explicit Test(int a)
  {
    cout << " Test::para\n";
  }

private:
  int x;
};

int main(void)
{
  //  const int &t = A ().compute ();
  // cout << " A::t " << t;
  Test a;
  //  A a;
  return 0;
}
