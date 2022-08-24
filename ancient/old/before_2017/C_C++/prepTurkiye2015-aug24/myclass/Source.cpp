#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int (*fPtr)(int);

class A
{
public:
	void setFPtr(fPtr ff);
	void doSomething(int X = 1)
	{
		cout << " disco misco \n";
		cout << mFuncPtr(X);
	}
	virtual void foo() const = 0;

private:
	fPtr mFuncPtr;
};

void A::foo() const
{
	cout << "A::foo const\n";
}

void A::setFPtr(fPtr p)
{
	mFuncPtr = p;
}

int makeDouble(int p)
{
	return 2 * p;
}

class B : public A
{
public:
	void foo() const
	{
		cout << "\nB::foo\n";
	}
};

#ifdef R
#define Y 6
int arr[X][Y] = {{1, 2, 3, 1, 2, 2},
				 {1, 2, 3, 1, 2, 2},
				 {1, 2, 3, 1, 2, 2},
				 {1, 2, 3, 1, 2, 2},
				 {1, 2, 3, 1, 2, 2},
				 {1, 2, 3, 1, 2, 2}};

int cnt = 0;

int graph[8][8] = {
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0},
	{0, 1, 2, 0, 0, 0, 5, 0}};

void bfs()
{
}

void dfs()
{
}

void test(int xx, int yy, int val)
{
	cnt++;
	if (xx < X)
	{
		arr[xx][yy] = val;
		test(++xx, yy, val);
	}
	else
	{
		if (yy < Y)
		{
			xx = 0;
			test(xx, ++yy, val);
		}
	}
}

void display()
{
	cout << cnt << " = number of times recursion iterated "
		 << "\n";
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
{
				{ 1,2,3,1,2,2},
				{ 1,2,3,1,2,2},
				{ 1,2,3,1,2,2},
				{ 1,2,3,1,2,2},
				{ 1,2,3,1,2,2},
				{ 1,2,3,1,2,2}


*/
#elif R
void spiralPrint()
{

	int arr[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};

	int R = 0;
	int i, j;
	i = j = 0;
	int L = 4;

	while (R < (L / 2))
	{
		while (j < (L - R))
		{
			cout << arr[i][j] << " ";
			j++;
		}
		j--;
		i++;
		cout << endl;

		while (i < (L - R))
		{
			cout << arr[i][j] << " ";
			i++;
		}
		cout << endl;
		i--;
		j--;
		while (j >= R)
		{
			cout << arr[i][j] << " ";
			j--;
		}
		cout << endl;
		i--;
		j++;
		R++;
		while (i >= R)
		{
			cout << arr[i][j] << " ";
			i--;
		}
		cout << endl;

		i = j = R;
	}
}
#endif
