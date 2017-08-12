// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"_template.h"

#define N 10

void sepPosNeg()
{
	int *arr = new int[N]{1,2,3,-9,7,-5,4,22,0,-99};
	for (int i = 0; i < N;i++)
	{
		std::cout << arr[i] << " ";
	}	

	delete[]arr;

	for (int i = 0,j=N-1; i < j;)
	{

	}
}

std::mutex mu;
std::condition_variable cv;
std::vector<int > gvec = {1,2,3,4,5,6};
bool g_ready = false;

void threadFunc1()
{
	std::unique_lock<std::mutex> locker(mu);
	//while ()

}




void threadFunc2()
{

}

template<typename MyType>
class Util
{
	public:
		Util(MyType &obj);

		void setData()const;
	private:
		mutable MyType *mData=nullptr;
};


int _tmain(int argc, _TCHAR* argv[])
{
	std::thread t1(threadFunc1);
	std::thread t2(threadFunc2);
	return 0;
}

