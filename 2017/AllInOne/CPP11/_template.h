#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include"CppAdvClass.h"
#include<map>
#include<set>
#include<exception>
#include<iostream>
#include<thread>
#include<mutex>
#include <condition_variable>
#include <chrono>
#include<list>
#include<vector>
#include<exception>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include<memory>

template<typename T>
class _template
{
public:
	_template();
	~_template();
};


template<class Type>
void function(Type t,int n)
{
	t(n);
}

#ifdef OLD_CODE


void foo(CppAdvClass c)
{

}

void foo(int &&)
{

}

void foo(int &)
{

}



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
public:
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

			for (auto it : common_space)
				std::cout << "  " << it;
		}
		locker.unlock();
	}
}


void producer(/*std::shared_ptr<int> d*/)
{
	int n = 100000;
	while (n >= 0)
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

template<typename U>
class abc
{
public:

	void setItem(U x)
	{
		a = x;
	}
private:
	U a;
};

template <typename T = int, typename X = abc<T>>
T function(T a, X b)
{
	b.setItem(a);
	return a;
}


template<typename hybridType>
void abrakadabra(hybridType &t)
{
	for (int i = 0; i < 100; i++)
	{
		t.push_back(i);
	}
}





template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
	auto len = end - beg;
	if (len < 1000)
		return std::accumulate(beg, end, 0);

	RAIter mid = beg + len / 2;
	auto handle = std::async(std::launch::async,
		parallel_sum<RAIter>, mid, end);
	int sum = parallel_sum(beg, mid);
	return sum + handle.get();
}

int task()
{
	std::vector<int> v(10000, 1);
	std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
	return 0;
}



#include<chrono>

int  testfunc(int)
{
	std::cout << "async ::  " << std::this_thread::get_id;
	std::this_thread::sleep_for(std::chrono::seconds(100));
	return 999;
}


//template<typename ...args>
//void variadicTemp(typename ...args)
//{
//
//}


template<typename ...args>
class VClass
{
public:
	VClass(args ...t)
	{

	}


	void display()
	{
		for (auto it : mData)
		{
			std::cout << mData << "\n";
		}
	}

	std::vector<int> mData;

};


template <typename T>
void bar(T t) {}

void foo2() {}

template <typename Car, typename... Cdr>
void foo2(Car car, Cdr... cdr)
{
	bar(car);
	foo2(cdr...);
}




void cElipsis(int num, ...)
{
	va_list args;
	_crt_va_start(args, num);
	int tot = 0;
	for (int i = 0; i < num; i++)
	{
		tot += _crt_va_arg(args, int);;
	}
	std::cout << tot << std::endl;
}
#endif
#endif