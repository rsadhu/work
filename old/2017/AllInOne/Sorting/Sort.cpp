#include "stdafx.h"
#include "Sort.h"

using namespace Algos;

Sort::Sort()
{
}


Sort::~Sort()
{
}




void Sort::sort(int *list, int size,ORDER order,SORTTYPE type)
{
	mLength = size;
	mArr = list;
	switch (type)
	{
	case SELECTION:
		selectionSort();
		break;
	case INSERTION:
		insertionSort();
		break;
	case MERGE:
		mergeSort();
		break;
	case QUICK:
		quickSort();
		break;
	case HEAP:
		heapSort();
		break;
	case BUBBLE:
		bubblesort();
		break;
	}
}


void Sort::selectionSort()
{	
	for (int i = 0; i < mLength; i++)
	{
		for (int j =i+1; j < mLength; j++)
		{
			if (mArr[i] >  mArr[j])
			{
				int  tmp = mArr[i];
				mArr[i] = mArr[j];
				mArr[j] = tmp;
			}
		}
	}
}


void Sort::insertionSort()
{
	for (int i = 1; i < mLength; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (mArr[i] < mArr[j])
			{
				int tmp = mArr[i];
				mArr[i] = mArr[j];
				mArr[j] = tmp;
			}
		}
	}
}

void Sort::heapSort()
{

}

void Sort::quickSort()
{

}

void Sort::mergeSort()
{

}

void Sort::bubblesort()
{
	for (int i = 0; i < mLength; i++)
	{
		int f = 0;
		for (int j = 0; j < mLength - i-1; j++)
		{
			if (mArr[j] > mArr[j + 1])
			{
				int tmp = mArr[j];
				mArr[j] = mArr[j+1];
				mArr[j+1] = tmp;
				f = 1;
			}
		}
		if (f == 0)
			break;
	}
}



