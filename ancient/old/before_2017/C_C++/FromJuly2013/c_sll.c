#include<stdio.h>
#include<stdlib.h>



typedef struct _stud
{
  int data;
  struct _stud *next;
} Node;


void addNode (Node ** head, int n)
{
  printf("\n:: main:: addMode\n");
  Node *tra;
  if(!*head)
     {
         *head =  (Node *)malloc(sizeof(Node));
         (*head)->data = n;
         (*head)->next = NULL;
     }
     else
     {
         for(tra= *head;tra->next;tra= tra->next);
         tra->next = (Node *)malloc(sizeof(Node));
         tra->next->data = n;
         tra->next->next =  NULL;
     }
}


void
display (Node * head)
{
  printf("\n:: main:: display\n");
 while(head)
 {
     printf(" data:: %d\n",head->data);
     head=head->next;
 }
}

void reverseIter(Node **head)
{
    Node *tra = *head;
    Node *tmp = 0,*cur = tra->next;
  
    while(cur)
    {
        tra->next = tmp;
        tmp = tra;
        tra = cur;
        cur = cur->next;
    }

    if(tra)
        tra->next = tmp;

    *head = tra;
}

void
reverseList(Node **head,Node ** cur)
{
if(!(*cur)->next)
{
    *head=*cur;
    return;
 }

 reverseList(head,&((*cur)->next));
 (*cur)->next = *cur;
}



int
main (int argc, char *argv[])
{
  printf("\n:: main:: func --starts\n");
  Node *head = 0;
  int n = 6;
  while (n-- > 0)
    addNode (&head, n);

  display (head);
 // Node *tmp = head;
//  reverseList(&head,&tmp);
  //tmp->next =0;
 // display(head);
  reverseIter(&head);
  display(head);
  printf("\n:: main:: func--ends\n");
  return 0;
}

