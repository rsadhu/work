#include<stdio.h>


int * ret(void)
{
 int a=9;
 return &a;
}



int main(void)
{
 int x  = ret();
 return 0;
}
