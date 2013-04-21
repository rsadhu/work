#include<stdio.h>
#include<stdlib.h>

typedef struct _queue
{
    struct _queue *next;
    int data;
}queue;


int isEmpty(queue *front)
{
    if(front == NULL )
        return 1;
    return 0;
}

queue* new (int d)
{
 queue *p = (queue *)malloc(sizeof(queue));
 p->next = 0;
 p->data=d ;
 return p;
}

void enque(queue *front,queue **rear,int d)
{
     while(front->next)
     {
         front  = front->next;
     }
     front->next = new (d);
     * rear = front->next;
}

void deque(queue **front)
{
    if(*front)
    {
        queue *t = *front;
        *front = (*front)->next;
        free(t);
        t=NULL;
    }
}

int peep(queue *front)
{
    if(front)
      return front->data;
}

int main(void)
{
    queue *front ,*rear ;
    front = rear = new (1);
    int i=1;
    while(i<10)
    {
         enque(front ,&rear,i);
         i++;
    }

    while(i-->0)
    {
         printf("\n ... %d ...",peep(front));
         printf("... %p.. ",front);
         deque(&front);
         printf("... %p.. ",front);     
    } 

    printf("\n the queue is empty ----- %d",isEmpty(front));
    return 0;
}
