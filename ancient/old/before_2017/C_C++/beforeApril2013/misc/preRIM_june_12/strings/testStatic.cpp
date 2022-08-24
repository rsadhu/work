#include <stdio.h>

class A
{
public:
  A()
  {
    printf("\n A::A\n");
  }
  ~A()
  {
    printf("\nA::~A\n");
  }
};

void foo()
{
  static A a;
}

int main(void)
{
  printf("\n main::main\n");
  foo();
  char buf[20];
  fgets(buf, 20, stdin);
  printf("\n %s\n", buf);
  foo();
  fflush(stdout);
  fgets(buf, 0, stdin);
  printf("\n %s\n", buf);
  return 0;
}
