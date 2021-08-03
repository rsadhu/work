#include<stdio.h>
#include<stdlib.h>


void foo(char **p)
{
     printf("\n foo... %s ...\n",*p);
     *p = "hello";
     printf("\n foo... %s ...\n",*p);
}
int main(void)
{
    char *t =" tesing";
     printf("\n main... %s ...\n",t);
    foo(&t);
     printf("\n main... %s ...\n",t);
     return 0;
}
