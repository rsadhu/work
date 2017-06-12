#pragma once
#include<thread>

typedef 
void (*fptr)(int);

class MyThreads
{
public:
	MyThreads();
	~MyThreads();
	virtual void run();
	
	void setCallBack( fptr t );
	void start();
private :
	std::thread *mThread;	
	fptr mCallBack;		
};





