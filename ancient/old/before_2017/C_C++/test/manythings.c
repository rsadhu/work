#include<stdio.h>

int
add (int n)
{
  if (n <= 1)
    return 1;
  return n + add (n - 1);
}

int
pow (int b, int d)
{
  if (0 == d)
    return 1;
  return b * pow (b, d - 1);
}

int
main (void)
{
  int n;
  n = 10;
  printf ("\n A.P series addition 1 to %d = %d\n", n, add (n));
  printf ("\n the power of %d to %d is ..  %d\n", 2, n, pow (2, n));
  return 0;
}
