#include <QtWidgets/QApplication>
#include "dictionary.h"
#include"MyThreads.h"
#include<iostream>
#include<mutex>
std::mutex mylock;

void callBack(int p)
{
	std::cout << "callback:: " << p << std::endl;
}

void myThread(int p)
{
	mylock.lock();
	callBack(p);
	mylock.unlock();
}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	std::thread t[10];
	for (int i = 0; i < 10; i++)
	{
		t[i] = std::thread(myThread, i);
		t[i].join();
	}

	return a.exec();
}
