// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Functions.h"
#include"MyMatrix.h"
#include"QueByStacks.h"
#include<map>
#include<string>
#include<regex>




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

	/*MyMatrix<int> m(5, 5);
	m.printSpiral();
*/
	//std::vector<int> a = { 8, 4, 6, 2, 6, 4, 7, 9, 5, 8 };
	//int res = firstDuplicate(a);

	std::string inputString("0dsdksjskjs");
	std::regex regex("[0-9]");
	std::smatch match;
	if (regex_search(inputString, match, regex)) {
		std::ssub_match sub_match = match[0];
		return sub_match.str()[0];
	}

	return 0;
}

