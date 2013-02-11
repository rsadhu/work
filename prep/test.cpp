#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct st
{
 unsigned bit:1;
}bittest;
int main(void)
{
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
 
 while(j<size){
 tmp = arr[j]; 
 int i=0;
 while(i <  j)
 {
   arr[i+1]=arr[i];
   i++;
 }
 arr[j
 }
 for(i=0;i<5;i++)
 cout<<arr[i]<< " ";
 cout<<"\n"; 
 return 0;
}