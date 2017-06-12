#include<stdio.h>

void foo(int *p)
{

    printf("\n %p \n",p);
    p =  (int *)malloc(sizeof(int));
    printf("\n %p \n",p);
    *p=90;
}

int main(void)
{
    int *p = (int *)malloc(sizeof(int));
    *p =10;
    printf("\n %p \n",p);
    foo(p);
    printf("\n %p \n",p);

    return 0;
}
