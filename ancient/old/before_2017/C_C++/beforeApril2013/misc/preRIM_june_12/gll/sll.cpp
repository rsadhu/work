#ifndef __SLL__H__
#define __SLL__H__
#include "sll.h"

void SLL::create(int d)
{
  Node *tra = m_head;

  if (!tra)
    m_head = new Node(d);
  else
  {

    for (; tra->next != 0; tra = tra->next)
      ;
    tra->next = new Node(d);
  }
}

void SLL::deleteNthNode(int index)
{
  Node *cur, *prev;
  int cnt = 2;
  if (1 == index)
  {
    cur = m_head;
    m_head = m_head->next;
    delete cur;
  }
  else
  {
    prev = cur = m_head;
    for (cur = cur->next; cur != NULL; cur = cur->next, ++cnt)
    {
      if (index == cnt)
      {
        prev->next = cur->next;
        delete cur;
        break;
      }
      prev = prev->next;
    }
  }
}

void SLL::insertNodeAt(int index, int d)
{
  Node *cur, *prev;
  int cnt = 1;
  prev = cur = m_head;
  for (cur = cur->next; prev != NULL; cur = cur->next, ++cnt)
  {
    if (index == cnt)
    {
      Node *tmp = new Node(d);
      tmp->next = cur;
      prev->next = tmp;
      break;
    }
    prev = prev->next;
  }
}

void SLL::reverse()
{
  Node *cur, *tmp, *prev;
  cur = prev = m_head;
  tmp = NULL;

  while (cur)
  {
    prev = prev->next;
    cur->next = tmp;
    tmp = cur;
    cur = prev;
  }
  m_head = tmp;
}

#endif //
