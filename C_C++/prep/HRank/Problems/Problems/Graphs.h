#pragma once
#include<iostream>
using namespace std;

namespace GRAPHS
{
	class Graphs
	{
	public:
		Graphs();
		~Graphs();
		void createGraph();
		void bfs();
	private:
		int **mData;
		int mRow, mCol;
	};
};

