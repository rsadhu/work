#include "stdafx.h"
#include "Graphs.h"
#include<queue>
using namespace GRAPHS;

Graphs::Graphs()
{
	cin >> mRow;
	mCol = mRow;
	mData = new int*[mRow];
	for (int i = 0; i < mRow; i++)
	{
		mData[i] = new int[mRow];
	}
}


Graphs::~Graphs()
{
}


void Graphs::createGraph()
{
	for (int i = 0; i < mRow; i++)
	{
		for (int j = 0; j < mCol; j++)
		{
			cin >> mData[i][j];
			cout << mData[i][j] << " ";
		}
		cout << endl;
	}
}

void Graphs::bfs()
{
	queue<int> q;
	
}
