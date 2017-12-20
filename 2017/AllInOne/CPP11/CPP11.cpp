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

void function_thread(int &s)
{
//	std::lock_guard<std::mutex> lock(mut);
	s += 10;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int x = 0;

	std::thread t1[1000];
	for (int i = 0; i < 1000; i++)
	{
		t1[i] = std::thread(function_thread, std::ref(x));
		t1[i].join();
	}
	std::cout << x;

	return 0;
}

