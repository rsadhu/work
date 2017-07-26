// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"CppAdvClass.h"
#include<map>
#include<exception>
#include<iostream>
#include<thread>
#include<mutex>
#include <condition_variable>
#include <chrono>
#include<list>
#include<vector>
#include<exception>




void foo(CppAdvClass c)
{

}

void foo(int &&)
{

}

void foo(int &)
{

}

#include<memory>

class Base
{
public:
	//virtual 
	~Base()
	{
		std::cout << " ~Base";
	}
};



class Der :public Base
{
public :
	~Der()
	{
		std::cout << "~Der";
	}
};

void test()
{
	std::shared_ptr<int>   ptr = std::make_shared<int>();
	*ptr = 9;
	std::cout << *ptr << "  " << ptr;



	std::shared_ptr<Base> d = std::make_shared<Der>();



	CppAdvClass c('a');

	int a = 5;
	foo(a);
	foo(5);
	std::map<int, int> m;
	try
	{

	}
	catch (std::exception &e)
	{
		std::cout << "Exception :: " << e.what();
	}
}



std::mutex mut;
std::condition_variable cond;
bool isReady = false;

//std::shared_ptr<int> d = std::make_shared<int>(9);
std::list<int> common_space;


void consumer(/*std::shared_ptr<int> d*/)
{
//	while (1)
	{
		std::unique_lock<std::mutex> locker(mut);
		{
			/*	while (!isReady)
				{
				cond.wait(locker);
				}
				*/

			cond.wait(locker, []
			{
				return isReady;; // wait and put the thread to sleep
			}
			);

			for (auto it: common_space)
				std::cout << "  " << it;
		}
		locker.unlock();
	}
}


void producer(/*std::shared_ptr<int> d*/)
{
	int n=100000;
	while (n>=0)
	{
		std::unique_lock<std::mutex> locker(mut);
		
		std::cin >> n;
		
		while (n--)
		{
			int d;
			std::cin >> d;
			common_space.push_back(d);
		}

		isReady = true;
		cond.notify_one();
		locker.unlock();
	}
}


void threadTry()
{
	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();
}

template<class ...Args>
class Utility
{
public:
	Utility(Args ...args) :mData(0)
	{
		//int d = args[0];
	}

	bool operator()(int x)
	{
		return  x>mData;
	}
private:
	int mData;
};

std::vector<std::exception> g_exceptions;

void
thread_with_exception()
{
	while (10)
	{
		try
		{
			throw new std::exception("Test Exceptions For Learning", 540);
		}
		catch (std::exception *ex)
		{
			g_exceptions.push_back(*ex);
		}
	}
}






class MyClass;
class Singleton
{
public:
	/*static Singleton * getInstance()
	{
	Singleton obj;
	return  &obj;
	}*/
	Singleton(MyClass *p)
	{
		mchild = p;
	}
	
	void callAll();



	MyClass *mchild = nullptr;
};



class MyClass :public Singleton
{
	friend class Singleton;
public:
	MyClass() :Singleton(this)
	{

	}
private:
	void display()
	{
		std::cout << "Display:: huhha";
	}

};


void Singleton::callAll()
{
	if (mchild)
		mchild->display();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Singleton  *obj = new   MyClass;
	obj->callAll();

	return 0;
}

