#pragma once
#include<string>
#include<iostream>
using namespace std;

class ArrayManipulations
{
public:
	ArrayManipulations(void);
	~ArrayManipulations(void);	
	void fillData(int &,int &, int &, int &);
    bool isSubArray();
	void isArrayHalfBalanced();
	void subMatrixSum(int m,int n);
private:
	int **arr,**pattern;
	int M,N;
};

