#include "stdafx.h"
#include "MyArrays.h"

#include<iostream>

MyArrays::MyArrays(int arr[],int row,int col)
{
	mArr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		mArr[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mArr[i][j] = arr[(row-1)*i + j];
	//		std::cout << mArr[i][j] << " ";
		}
		//std::cout << "\n";
	}
	mRow = row;
	mCol = col;
}


MyArrays::~MyArrays()
{
	for (int i = 0; i < mRow; i++)
	{
		delete[]mArr[i];
	}
}


MyArrays::MyArrays()
{
	mRow = mCol = 0;
	mArr = nullptr;
}

bool MyArrays::isPatternThere(int arr[],int row,int col)
{
	bool ret(false);
	int **tmp = new int *[row];
	for (int i = 0; i < row; i++)
	{
		tmp[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			tmp[i][j] = arr[(row - 1)*i + j];
			std::cout << tmp[i][j] << " ";
		}
		std::cout << "\n";
	}


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{

		}
	}


	for (int i = 0; i < row; i++)
		delete[]tmp[i];


	return ret;
}



void MyArrays::rotateLeft(int arr[], int size, int k)
{		
	for (int i = 1; i <= k; i++)
	{
		int tmp = arr[0];
		for (int j = 0; j <size-1; j++)
		{
			arr[j] = arr[j+1];
		}
		arr[size - 1] = tmp;
	}
}

void MyArrays::rotateRight(int arr[], int size, int k)
{
	int n = size - 1;
	for (int i = 1; i <= k; i++)
	{
		int tmp = arr[n];
		for (int j = size - 1; j>0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = tmp;
	}	
}


MyArrays & MyArrays::operator<<(int k)
{
	rotateRight(mArr[0], mCol,k);
	return *this;
}

MyArrays & MyArrays::operator>>(int k)
{
	rotateLeft(mArr[0], mCol,k);
	return *this;
}


void MyArrays::display()
{
	std::cout << "\n";
	for (int i = 0; i < mRow; i++)
	{
		for (int j = 0; j < mCol; j++)
		{
			std::cout << mArr[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}