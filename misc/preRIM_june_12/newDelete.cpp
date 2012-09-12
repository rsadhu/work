#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;


class T
{
public:
  T ()
  {
    cout << " T::T\n";
    str = strdup ("testing");
  }

  static  void *operator     new (size_t size)
  {
    cout << " T:: new operator \n";
    T *p = (T *) malloc (sizeof (T));
    return (void *) p;
  }

  static void operator    delete (void *p)
  {
    if (p)
      free (p);
    cout << " delete operator ::\n";
  }

  ~T ()
  {
    cout << "  T::~T\n";
    if (str)
      delete str;
  }
  void display (void)
  {
    cout << " data is ... " << str;
  }

private:
  char *str;
};



int
main (void)
{
  T *t = new T ();
  delete t;
  return 0;
}
