#include <unistd.h>
#include<stdio.h>

int
main (void)
{
  pid_t id = fork ();
  switch (id)
    {
    case 0:
      printf ("\n child process ... %d %d",getpid(),getppid());
      exit(0);
      break;
    case -1:
      printf ("\n cant fork the process\n");
      break;
    default:
      printf ("\n parents process--- pid child %d\n",id);
      wait();
      printf(" child returned\n");
      break;
    }
  return 0;
}
