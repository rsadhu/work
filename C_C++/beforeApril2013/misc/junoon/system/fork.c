#include<sys/types.h>


int
main (void)
{
  int count = 0, i;
  pid_t ret;
  printf ("\n start :: forking \n");
//  for (i = 0; i < 3; i++)

    ret = fork ();
    

    ret = fork ();
    

  if (ret == 0)
    {
      printf (" child %d  :: %d", count, getppid ());
    }
  else if (ret < 0)
    {
      printf ("\n cudnt spawned child \n");
    }
  else
    {
      printf ("\n papa is here in %d \n", ++count);
      wait ();
    }
  printf ("\n Exitting ...\n");
 return 0;
}
