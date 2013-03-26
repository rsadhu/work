#include"stringmanipulation.h"


int
main (void)
{
  String *p = new DerString ();
  p->display ();
  delete p;
  return 0;
}
