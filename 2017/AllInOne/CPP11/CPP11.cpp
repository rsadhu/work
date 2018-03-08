// CPP11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include"_template.h"
#include<set>
#include<map>
#include<thread>
#include<mutex>
#include<future>



void function_thread()
{
	try
	{
		while (1)
		{
			std::wcout << " function_Thread" << std::this_thread::get_id() << "\n";
		}
	}
	catch (std::exception e)
	{
		std::wcout << " exc " << e.what();
	}
}


class Test
{
public:
	void setValue(const int x)
	{
		m_val = x;
		//	m_valc = x;
		m_valm = x;
	}

	void setValue(int x) const
	{
		//m_val = x;
		//m_valc = x;
		m_valm = x;
	}
private:

	int m_val = 10;
	const int m_valc = 10;
	mutable int m_valm = 10;
};

class UInit
{
public:
	UInit()
	{

	}

	UInit(int d, char *c, float f)
	{
		std::wcout << " uniform init -1 \n";
		int mInt = d;
		mChar = _strdup(c);
		mFloat = f;
	}

	UInit(std::initializer_list<int> l)
	{

	}

	void display()
	{
		std::wcout << "\n int" << mInt << "\n char " << mChar << "\n flat " << mFloat;
	}
private:
	int mInt;
	char *mChar;
	float mFloat;
};



void fun(const int &i)
{
	std::wcout << "fun(const int &) called ";
}
void fun(int &i)
{
	std::wcout << "fun(int &) called ";
}


class XYZ
{
public:
	void setValue(const int &x)
	{
		/*this->x = x;
		this->mx = x;*/
	}
	void setValue(const int &x) const
	{

	}
private:
	int x;
	mutable int mx;
	const int cx = 10;
};

#include<memory>

void discodance(std::shared_ptr<int> &pp)
{
	std::wcout << "\none more shared-ptr:: " << *pp << "\n";
	std::wcout << "\n number of instances :: " << pp.use_count();
}


void foo(std::shared_ptr<int>  psptr)
{
	std::wcout << " shared-ptr:: " << *psptr;
	discodance(psptr);
	std::wcout << "\n number of instances :: " << psptr.use_count();
}


class z
{
public:
	~z()
	{
		std::wcout << "\nz::~z";
	}
};
template<typename T>
class SmartPointer
{
public:
	SmartPointer(T s)
	{
		m_Str = std::make_unique<T>(s);
	}

	void display() const
	{
		if (m_Str)
			std::wcout << "\nstring::  " << *m_Str;
		else
			std::wcout << " unique ptr str:: is null\n";
	}

private:
	std::unique_ptr<T> m_Str;
};


void t()
{
	const int i = 10;

	const XYZ  c_xyz;

	XYZ xyz;

	c_xyz.setValue(i);

	xyz.setValue(10);

	fun(i);

	std::shared_ptr<int> sptr = std::make_shared<int>(7);
	std::wcout << "\n shared_ptr:: " << *sptr << "\n";
	foo(sptr);
	std::wcout << "\n number of instances :: " << sptr.use_count();

	SmartPointer<char*> sp("hello World");;
	sp.display();
	//z abc;
	//	SmartPointer<z> sp1(abc);
	auto movPtr = std::move(sp);

	sp.display();
	movPtr.display();
}

class GPar
{
public:
	int x = 10;
	GPar()
	{
		std::wcout << "GPar::GPar\n";
	}
	void discoStation()
	{
		std::wcout << " GPar::discoStation\n";
	}

	virtual void display(char16_t *s)const
	{
		std::wcout << " GPar:: display" << s << "    " << x << "\n";
	}

	virtual ~GPar()
	{
		std::cout << "Gpar:~Gpar\n";
	}
};


class Par1 : virtual public GPar
{

public:

	Par1()
	{
		std::wcout << "Par::Par1\n";
	}

	Par1(int x)
	{
		this->x = x;
		std::wcout << "Par::Par1::x\n";
	}


	void culpritFunc()
	{
		std::wcout << " cultpritFunc:: x    " << x << "\n";
	}

	virtual void display(char16_t *s) const
	{
		std::wcout << " Par1::display : " << s << "    " << x << "\n";
	}
};

class Par2 : virtual public GPar
{
public:
	Par2()
	{
		std::wcout << "Par::Par2\n";
	}

	Par2(int x)
	{
		this->x = x;
		std::wcout << "Par::Par2::x\n";
	}

	void culpritFunc()
	{
		std::wcout << " cultpritFunc:: x    " << x << "\n";
	}

	virtual void display(char16_t *s) const
	{
		std::wcout << " Par2::display : " << s << "    " << x << "\n";
	}
};

class Der :public Par1, public Par2
{
public:
	Der() : Par1(3), Par2(4), GPar() {}
	~Der()
	{
		std::wcout << "~Der::\n";
	}
	void display(char16_t *s)const
	{
		std::wcout << " Der::display : " << s << "\n";
	}

	void culpritFunc()
	{
		std::wcout << " cultpritFunc:: x    " << x << "\n";
	}
};


//class A
//{
//	int x;
//public:
//	void setX(int i) { x = i; }
//	void print() { std::wcout << x; }
//};
//
//class B : public A
//{
//public:
//	B() { setX(10); }
//};
//
//class C : public A
//{
//public:
//	C() { setX(20); }
//};
//
//class D : public B, public C {
//};



void refInt(int & x)
{
	std::cout << "lvalue ref " << x << "\n";
}


void refInt(int && x)
{
	std::cout << "rvalue ref " << x << "\n";
}

void refInt(const int &x)
{
	std::cout << "const lvalue ref " << x << "\n";
}


class Ref
{
public:
	Ref() = default;
	Ref(const Ref &rhs)
	{
		std::cout << "Ref::copy Constructor\n";
	}

	Ref(const Ref && rhs)
	{
		std::cout << "Ref::move Constructor\n";
	}
};

void sendByCopy(Ref r)
{

}

void sendByRef(Ref &r)
{

}

Ref createRef()
{
	return Ref();
}


template<typename T>
class ThreadObj
{
public:
	ThreadObj(T p) :mPara(p)
	{
		mKeepActive.store(true);
		mWait.store(true);
		mThread  = new std::thread(&ThreadObj::counter,this);	
		mThread1 = new std::thread(&ThreadObj::counter, this);
	}

	void wait()
	{
		while (mWait.load());
	}

	std::mutex mMutex;
	void counter()
	{
		std::lock_guard<std::mutex> lock(mMutex);
		while (mKeepActive.load())
		{
			std::cout << " counter:: "<<mPara++;
			std::chrono::milliseconds(100);
		}
	}

	void signalHandler()
	{

	}

	void stop()
	{
		mKeepActive.store(false);
		mWait.store(false);
	}

	~ThreadObj()
	{
		mThread->join();
		mThread1->join();
		delete mThread1;
		delete mThread;
	}

private:
	std::thread *mThread,*mThread1;
	T mPara;
	std::atomic_bool mKeepActive;
	std::atomic_bool mWait;
};


void tttt()
{	//int x = 10;
	//refInt(x);
	//refInt(10);
	//

	//Ref f;
	//sendByCopy(f);
	//sendByRef(f);
	//sendByCopy(std::move(createRef()));

	/*Par1 * p1 = new Der();
	p1->display("hello world !!!");

	Par2  *p2 = new Der();
	p2->display("Hello World!!!");
	*/

	//	GPar *gp = new Der();
	//gp->display("");

	//Der d;
	//d.display(u"çok hoş!!!");
	//d.culpritFunc();

	///*D d1; 
	//d1.print();*/
	//
	//int cx = 9, yx = 100;
	//auto lf = [=](int x, int y) { return yx-cx*(x + y); };
	//std::cout << lf(9, 1);


	GPar * gp = new Par1();

	Par1* par1 = nullptr;

	par1 = dynamic_cast<Par1*>(gp);
	if (par1)
	{
		par1->display(u"hello");
	}

	//Par1 p;
	//try
	//{
	//	p = dynamic_cast<Par1&>(*gp);
	//}
	//catch (std::exception e)
	//{
	//	std::cout << e.what();
	//}

	//Par1 p1(10);
	//Par2 p2(20);

	//GPar *gp1 = &p1;
	//GPar *gp2 = &p2;

	//gp1->display(u"hello");
	//gp2->display(u"hello");



	//gp1 = dynamic_cast<Par2*>(gp2);
	//gp1->display(u"hi");


	/*class Base
	{
	public:
	virtual ~Base()
	{

	}
	};


	class Der :public Base
	{
	public:

	};



	Base *b= new Der;
	Der *d;
	d = dynamic_cast<Der*>(b);*/


}

#include<queue>
#include<condition_variable>

std::condition_variable cond;
std::mutex mut;
std::queue<int> que;
bool wait = false;

void threadedFunction()
{	
	while (wait)
	{
		std::unique_lock<std::mutex> locker(mut);
		cond.wait(locker, [] { return !que.empty(); });
		while (!que.empty())
		{
			std::cout << "\n data:: " << que.front() << "\n";
			que.pop();
		}
	}
}

#include<future>


int _tmain(int argc, _TCHAR* argv[])
{			
	/*wait = true;
	std::thread t(threadedFunction);
	int d;
	while (wait)
	{
		std::unique_lock<std::mutex> locker(mut);
		std::cin >> d;
		if (d == 0)
		{
			wait = false;
		}
		else
		{
			que.push(d);			
		}
		cond.notify_all();
		locker.unlock();
	}
	t.join();*/

	std::promise<int> input;
	//std::future<int> ret =  std::async(std::launch::async,[=] ( std::promise<int> &input ) 
	//{
	//	auto i = input.get_future().get();
	//	std::cout << i << " aysnc function called\n";
	//	std::chrono::milliseconds(1000);
	//	return i * i;
	//},input );

	input.set_value(10);	
	
	//std::cout << " return from asnc :: future" << ret.get() << "\n";
	
	return 0;
}

