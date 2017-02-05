#pragma once
#include "MyThreads.h"
class MyCustomThreads :	public MyThreads
{
public:
	MyCustomThreads();
	~MyCustomThreads();
	void run();
};

