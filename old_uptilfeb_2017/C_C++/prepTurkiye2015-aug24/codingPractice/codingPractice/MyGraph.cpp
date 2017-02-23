#include "stdafx.h"
#include "MyGraph.h"
#include<queue>
#include<stack>



MyGraph::~MyGraph(void)
{
}


void MyGraph::addEdge(int  u,int v)
{
	if((u >=0 && u <= nV ) &&( v>=0 && u <= nV))
	{
		arr[u][v]=1;
		arr[v][u]=1;
	}
}


void display( MyGraph &rhs)
{
	for(int i=0;i<rhs.nV;i++)
	{
		for(int j=0;j<rhs.nV;j++)
		{
			cout<<rhs.arr[i][j];
		}
		cout<<endl;
	}

}


void MyGraph::bfs()
{
	queue<int>q;
	bool *visited  =  new bool[nV];
	for(int i=0;i<nV;i++)
		visited[i]=false;

	//lets start with A,0 index.

	int node = 0;
	visited[node]=true;
	q.push(node);

	while(!q.empty())
	{
		int node =  q.front();
		q.pop();
		cout<<node<<"  ";

		for(int w=0;w<nV;w++)
		{
			if(isConnected(node,w) && !visited[w])
			{
				q.push(w);
				visited[w]=true;
			}
		}

	}
	delete []visited;
}


bool *visited = new  bool[8];
void dfsRec(int v, MyGraph &rhs)
{
	
	cout<< v<<" ";
	visited[v]=true;
	for(int i=0;i<rhs.nV;i++)
	{
		if( rhs.isConnected(v,i) && !visited[i])
		{
			dfsRec(i,rhs);
		}
	}
}

void MyGraph::dfs()
{
  stack<int> st;
  int node=0;
  st.push(node);
  //bool *visited = new  bool[nV];
  visited[node]=true;

  for(int i=0;i<nV;i++)
  {
	  visited[i]=false;
  }
  /*
  while(!st.empty())
  {
	  for(int w=node;w<nV;w++)
	  {
		  if(isConnected(w,node) && !visited[w])
		  {
			  st.push(w);
			  visited[w]=true;
		  }
		  else
		  {
			  node = st.top();
			  st.pop();
			  cout<<node<<" ";
		  }
	  }
  }*/
		dfsRec(node, *this);
	

}
