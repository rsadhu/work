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



void function_thread()
{
	try
	{
		while (1)
		{
			std::cout << " function_Thread" << std::this_thread::get_id() << "\n";
		}
	}
	catch (std::exception e)
	{
		std::cout << " exc " << e.what();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t(function_thread);
	//t.detach();
	return 0;
}

