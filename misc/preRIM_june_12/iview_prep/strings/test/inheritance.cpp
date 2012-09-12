#include<iostream>
using namespace std;


class Dad
{
public:
  Dad ()
  {
    cout << "Dad::Dad\n";
  }
  void dadFun ()
  {
    cout << "Dad:: hi \n";
  }
  virtual ~ Dad ()
  {
    cout << "Dad::~Dad\n";
  }
};


class Son:public Dad
{
public:
  Son ()
  {
    cout << "Son::Son\n";
  }
   ~Son ()
  {
    cout << "Son::~Son\n";
  }
  virtual void SonFun () = 0;
};

void
Son::SonFun ()
{
  cout << "Son::SonFun\n";
}

class GrandSon:public Son
{
public:
  GrandSon ()
  {
    cout << "GrandSon::Grandson\n";
  }
  void SonFun ()
  {
    cout << "GrandSon:::Son::hi\n";
  }
  void GrandSonFun ()
  {
    cout << "GrandSon::hi\n";
  }
  ~GrandSon ()
  {
    cout << "GrandSon::~GrandSon\n";
  }
};


int
main (void)
{
  Son *d = new GrandSon ();
  d->SonFun ();
  delete d;
  return 0;
}
