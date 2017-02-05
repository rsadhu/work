#pragma once
#include<thread>
#include<iostream>
#include<mutex>

class MyThreads
{
public:
	MyThreads();
	~MyThreads();

	void thread1();
	void thread2();
	void printValues();

	void start();
	void stop();


private:
	std::thread th;
	std::thread th1;
	std::thread th2;
	std::mutex m1;
	int mSharedData = 0;
	bool mStop = false;
};

