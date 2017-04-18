// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

void candles_bday()
{
	int N;
	std::cin >> N;

	int x = 0, y;
	int n = 1;
	int bigg = 1;

	std::cin >> y;

	for (int i = 1; i<N; i++)
	{
		std::cin >> x;
		if (x >= y)
		{
			n++;
		}
		else
		{
			if (n>bigg)
				bigg = n;
			n = 1;
		}
		y = x;
	}

	if (n>bigg)
		bigg = n;

	std::cout << bigg;
	
}


void birthDay_bar_question()
{

	int N;
	cin >> N;
	int *arr = new int[N]();

	for (int i = 0; i<N; i++)
		cin >> arr[i];

	int sum = 0, cL = 0;
	cin >> sum >> cL;

	int s = 0;
	int cnt = 0;

	if ((N == 1) && sum == arr[0])
		cnt = 1;
	else
	{

		for (int i = 0; i <= (N - cL); i++)
		{
			s = 0;
			for (int j = i; j < (i + cL); j++)
			{
				s += arr[j];				
			}

			if (sum == s)
			{
				cnt++;				
			}
		}
	}

	cout << cnt;
}

void closest_numbers()
{
	int N;
	cin >> N;
	int *arr = new int[N]();
	//int arr[10000] = { 0 };
	for (int i = 0; i<N; i++)
		cin >> arr[i];

	std::sort(arr, arr + N);
	long int min = 10000000;	
	int tracker[10000][2] = { 0 }, k = 0;
	int f = 0;
	for (int i = 0; i<N - 1; i++)
	{
		int tmp = arr[i + 1] - arr[i];
		
		if (tmp == min)
		{
			if (f == 1)
			{
				k++;
				f = 0;
			}

			min = tmp;
			tracker[k][0] = i;
			tracker[k][1] = i + 1;
			k++;
		}
		else if (tmp<min)
		{
			if (k > 0)
			{
				k--;
				f = 1;
			}

			min = tmp;
			tracker[k][0] = i;
			tracker[k][1] = i + 1;			
		}
		else
		{

		}
	}

	for (int i = 0; i<k; i++)
		std::cout << arr[tracker[i][0]] << " " << arr[tracker[i][1]] << " ";
	delete[]arr;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//candles_bday();
	//birthDay_bar_question();
	closest_numbers();
	return 0;
}

