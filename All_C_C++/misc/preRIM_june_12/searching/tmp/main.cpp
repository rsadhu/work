//#include"assignment.h"

#include<stdio.h>



#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))


void foo(int arr[],char *s)
{

	printf("\n MACRO ::  %d  %d \n",NUM_ELEM(arr),NUM_ELEM(s));

	printf("\n SIZEOF ::  %d  %d \n",sizeof(arr)/sizeof(int),sizeof(s));

}



int main(int argc,char *argv[])
{
	int arr[]={1,2,3,4,5,6,7,8,9},i=9;
	char str='c';
	//int s = Utility::search(arr,i);
	printf("\n %d  %d\n",sizeof(arr)/sizeof(int), sizeof(str)/sizeof(char));
	//foo(arr,str);
//	printf("\n size of %d \n", s);
	return 0;
}
