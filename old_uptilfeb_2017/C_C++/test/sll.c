#include<stdio.h>
#include<stdlib.h>

typedef struct stud
{
    int data;
    struct stud *next;
}Node;

Node **arr[10];
int i=0;


Node *tmp;
void create(Node **head,int d)
{
    Node *tra ;
    for(tra = *head;tra->next!=NULL;tra=tra->next);
    tra->next = (Node *)malloc(sizeof(Node));
    tra->next->data = d;
    tra->next->next = NULL;
    i++;
    if(i == 4)
        tmp  = tra->next;
}

void display(Node *head)
{
    printf("\n \n");
    while(head)
    {
         printf(" %d ", head->data);
         head =  head->next;
    }

    printf("\n \n");
}

void deleteOne(Node **n)
{ 
    Node *tra =  *n;
    Node *tmp;
    if(tra->next)
    {
        tra->data = tra->next->data;
        tmp = tra->next;
        tra->next = tra->next->next;
        free(tmp);        
    }
    else
    {
        free(tra);
        tra = NULL;
    }
}


int main(void)
{
   Node *head=(Node *)malloc(sizeof(Node));
   head->data=0;
   head->next=NULL;

   int arr[]={ 1,2,3,4,5,6,7,8,9,10};
   int i,s=sizeof(arr)/sizeof(int);
   for( i=0;i<s;i++)
   {
       create(&head,i+1);
   }

   display(head);
   
   deleteOne(&tmp);
   display(head);
   
   deleteOne(&head);
   display(head);

   return 0;
}
