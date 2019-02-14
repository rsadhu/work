#include<stdio.h>
int pow(int a,int b)
{
    if(b==0)
        return 1;
    return a*pow(a,b-1);
}

//setting the 'n'th bit 

int main(void)
{
    int a = 64;
    printf("\n %d\n ",64|pow(2,7));
//printf(" %d ", pow(2,10));
return 0;   
}
