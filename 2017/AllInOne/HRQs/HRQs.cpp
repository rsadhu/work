// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include"MyGraph.h"
#include"MyMatrix.h"
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	//vector<string> rawRegistry{
	//	"Name=Johny Sex=Man Age=8 Country=UK",
	//	"Name=Anna Sex=Woman Age=66 Country=US",
	//	"Name=Fred Sex=Man Age=51 Country=NL",
	//	"Name=Mirjam Sex=Woman Age=28 Country=BE",
	//	"Name=Fred Sex=Man Age=61 Country=US",
	//	"Name=Frederique Sex=Woman Age=6 Country=US" 
	//};
	//string soughtTraits("Age=6 Country=US");


	////vector<string> rawRegistry{"Name=John Sex=Man Age=46 Country=UK", "Name=Anita Sex=Woman Age=22 Country=NL"};
	////string soughtTraits("Sex=Woman");

	//string  r= GetNameFromRegistryByTraits(rawRegistry,soughtTraits);
	//5 1 2 3 4
	// 1 2 3 4 5 , 4

//	int N;
	//cin >> N;
	//MyGraph graph(N);

	MyMatrix<int> m(5, 5);
	m.printSpiral();

	


	return 0;
}


