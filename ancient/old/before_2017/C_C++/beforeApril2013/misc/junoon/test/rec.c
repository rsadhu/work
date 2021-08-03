#include<stdio.h>

int
power (int x, int y)
{
  if (0 == y)
    return 1;
  x = x * power (x, y - 1);
}

int factorial(int z)
{
 if(0 == z)
 return 1;
 z = z* factorial(z-1);
}


void selectionSort(int arr[],int size,int tmp)
{
	if(size <1)
		return ;
	selectionSort(arr,--size,tmp);
	size = tmp-1;
	int sw;
	if(arr[size] >arr[size+1])
	{
		sw = arr[size];
		arr[size] = arr[size+1];
		arr[size+1] = sw;
	}

}


void stringRev(char *str)
{
 if(*str == '\0')
 return;
 stringRev(1+str);
 printf("%c",*str);
}


void print2D(int i,int j)
{
 if(i == 0 || j == 0){
  printf(" %d\n",j);  
  return ;
 }
  printf("%d ",i);
  print2D(i-1,j);
  printf("%d ",i);
  i = j;
  print2D(i,j-1);
}

int
main (void)
{
  printf (" %d power of %d = %d ", 2, 3, power (2, 3));
  printf(" \nfactorial of %d = %d\n",5, factorial(5));
  int arr[]={ 3,2,0,-9,10,6,100,-90,1};
  int size = sizeof(arr)/sizeof(int);
  int tmp =  size;
//  selectionSort(arr,size-1,tmp-1);
  char str[]="hello world";
  stringRev(str);
  printf("\n");
 print2D(3,1);
  printf("\n");
 
  return 0;
}
