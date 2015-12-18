#include "graphs.h"

LinkList & LinkList::operator <(int d)
{
    if(!root)
        root = new Node(d);
    else
    {
      Node *tra;
      for(tra =  root;tra->next;tra=tra->next);
          tra->next = new Node(d);
    }
     return *this;
}

void LinkList::display()
{
    Node *tra= root;
    while(tra)
    {
        qDebug()<<tra->data;
        tra =  tra->next;
    }
}

