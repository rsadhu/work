#include "stdafx.h"
#include "Matrix.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
using namespace ARRAY;

Matrix::Matrix()
{
	mMat = 0;
	mSubMat = 0;
	mMatRow = mMatCol = mSubMatRow = mSubMatcol = 0;
}


Matrix::~Matrix()
{
}

void Matrix::del(int row, int **ptrMat)
{
	for (int i = 0; i < row; i++)
	{
		delete[] ptrMat[i];
	}
}

void Matrix::search()
{
	typedef struct _pair
	{
		int row, col;
	}pair;

	vector<pair>list;

	int seed = mSubMat[0][0];

	for (int i = 0; i < mMatRow; i++)
	{
		for (int j = 0; j < mMatCol; j++)
		{
			if (seed == mMat[i][j] && (i + mSubMatRow) <= mMatRow && (j + mSubMatcol) <= mMatCol)
			{
				pair p;
				p.row = i;
				p.col = j;
				list.push_back(p);
			}
		}
	}

	int f = 0;

	for (int i = 0; i < list.size(); i++)
	{
		int row = list.at(i).row;
		int col = list.at(i).col;
		f = 0;

		for (int j = 0; j < mSubMatRow; j++)
		{
			for (int k = 0; k < mSubMatcol; k++)
			{
				if (mMat[row + j][k + col] != mSubMat[j][k])
				{
					f = 1;
					break;
				}
			}
			if (f == 1)
				break;
		}
		if (f == 0)
			break;
	}
	if (f == 0)
		cout << "found\n";
	else
		cout << "not found\n";
}

void Matrix::searchGlassHour()
{
	int 
}

int ** Matrix::init(int row, int col)
{
	int **arr = 0;
	arr = new int*[row];
	for (int j = 0; j < row; j++)
	{
		arr[j] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		string inp;
		cin >> inp;
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = inp[j] - '0';
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return arr;
}

void Matrix::hackerRank2DSearch()
{
	int T = 0;
	cin >> T;
	while (T > 0)
	{
		int row, col;
		cin >> row >> col;

		mMat = init(row, col);
		mMatRow = row;
		mMatCol = col;

		cin >> row >> col;

		mSubMat = init(row, col);

		mSubMatRow = row;
		mSubMatcol = col;

		search();
		del(mMatRow, mMat);
		del(mSubMatRow, mSubMat);
		T--;
	}
}

void Matrix::spiralDisplay()
{
	int row, col;
	cin >> row >> col;

	mMat = init(row, col);
	mMatRow = row;
	mMatCol = col;


}
