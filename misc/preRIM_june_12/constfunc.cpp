#include<iostream>
using namespace std;

class T
{
public:
  T ():y(888)
  {
    cout << "T:T\n";
  }
  virtual void display () const = 0;
  virtual void display1 () const ;
 private:
	int y;
};

void T::display1() const
{
 int *z  = const_cast<int *>(&y);
 *z = 100;
  
  cout<<" T:: y :: "<<y<<endl;
}


class der:public T
{
public:
  der ():x (999)
  {
    cout << "der ::der\n";
  }
  void display () const
  {
    cout << " der::x :: " << x << endl;
  }
private:
  int x;
};

int
main (void)
{
  T *t = new der;
  t->display ();
  t->display1 ();
  return 0;
}
