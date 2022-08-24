#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int childProcess()
{
  printf(" \nChild Process Called Functiom -------7\n");
  return 0;
}

int main(void)
{
  pid_t pid, pret;
  int i = 8;
  printf(" Starting the  Main Process----1\n");

  printf(" WIll fork a new child process now ----2\n");
  pid = fork();
  if (0 == pid)
  {
    printf(" CHILD PROCESS RUNNING ..4\n");
    childProcess();
  }
  else if (0 < pid)
  {
    int ret;
    printf(" PARENT PROCESS RUNNING  ---3\n");
    pret = waitpid(pid, &ret, WNOHANG | WUNTRACED);
    printf(" CHILD EXITTED :: %d ::  %d\n", ret, pid);
  }
  else
  {
    printf(" FAILED TO FORK");
  }

  printf("EXITTING MAIN PROCESS ----%d\n", i);
  i++;
  return 0;
}
