#ifndef __GLL__H__
#define __GLL__H__
#include<stdio.h>
#include<stdlib.h>

#define MAX printf("rakeshsadhu");

#ifdef R
typedef enum
{
	NONE,
	SLL,
	DLL,
	CLL
}Type;



Type arr[]={ NONE,SLL,DLL,CLL};

#endif

class Node
{
public:
  Node (int d):next (NULL), prev (NULL), data (d)
  {

  }
  Node *next;
  Node *prev;
  int data;
};

class GLL
{
public:
  GLL ():m_head (NULL)
  {
  }
  virtual void create (int) = 0;
  virtual void deleteNthNode (int index) = 0;
  virtual void insertNodeAt (int index, int d) = 0;
  virtual int count ();
  virtual void reverse () {}
  virtual void display ();

  GLL & operator < (int);
  virtual ~ GLL ();
protected:
  Node * m_head;

};


#endif //
