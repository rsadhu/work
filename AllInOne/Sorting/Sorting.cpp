// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Sort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int N = 0;
	std::cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	

	Algos::Sort sorter;
	sorter.sort(arr, N,Algos::ASC,Algos::MERGE);
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i]<<"  ";
	}
	return 0;
}

