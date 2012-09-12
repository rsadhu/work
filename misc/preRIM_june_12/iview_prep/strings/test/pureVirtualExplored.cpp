#include<iostream>
using namespace std;
class Base
{
public:
  virtual void display () = 0;
    virtual ~ Base ()
  {
    cout << " Base::~Base\n";
  }
};

void Base::display()
{
 cout<<" BAse:: Display:: \n";
}
class Der:public Base
{
public:
  void display ()
  {
    cout << " Der::display\n";
  }
   ~Der ()
  {
    cout << "Der::~Der\n";
  }
};



int
main (void)
{
  Base *b = new Der;
  b->display ();
  delete b;
  return 0;
}
