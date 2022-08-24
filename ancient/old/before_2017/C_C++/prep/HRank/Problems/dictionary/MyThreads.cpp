#include "MyThreads.h"
#include <stdlib.h>

MyThreads::MyThreads()
{

	mThread = new std::thread(&MyThreads::start, this);
}

MyThreads::~MyThreads()
{
	delete mThread;
}

void MyThreads::run()
{
}

void MyThreads::setCallBack(fptr t)
{
	mCallBack = t;
}

void MyThreads::start()
{
	mCallBack(5000);
}