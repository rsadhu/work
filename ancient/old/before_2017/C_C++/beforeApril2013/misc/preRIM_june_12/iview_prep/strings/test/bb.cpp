#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

using namespace std;

struct stud
{
  int a;
  int b;
};

class U
{
public:
  U()
  {
    s = sizeof(struct stud);
    p = (struct stud *)malloc(s);
  }
  ~U()
  {
    free(p);
  }
  struct stud *data()
  {
    return p;
  }
  size_t size()
  {
    return s;
  }

private:
  struct stud *p;
  size_t s;
};

class T
{
public:
  T()
  {
    cout << "T:T:\n";
    p = NULL;
  }
  ~T()
  {
    cout << "T:~T:\n";
    delete p;
  }
  int &number()
  {
    p = new int;
    *p = 100;
    return *p;
  }

private:
  int *p;
};

class ABC
{
public:
  ABC(int a){};
  void readWrite() { cout << " ABC::readWrite\n"; }
  void readWrite() const { cout << "ABC::readWrite---1\n"; }
};
int main(void)
{
  // const int &i = T ().number ();
  // cout << " number is .. " << i << endl;
  /*  U u;
    memset (u.data (), 0, u.size ());
    cout << u.data ()->a << endl << u.data ()->b << endl;

     int *n = new int;
     free(n);*/

  const ABC a(1);
  a.readWrite();

  return 0;
}
