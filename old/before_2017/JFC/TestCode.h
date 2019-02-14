#pragma
#ifndef RAKESH_H
#define RAKESH_H
#include<thread>
#include<mutex>
#include<iostream>

int cnt = 1;
std::mutex m;
void workerThread()
{
	std::lock_guard<std::mutex> guard(m);
	std::cout << "\nhi there , i am worker thread:: " << cnt << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cnt++;
}


class Functor
{
public:
	void operator()(int d)
	{
		std::lock_guard<std::mutex> guard(m);
		std::cout << "Functor:: int " << d << std::endl;
		d = 1000;
	}
};


class DeadLock
{
	std::mutex m_m1, m_m2;
public:
	void test1(int p)
	{
		std::lock_guard<std::mutex> lock(m_m1);
		std::lock_guard<std::mutex> lock1(m_m2);
		std::cout << "test1:: DeadLock  ::  " << p << "\n";
	}

	void test2(int p)
	{
		std::lock_guard<std::mutex> lock1(m_m1);
		std::lock_guard<std::mutex> lock(m_m2);

		std::cout << "test2:: DeadLock :: " << p << "\n";
	}
};




void testThread(DeadLock &ref, int &x)
{
	for (int i = 0; i < 100; i++)
		ref.test1(i);

	x = 100;
}

#include"TrieDS.h"


void testoldcode()
{
	/*std::thread t1(workerThread);

	t1.join();*/

	/*std::string s;
	for (int i = 0; i < 100; i++)
	{
	std::string res = std::string("Writing from main Thread\n");// +to_string<int>(i);
	LogFile::getInstance()->writeToFile(res);
	}*/

	/*DeadLock d1;
	int x = 10;
	std::thread t1(testThread, std::ref(d1),std::ref(x));
	std::cout << "x :: " << x << std::endl;
	t1.join();


	auto t = [](int x, int y){return x*y; };

	std::cout<<"lamba func retuns :  "<<t(5, 5);*/

	TrieDS trie;
	trie.insert(std::string("apple"));
	trie.insert(std::string("apricot"));
	trie.insert(std::string("application"));
	trie.insert(std::string("parrot"));

	if (trie.search(std::string("appl")))
		std::cout << " present \n";
	else
		std::cout << " not present\n";

}


class TestThreads
{
	std::recursive_mutex mu;
	int res = 0;
	std::thread t1;
	std::thread t2;;

public:


	void mul(int x, int y)
	{
		std::lock_guard<std::recursive_mutex> lock(mu);
		res = x*y;
	}

	void div(int x, int y)
	{
		std::lock_guard<std::recursive_mutex> lock(mu);
		res = x / y;
	}


	int operations(int x, int y)
	{
		t1 = std::thread(&TestThreads::div, this, x, y);
		t2 = std::thread(&TestThreads::mul, this, x, y);
		t1.join();
		t2.join();
		return res;
	}
};

std::mutex mu, mu1;
std::condition_variable cond;

int globalData = 0;

bool gVar = false;
void func1()
{
	std::unique_lock<std::mutex> locker(mu);
	locker.lock();
	std::cout << "value of global Data:: " << globalData << "\n";
	for (int i = 0; i < 3; i++)
	{
		globalData++;
	}
	locker.unlock();
	gVar = true;
	cond.notify_one();
}


void func2()
{
	std::unique_lock<std::mutex> locker(mu1);
	locker.lock();
	cond.wait(locker, [](){return gVar; });
	for (int i = 0; i < 3; i++)
	{
		std::cout << "value of global Data:: " << globalData << "\n";
		globalData--;
	}
	std::cout << "value of global Data:: " << globalData << "\n";
	locker.unlock();
}

void threadFunc1()
{
	std::lock_guard<std::mutex> lock(mu);


	globalData++;

	std::this_thread::sleep_for(std::chrono::seconds(1));

}

void threadFunc2()
{
	std::lock_guard<std::mutex> lock(mu);

	globalData++;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << " helllo  ::  " << globalData << "\n";


}


std::mutex mu;

class MyFunctor
{
public:
	void operator()(std::string &m)
	{
		//std::lock_guard<std::mutex> lock(&mu);
		mu.lock();
		m = " messaged changed in thread";
		for (int i = 0; i < 50; i++)
		{
			std::cout << "Functor :: " << m.c_str() << ": " << i << "\n";
		}
		mu.unlock();
	}
};

class Runnable
{
public:
	void start()
	{
		cbThread = std::thread(&Runnable::run, this);
		cbThread.join();
	}

	virtual void run() = 0;
private:
	std::thread cbThread;
};


class  MyClass : public Runnable
{
public:
	void run()
	{
		std::cout << " Run called \n";
	}

};



void threadFunc2()
{
	std::cout << "threadFunc2:: 2";
}




typedef void(*fptr)(int);
void callback(int res)
{
	std::cout << " result is :: " << res << "\n";
}

#include<queue>
#include<stack>



std::stack<int> gVec;

long gV = 0;
std::mutex mut, mut2;


void reader()
{
	while (1)
	{
		if (!gVec.empty())
		{
			mut.lock();
			int data = gVec.top();
			gVec.pop();
			mut.unlock();

			mut2.lock();
			std::cout << "Reader :: " << data << "\n";
			mut2.unlock();
		}
	}
}

void writer(int limit)
{
	for (int i = 1; i <= limit; i++)
	{
		mut.lock();
		gVec.push(i);
		mut.unlock();
		mut2.lock();
		std::cout << "Writer:: " << i << "\n";
		mut2.unlock();
	}
}

void test1()
{
	std::thread t2(writer, 10);
	std::thread t1(reader);

	t1.join();
	t2.join();


	MyClass  mc;
	mc.start();
	MyFunctor fc;

	std::string s = "message from Main Thread";
	std::thread t((MyFunctor()), std::ref(s));
	for (int i = 0; i < 50; i++)
	{
		std::cout << s.c_str() << "   " << i << "\n";
	}


	t1.detach();

	fptr b = callback;
}


#endif