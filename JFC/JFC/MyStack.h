#pragma once
#include<mutex>
class MyStack
{
	int *mData;
	std::mutex *mMutex;
public:
	MyStack();
	~MyStack();
};

