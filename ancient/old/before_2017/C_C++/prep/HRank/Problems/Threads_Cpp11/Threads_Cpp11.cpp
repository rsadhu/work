// Threads_Cpp11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <mutex>
#include <iostream>

std::mutex mylock;

class MythreadClas
{
public:
	void operator()()
	{
		std::cout << " MythreadClas::thread ";
	}
};

class T
{
public:
	T(int p) : mP(p)
	{
	}
	int mP;
};

void myThread(int x)
{
	std::cout << "\nmyThread::x " << std::this_thread::get_id();
}

void initThreads()
{
	/*std::thread t[10000];
	for (int i = 0; i < 10000; i++)
	{
	t[i] = std::thread(myThread, i);
	t[i].join();
	}*/

	//	std::thread tt((MythreadClas()));
	// tt.join();

	std::thread t([](int x)
				  { std::cout << "x::  " << x << std::endl; },
				  10);
	t.join();

	std::thread t1(myThread, 100);
	std::cout << "\nmyThread:::id " << t1.get_id();
	std::cout << "\nmain Thread:::id " << std::this_thread::get_id();
	t1.join();
}

int main(int argc, char *argv[])
{

	return 0;
}
