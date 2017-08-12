// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Functions.h"

#include"QueByStacks.h"
//using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//candles_bday();
	//birthDay_bar_question();
	//closest_numbers();
	QueByStacks<int> obj;

	for (int i = 0; i < 10; i++)
		obj.enque(i);

	for (int i = 0; i < 5; i++)
	{
		std::cout << obj.front() << "  ";
		obj.deque();

	}

	for (int i = 0; i < 5; i++)
		obj.enque(10+i);

	for (int i = 0; i < 10; i++)
	{
		std::cout << obj.front() << "  ";
		obj.deque();

	}




	return 0;
}

