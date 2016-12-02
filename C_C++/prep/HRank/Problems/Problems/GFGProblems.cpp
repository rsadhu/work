#include "stdafx.h"
#include "GFGProblems.h"
#include<iostream>

using namespace std;
namespace GEEKFORGEEKS
{

	GFGProblems::GFGProblems()
	{
	}


	GFGProblems::~GFGProblems()
	{
	}

	void GFGProblems::reOrder(int arr[], int size)
	{
		int sign = 0;
		if (arr[0] > 0)
		{
			sign = 1;
		}
		else
		{
			sign = -1;
		}

		for (int j=0,i = 1; i < size; i++,j++)
		{
			if (sign > 0)
			{

			}
		}

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

}
