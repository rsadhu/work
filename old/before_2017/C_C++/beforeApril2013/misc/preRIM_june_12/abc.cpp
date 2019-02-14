#include<iostream>
using namespace std;
class T
{
  int a;
public:
    T ()
  {
    cout << "T::T\n";
  }
  void display ()
  {
    cout << "T::display" << a;
  }
};


int
main (void)
{
  T *t;
  t->display ();
}
