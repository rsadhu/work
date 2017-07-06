// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"CppAdvClass.h"
#include<map>
#include<exception>
#include<iostream>

void foo(CppAdvClass c)
{

}

void foo(int &&)
{

}

void foo(int &)
{

}


int _tmain(int argc, _TCHAR* argv[])
{
	CppAdvClass c('a');

	int a = 5;
	foo(a);
	foo(5);
	std::map<int, int> m;
	try
	{

		m.insert(1, 42);
		m.insert(1, 3);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception :: " << e.what();
	}
	return 0;
}

