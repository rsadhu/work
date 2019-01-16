#include<iostream>

struct[[deprecated ("deprecated")]] S;


[[deprecated()]]
int  add(int b, int a)
{
 return a+b;
}

[[deprecated()]] typedef s*t;

int
main (void)
{

  struct sttt
  {
    int data;
  };

  typedef struct sttt T;
   
  std::cout<<add(1,1);  

  return 0;
}
