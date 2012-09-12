#include<iostream>
using namespace std;


class Base
{
public:
  Base ()
  {
    cout << " Base:: Base\n";
    m_data = 0;
  }
  Base (const Base & rhs)
  {
  }
  Base & operator = (const Base & rhs)
  {
  }
  void setValue (int val = 9)
  {
    cout << " Base:: setValue\n";
    m_data = val;
  }
public:
  virtual void display (int a, float b = 9, unsigned int ch = 8)
  {
    cout << " Base:: Display\n";
    cout << "a " << a << "b :: " << b << " ch :: " << ch << endl;
  }

  virtual void BaseVirtual (void)
  {
    cout << " Base::BaseVirtual \n";
  }

public:
  bool operator == (const Base & rhs)
  {
  }

  friend bool operator < (const Base & lhs, const Base & rhs)
  {
    if (lhs.m_data < rhs.m_data)
      return true;
    return false;
  }
  virtual bool operator > (const Base & rhs)
  {
    if (m_data > rhs.m_data)
      return true;
    return false;
  }
private:
  int m_data;
};

class Der:public Base
{
public:
  Der ()
  {
    cout << " Der::Der\n";
    m_data = 0;
  }
  Der (const Der & rhs)
  {
    cout << " Der::copyConstructor\n";
  }
  Der & operator = (const Der & rhs)
  {
    cout << " Der::assignment Operator\n";
  }
  void display (void)
  {
    cout << "Der::display\n";
  }
  void display (int a)
  {
    cout << "Der::display1\n";
  }
  void display (int a, float b)
  {
    cout << "Der::display2\n";
  }
  void display (int a, float b, unsigned int ch)
  {
    cout << "Der::display3\n";
  }
public:
  virtual bool operator > (const Der & rhs)
  {
    cout << " Der:operator > \n";
    if (m_data > rhs.m_data)
      return true;
    return false;
  }
public:
	Der & operator ->(Der *rhs){ cout<<" operator *\n";return *this;}

private:
  int m_data;
};



int
main (void)
{
/*  Base b1, b2;
  b1.setValue (-9);
  if (b1 < b2)
    {
      cout << " b1< b2\n";
    }
  else
    {
      cout << "b2<b1\n";
    }*/
  Base *b1 = new Der;
  b1->display (1);
  b1->display (-1, 1.9, 9);

  Base *b2 = new Der;
  if (*b1 < *b2)
    {
      cout << " b1 < b2\n";
    }
  else if (*b1 > *b2)
    {
      cout << " b1 > b2\n";
    }
  else
    {
      cout << " b1 ==  b2\n";
    }
  delete b1;
  delete b2;
cout<<" NEw THINGS ................\n";
Der *d= new Der;
 (*d).display(1,2.5);
  return 0;
}
