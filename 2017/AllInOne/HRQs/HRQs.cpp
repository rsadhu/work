// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Functions.h"

#include"QueByStacks.h"
#include<map>
#include<string>
//using namespace std;


void replace(char *str,int i)
{
	if (*(str+i)!= '\0')
	{
		str[i] = str[i] + 'z'-'Z'; 		
		replace(str, ++i);
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	////candles_bday();
	////birthDay_bar_question();
	////closest_numbers();
	//QueByStacks<int> obj;

	//for (int i = 0; i < 10; i++)
	//	obj.enque(i);

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << obj.front() << "  ";
	//	obj.deque();

	//}

	//for (int i = 0; i < 5; i++)
	//	obj.enque(10+i);

	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << obj.front() << "  ";
	//	obj.deque();

	//}


	//char  str[8]("TESTING");

	//replace(str,0);



	/*int i = 0;
	int sum[9] = {0};

	while (i<9)
	{
		int t;
		cin >> t;
		sum[(i + 9 - 4) % 9] = t;
		i++;
	}

*/

	int T;
	cin >> T;
	map<string, int> v1;
	while (T--)
	{
		string t;
		cin >> t;
	//	if (v1.count(t))
		{
		//	v1.insert(std::pair<string, int>(t, v1.count(t) + 1));
			v1[t]= v1[t] + 1;
		}
	}

	cin >> T;

	while (T--)
	{
		string t;
		cin >> t;
		cout << v1[t] << "\n";
	}

	return 0;
}

