// codingPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"ArrayManipulations.h"
#include"MyGraph.h"
#include<string>


int _tmain(int argc, _TCHAR* argv[])
{	
	int n;
	cin>>n;

    MyGraph gr(n);
	int j=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;	

		char *str = const_cast<char *>( s.c_str());
			
		for(int i=0;i<s.size();i++)
		{
			if(*(str+i)=='1')
				gr.addEdge(j,i);
		}
		j++;
	}
	

	void display( MyGraph &rhs);
	display(gr);

	gr.bfs();
	cout<<endl;
	gr.dfs();
	return 0;
}


