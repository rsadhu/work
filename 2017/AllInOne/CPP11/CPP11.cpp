// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"CppAdvClass.h"

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
	return 0;
}

