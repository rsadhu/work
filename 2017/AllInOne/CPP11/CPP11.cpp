// CPP11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include"_template.h"
#include<set>
#include<map>
#include<thread>
#include<mutex>
#include<future>



std::mutex mut;
int g_data = 0;
void function_thread(int &s)
{
	while (1)
	{
		g_data++;
		if (g_data >= INT_MAX)
			g_data = 0;
		s = g_data;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	int x = 0;

	std::thread t1[1000];
	//for (int i = 0; i < 1000; i++)
	{
		t1[0] = std::thread(function_thread, std::ref(x));
		std::cout << x;
		t1[0].join();
	}
	std::cout << x;

	return 0;
}

