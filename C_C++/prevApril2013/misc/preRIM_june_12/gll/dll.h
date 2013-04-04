#include"gll.h"


class DLL:public GLL
{
public:
  void create (int);
  void deleteNode (int);
  void deleteNthNode (int index);
  void insertNodeAt (int index, int d);
};
