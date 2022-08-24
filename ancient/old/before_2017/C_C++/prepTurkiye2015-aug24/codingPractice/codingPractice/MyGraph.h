#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyGraph
{
public:
	MyGraph(int n)
	{
		nV = n;

		arr = new int *[n];
		for (int i = 0; i < nV; i++)
			arr[i] = new int[n];
		for (int i = 0; i < nV; i++)
		{
			for (int j = 0; j < nV; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	~MyGraph(void);

	void addEdge(int v1, int v2);
	bool isConnected(int v1, int v2)
	{
		return arr[v1][v2] ? true : false;
	}

	void bfs();
	void dfs();

	friend void display(MyGraph &);
	friend void dfsRec(int v, MyGraph &rhs);

private:
	int **arr;
	int nV;
};
