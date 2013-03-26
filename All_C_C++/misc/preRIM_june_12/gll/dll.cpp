#include"dll.h"

void
DLL::create (int d)
{
  Node *tra = m_head;
  Node *tmp = new Node (d);
  if (!tra)
    m_head = tmp;
  else
    {

      for (; tra->next != 0; tra = tra->next);
      {
	tra->next = tmp;
	tmp->prev = tra;
      }
    }
}


void
DLL::deleteNthNode (int index)
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


void
DLL::insertNodeAt (int index, int d)
{
  Node *cur, *prev;
  int cnt = 1;
  prev = cur = m_head;
  for (cur = cur->next; prev != NULL; cur = cur->next, ++cnt)
    {
      if (index == cnt)
	{
	  Node *tmp = new Node (d);
	  tmp->next = cur;
	  prev->next = tmp;
	  break;
	}
      prev = prev->next;
    }
}

