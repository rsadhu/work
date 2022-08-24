#include <iostream>
using namespace std;

#define MAX 40

class A
{
public:
  A()
  {
    c++;
    cout << "\nA::A\n"
         << c << endl;
    for (int i = 0; i < MAX; i++)
      arr[i] = i * 3;
  }
  virtual ~A()
  {
    cout << "A::~A" << c-- << endl;
    // call ();
  }
  virtual void call()
  {
    cout << "A::call\n";
  }
  A(const A &rhs)
  {
    cout << "A::copy\n"
         << &rhs;
  }
  A &operator=(const A &rhs)
  {
    cout << " A::operator = \n";
    c = rhs.c * 11;
    return *this;
  }
  int operator[](int unsigned i)
  {
    if (i >= 0 && i < MAX)
      return arr[i];
  }
  // virtual void display () = 0;
  bool operator==(const A &rhs)
  {
    if (this == &rhs)
      return true;
    return false;
  }

  virtual void overloaded(int x, int y = 9)
  {
    cout << "\nA :: overloaded 1\n";
  }
  virtual void overloaded(int x, int y, int z)
  {
    cout << "\nA :: overloaded -3\n";
  }

protected:
  static void check()
  {
    cout << " A::static :: check\n";
  }
  static int c;
  int arr[MAX];
};

int
    A::c = 0;

class
    B : public A
{
public:
  void
  overloaded(int x, int y, int z)
  {
    cout << "\n B:: overlaoded -3\n";
  }
  // void overloaded(int x , int y=0){ cout<<"\n B:: overlaoded -2\n";}
  void
  overloaded(int x)
  {
    cout << "\n B:: overlaoded -1\n";
  }

public:
  B() : A()
  {
    cout << " B::B\n"
         << this << endl;
    //  call ();
  }
  ~B()
  {
    cout << "B::~B\n";
    // call ();
  }

  virtual void
  display()
  {
    cout << "B::Display\n";
  }
  B(const B &rhs)
  {
    cout << " B::B Copy \n";
  }
  B &operator=(const B &rhs)
  {
    cout << "\nB:: operator\n";
    return *this;
  }
  void
  accessor();

protected:
private:
  virtual void
  call()
  {
    cout << "B::call :: A::c :: \n"
         << c;
  }
};

void B::accessor()
{
  A::check();
}

int main(void)
{
  //  B b;
  // b.accessor ();
  // A *a = new B ();
  // a->call ();
  //  A c[10];// = new A;
  //*a = *c;
  // a->call ();
  // delete a;
  // A *a = new A;
  //   a->~A();
  //  delete a;
  /*  A b;
    if (b == b)
      cout << " same ";
    else
      cout << " n ottttttttttttt";

   for(int i=0;i< MAX;i++)
    cout<<" :: "<< b[i];
  */
  /*A *a = new B;
  a->overloaded (4);
  a->overloaded (4, 3);
  a->overloaded (4, 3, 4);
*/
  class B
  {
  public:
    B()
    {
      s = "testng";
      a = 9;
    }
    void display(void)
    {
      cout << " a:: " << a << endl;
    }
    int a;
    char *s;
  };
  B *b = NULL;
  b->display();
  delete b;

  return 0;
}
