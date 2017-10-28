// TestCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>

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


int countNumber(std::vector<int>v, int n,int index)
{
	int c = 0;
	if (index >= v.size() )
		return c;
	else
	{
		if (v[index] == 1)
			c = 1 +  countNumber(v, n, ++index);
		else
			c =  countNumber(v, n, ++index);			
	}
	return c;	
}

std::string allStar(std::string str)
{
	std::string s="";
	if (str.length() > 0)
	{		 
		 allStar(str.substr(1));
		 s += str[0] + "*";
		 std::cout << s;
	}
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// one approach
	//rotateArray();
	//second approaach
	//roatateArrayByReversing();
	//sepPosNegNums();

	std::vector<int> v = {1,2,4,0,5,2,3,5,1,3,1,9,1,0,10};
	int c = countNumber(v, 1,0);

	std::string s = allStar("hello");
	return 0;
}

