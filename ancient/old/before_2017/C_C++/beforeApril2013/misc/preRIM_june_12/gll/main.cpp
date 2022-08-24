#include "gll.h"
#include "sll.h"
#include "cll.h"
#include "dll.h"

static void
sllOperations(void)
{

  GLL *g = new SLL();
  *g < 1 < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9;
  g->display();
  printf("\n number of node are :: %d \n", g->count());
  g->insertNodeAt(1, 99);
  g->insertNodeAt(5, 1000);
  g->insertNodeAt(g->count(), 9999);
  ;
  g->display();
  printf("\n number of node are :: %d \n", g->count());

  printf("\n DELETING ..first \n");
  g->deleteNthNode(1);
  g->display();
  printf("\n DELETING .. last\n");

  g->deleteNthNode(g->count());
  g->display();
  printf("\n DELETING ..middle \n");
  g->deleteNthNode(g->count() / 2);
  g->display();

  printf("\n REVERSING\n");
  g->reverse();
  g->display();
  delete g;
}

static void
dllOperations()
{
  GLL *g = new DLL;
  *g < 1 < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9;
  g->display();
}

static void
cllOperations()
{
}

int main()
{
  int key;
  while (1)
  {
    printf("\n 1.SLL Operations\n");
    printf("\n 2.DLL Operations\n");
    printf("\n 3.CLL Operations\n");
    printf("\n Enter the choice ::");
    scanf("%d", &key);
    switch (key) // arr[key])
    {
    case 1:
      sllOperations();
      break;
    case 2:
      dllOperations();
      break;
    case 3:
      cllOperations();
      break;
    case 0:
      exit(0);
    default:
      break;
    }
  }
  return 0;
}
