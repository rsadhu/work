#include<iostream>
using namespace std;


class temp
{
public:
  temp ()
  {
    cout << "temp:: temp\n";
  }
   ~temp ()
  {
    cout << "temp::~temp\n";
  }
};

class Test
{
public:
  Test ()
  {
    cout << "Test:Test\n";
//    p = new temp;
  }
  static temp *getInstance ()
  {
    return &p;
  }
  static temp p;
};

//temp *Test::p =
temp Test::p;

int
main (void)
{
  Test    t;
  temp *    p = Test::getInstance ();
  char *    ptr = "testing this string ";
  char    ch = ptr[0];
  cout << ch << endl;
  return 0;
}
