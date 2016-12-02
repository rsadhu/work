#include "stdafx.h"
#include<vector>
#include<iostream>
#include"BST.h"
#include"Matrix.h"
#include"DP_PROBS.h"
#include"GFGProblems.h"
#include<string.h>
#include<string>
#include"Graphs.h"
#include<time.h>
#include"templatizedClass.h"
#include"MyArrays.h"
#include"MyBitwise.h"


using namespace std;


double  time()
{	
	time_t timer = time(0);	
	return timer;
}


void test()
{
    double st= time();
	int n, r;
	cin >> n >> r;
	vector<int>arr(n,0);
	for (int i = 0; i<n; i++)
		cin >> arr[i];


	for (int j = 0; j<r; j++)
	{
		int tmp = arr[0];
		for (int i = 0; i<n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = tmp;
	}

	cout << "time diff:: " << time() - st << endl;
}


void reverse(int arr[], int start, int end)
{
	while (start <= end)
	{
		int tmp = arr[end];
		arr[end] = arr[start];
		arr[start] = tmp;
		end--;
		start++;
	}
}


void rotateArray()
{
	int arr[] = { 1, 2, 3, };// 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
	int n = sizeof(arr) / sizeof(int);
	int k = 2;
	reverse(arr, 0, n - k - 1);
	reverse(arr, n - k, n - 1);
	reverse(arr, 0, n - 1);
}

void
chocolateWrapper()
{
	int n = 4;
	int m = 2;
	
	int cnt = 0;
	while (n)
	{
		cnt+= n;
		n /= m;
	}
	cout << "cnt= " << cnt << std::endl;
}

int main()
{	

	//rotateArray();
	chocolateWrapper();

	return 0;
}

