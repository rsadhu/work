#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct st
{
 unsigned bit:1;
}bittest;


bool pow2(int x)
{
 int y = 2;
 bool f = true;
 while(x>1)
 {  
  if(x%2 != 0)
  { 
   f = false;  
   break;
  }
  x = x/y;
 }
 return f;
}

int main(void)
{
#ifdef R
 int a,c;
 double b,d;
 char l,m;
 printf(" %p %p",&a,&c);
 printf("\n %p %p",&b,&d);
 printf("\n %p %p\n",&l,&m); 
 st s;
 printf("%d",s.bit);
 
 int arr[]={1,2,3,4,5,6};
 int size=sizeof(arr)/sizeof(int);
 int j=0;
 #endif
 
 for(int x=1;x<100;x++)
 {
  printf("\n%d %d",x,pow2(x));
 }
 cout<<"\n";
 return 0;
}