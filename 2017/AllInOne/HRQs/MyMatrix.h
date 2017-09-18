#pragma once
#include<vector>
template<typename T>
class MyMatrix
{
public:
	MyMatrix(int m, int n) :mRows(m), mCols(n){ init(); }
	~MyMatrix(){}
	void init();
	void printSpiral(int c=0,int r=0);
private:
	std::vector<std::vector<T>> mData;
	int mCols, mRows;
};

template<typename T>
void MyMatrix<T>::init()
{
	for (int i = 0; i < mRows; i++)
	{
		vector<T> rowData;
		for (int j = 0;j<mCols; j++)
		{
			int tmp;
			cin >> tmp;
			rowData.push_back(tmp);
		}
		mData.push_back(rowData);
	}
	mRows = mCols = mRows - 1;
}

template<typename T>
void MyMatrix<T>::printSpiral(int c,int r)
{	
	if (r < mRows){
		// right
		for (int i = c; i <= mRows - c; i++)
		{
			cout << mData[c][i] << " ";
		}

		// down
		r++;
		for (int i = r; i <= mRows - c; i++)
		{
			cout << mData[i][mRows - c]<<" ";
		}

		//left
		for (int i = mRows - r; i >=c; i--)
		{
			cout << mData[mRows - c][i]<<" ";
		}

		//up
		for (int i = mRows - r; i > c; i--)
		{
			cout << mData[i][c] << " ";;
		}
		c++;
		printSpiral(c, r);
	}	
}

/*
1  2  3  4  5 
6  7  8  9  10 
11 12 13 14 15 
16 17 18 19 20
21 22 23 24 25
*/

