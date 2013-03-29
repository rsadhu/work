#include<stdio.h>


class A
{

public:
  A ():a (0), b (0), c (0)
  {
    printf ("\nA::A\n");
  }
  void set (int b)
  {
    c = b;
    printf ("\n A::A\n %d %d %d ", a, this->b, c);
  }
  int a;
protected:
  int b;
private:
  int c;
};



class B:public A
{
public:
  B ()
  {
    printf ("\nB::B\n");
  }
  void display ()
  {
    a = 10;
    b = 20;
    printf ("\n %d %d \n", a, b);
    set (99);
  }
};

void foo(int &d)
{
	d=100;
}

int
main (void)
{
  B b;
  b.display ();
  int y=9;
  int &i=y;
  i=0;
  printf("\n %d %d \n",i,y);
  foo(i);
  printf("\n %d  %d\n",i,y);
  return 0;
}
