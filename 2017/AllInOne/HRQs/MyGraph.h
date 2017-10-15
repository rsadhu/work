#pragma once
#include<vector>
#include<array>
#include<string>
#include<map>
#include<set>

class Result
{
public:
	int mPathlength = 0;
	std::string mPath;
};

class MyGraph
{
public:
	MyGraph(int v);
	~MyGraph();

	void createAdjList();	
	void getShortestPath(Result &);
	void printDFS();

private:
	std::set<std::string> mRoots; // VISITED NODES

	int mVec;		
};

