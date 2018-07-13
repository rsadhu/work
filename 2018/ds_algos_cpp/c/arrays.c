#include<stdio.h>

int
main (int argc, char *argv[])
{
  // static array
  int arr[10];


  for (int i = 0; i < 10; i++)
    arr[i] = 5;

  *(arr + 5 * sizeof (int)) = 10;

  for (int i = 0; i < 10; i++)
    printf ("%d", arr[i]);
  return 0;
}
