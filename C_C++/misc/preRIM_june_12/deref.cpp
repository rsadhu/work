#include<iostream>
using namespace std;


class T
{
public:
  T ()
  {
    cout << "T::T\n";
    f = 3.17;
  }
  void display ()
  {
    cout << "T::display\n";
  }
  ~T ()
  {
    cout << "T::~T\n";
  }
private:
  int *d;
  float f;
};



int
main (void)
{
  T *t = NULL;
  t->display ();
  delete t;
  return 0;
}
