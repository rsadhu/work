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
	std::map<std::string, std::map<std::string, int>> mEdge; // EDGE DS
	std::set<std::string> mVisitedNodes; // VISITED NODES
	std::vector<std::map<int, std::string>> mOperationalArea; // OPERATIONAL DATA
	int mVec;		
};

