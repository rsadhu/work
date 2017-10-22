// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Functions.h"
#include"MyMatrix.h"
#include"QueByStacks.h"
#include<map>
#include<string>
#include<regex>
#include<list>

int firstDuplicate(std::vector<int> arr)
{
	int n = INT_MAX, num = INT_MAX;
	std::vector<std::pair<int,int>> lu;
	int i = 0;
	for (auto it : arr)
	{
		lu.push_back(std::pair<int, int>(it, i++));
	}

	std::sort(lu.begin(), lu.end(), [](std::pair<int, int> a, std::pair<int, int> b)
	{
		if (a.first < b.first)
			return true;
		return false;
	});


	for (int i = 0, j = 1; j < lu.size();i++,j++)
	{
		if (lu[i].first == lu[j].first)
		{
			if (lu[j].second <=  num)
			{
				num = lu[j].second;
			}
		}
	}

	return arr[num];
}

#include<string>
#include<cctype>
#include<algorithm>

bool passwordCheckRegExp(std::string inputString) {

	if (inputString.length() >= 5)
	{
		bool num = false, lc = false, uc = false;
		for (auto it : inputString)
		{
			if (std::islower(it))
			{
				lc = true;
				//     cout<<it<<"   ";
			}
			else
				if (std::isupper(it))
				{
					lc = true;
					//    cout<<it<<"   ";
				}
				else
				{
					if (it >= '0' && it <= '9')
					{
						int n = it - '0';
						if (n >= 0 && n <= 9)
							num = true;
					}
				}
		}

		if (lc && uc && num)
			return true;
		return false;
	}
	else
	{
		return false;
	}
}


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

	//std::string inputString("0dsdksjskjs");
	//std::regex regex("[0-9]");
	//std::smatch match;
	//if (regex_search(inputString, match, regex)) {
	//	std::ssub_match sub_match = match[0];
	//	return sub_match.str()[0];
	//}


	/*std::vector<int> v = { 2, 3, 3, 1, 5, 2 };
	int r = firstDuplicate(v);*/

	bool r = passwordCheckRegExp("my.Password123");
	return 0;
}

