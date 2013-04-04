#include<iostream>
using namespace std;



class Test
{
public:
  Test ()
  {
    cout << "Test::Test:: " << this << endl;

  }
  Test (int p):x (p)
  {
    y = 'c';
    Test (x, y);
    cout << "Test::Test::para " << this << endl;
  }

  Test (int a, char b):x (a), y (b)
  {
    cout << "Test::Test::para::2 " << this << endl;
  }

  void speak ()
  {
    cout << " Radio Mirchi :: 1st\n";
  }

  void speak () const
  {
    cout << " Radio Mirchi :: 2nd\n";
  }

private:
  int x;
  char y;
};




int
main (void)
{
  const Test t (9);
  /*t.speak ();
     Test *p = new Test;
     p->speak ();
     Test const *r = new Test ();
     r->speak ();
     delete p;
     delete r; */
  return 0;
}
