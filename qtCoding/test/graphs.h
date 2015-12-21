#ifndef GRAPHS_H
#define GRAPHS_H

#include<QDebug>
class Node final
{
public:
    int data;
    Node *next;
    Node(int d):data(d),next(0){}
};

class LinkList
{
    Node *root;
 public:
    LinkList ():root(0){}
    LinkList & operator<(int d);
    void display();
};





#endif // GRAPHS_H
