#include <iostream>
using namespace std;

class Test
{
public:
  // Test (int a);
  Test() : x(*p), p(new int)
  {
    *p = 1000;
  }

private:
  int *p;

public:
  int &x;

public:
  void display()
  {
    cout << " Test: a" << x;
  }
};

/*Test::Test ()
{
  cout << " Test::Test" << "this : " << this << endl;
}

Test::Test (int a)
{
  cout << " Test::para\n";
}*/

int main(void)
{
  // Test a;
  Test a; //=  new Test();
  a.display();
  a.x = 99999;
  a.display();
  return 0;
}
