#include "assignment.h"

#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))


int Utility::search(int arr[],int number)
{
	int size = NUM_ELEM(arr);		
	printf("%d",size);
	return size;
}


