// TestCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define N 2

int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
size_t size = sizeof(arr) / sizeof(int);


void rotateArray()
{
	
	
	for (size_t i = 0; i < N; i++)
	{
		int tmp = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[size-1] = tmp;
	}

	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << "  ";
}


void reverseArray(int st,int end)
{
	while (st < end)
	{
		int tmp = arr[st];
		arr[st] = arr[end];
		arr[end] = tmp;
		st++;
		end--;
	}
}

void roatateArrayByReversing()
{
	reverseArray(0, N-1);
	reverseArray(N, size-1);
	reverseArray( 0, size - 1);

	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << "  ";
}


void sepPosNegNums()
{
	int arr[] = { 1, -5, 3, -9, 0, 1, -3, 6, -7, 11, -99, 123 };
	size_t sz = sizeof(arr) / sizeof(int);	
	for (int i = 0, j = 0; i < sz - j; i++, j++)
	{
		if (arr[i] > 0)
		{
			i++;
		}
		else
		{

		}

		if (arr[sz - j] < 0)
		{
			j++;
		}
		else
		{

		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// one approach
	//rotateArray();
	//second approaach
	//roatateArrayByReversing();
	sepPosNegNums();
	return 0;
}

