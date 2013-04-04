#include<iostream>
using namespace std;

class A;

class T
{
public:
  T ():m_data (999)
  {
  }
private:
  int m_data;
  friend class A;
};

class A
{
public:
  void display (T & t)
  {
    cout << "\nA:: m_data :: " << t.m_data << endl;
    t.m_data = 10;
    cout << "\nA:: m_data :: " << t.m_data << endl;
  }
};


int
main (void)
{
  T t;
  A a;
  a.display (t);
  return 0;
}
