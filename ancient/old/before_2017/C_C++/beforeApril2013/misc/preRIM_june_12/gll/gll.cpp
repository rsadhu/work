#include "gll.h"

GLL &GLL::operator<(int d)
{
  create(d);
  return *this;
}

void GLL::display()
{
  Node *tra = m_head;
  while (tra)
  {
    printf(" %d ", tra->data);
    tra = tra->next;
  }
  printf("\n");
}

int GLL::count()
{
  int count = 0;
  Node *tra = m_head;
  while (tra)
  {
    tra = tra->next;
    count++;
  }
  return count;
}

GLL::~GLL()
{
  Node *tmp;
  printf("\n %d \n", this->count());
  while (m_head)
  {
    tmp = m_head;
    m_head = m_head->next;
    delete tmp;
  }
}
