// CppExtended.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <future>

std::mutex mu;
std::deque<int> deq = { -1 };
std::condition_variable cond;
bool bool_val = false;



void readerThread()
{
	while (!bool_val || !deq.empty())
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, []()
		{
			return !deq.empty();
		});
		std::cout << "  " << deq.front();
		deq.pop_front();
	}
}


void writerThread()
{	
	int d = 1;

	while (d != 0)
	{
		std::unique_lock<std::mutex> locker(mu);
		std::cin >> d;
		deq.push_back(d);
		cond.notify_all();
		locker.unlock();
	}
	bool_val = true;
}

#ifdef RAKESH
template<typename T>
constexpr T sqfun(const T &p)
{
	return p * p;
}




class XYZ
{

public: 
	void displayABC();	
};



class ABC
{
	friend class XYZ;
	friend void dostFunction();
public:
	ABC()
	{
		std::cout << " ABC::ABC\n";
	}

	~ABC()
	{
		std::cout << " ABC::~ABC\n";
	}

	void display() { std::cout << " \nABC:: display :: " << data; }
private:
	int data = 0;
};


void XYZ::displayABC()
{
	{
		ABC abc;
		abc.data = 10001;
		abc.display();
	}
}

void dostFunction()
{
	ABC abc;
	abc.data = 100;
	abc.display();
}


template<typename T, typename U=char>
class MultiDataTypeClass
{	
public:
	MultiDataTypeClass() = default;

	MultiDataTypeClass(T data, U data1) :m_Data(data), m_CharData(data1)
	{

	}

protected:
	void display() { std::cout << "MultiDataTypeClass:: display :: " << m_Data << " " << m_CharData; }
private:
	T m_Data;
	U m_CharData;
};

//template<typename T,typename U>
class DataType : public MultiDataTypeClass<int,char>
{
public:
	DataType() = default;
	DataType(int d,char c) :MultiDataTypeClass(d,c) {}
	void printAll()
	{
		display();
	}
};

int  test(int n)
{
	if(n > 1)
	{
		n=n*test(--n);
	}
	return n;
}

void reverseString(char *str)
{
	if (*str != '\0')
	{
		str++;
		reverseString(str);
	}

	std::cout << *str;
}

int sq(std::shared_future<int> f)
{
	int d = f.get();
	return d * d;
}

#include"ClassCpp.h"


class TestPtrs
{
	static int cnt;
public:
	TestPtrs()
	{
		cnt++;
		std::cout << " Def:: Const :: " << cnt << std::endl;
	}

	TestPtrs(int x) 
	{
		cnt++;
		std::cout <<" Const :: "<<cnt << std::endl;
	}

	TestPtrs(std::unique_ptr<int> &ptr);
	TestPtrs(std::shared_ptr<int> &ptr);
	void displayData();
	~TestPtrs()
	{
		cnt--;
		std::cout << " ~Dest :: "<<cnt << std::endl;
	}
private:
	std::shared_ptr<int> sptr;
	std::unique_ptr<int> uptr;
};


int TestPtrs::cnt = 0;

TestPtrs::TestPtrs(std::unique_ptr<int> &ptr)
{
	if (ptr)
	{
		
	}
}


TestPtrs::TestPtrs(std::shared_ptr<int> &ptr)
{

}


void TestPtrs::displayData()
{

}


void funcSharedPtr(std::shared_ptr<TestPtrs> p,int x=0)
{
	if (x <= 100)
	{
		funcSharedPtr(p, ++x);
	}
}


void funcUniquePtr(std::unique_ptr<TestPtrs> p, int x = 0)
{
	if (x <= 100)
	{
		funcUniquePtr(std::move(p), ++x);
	}
}

template<typename T>
class SmartPtrs
{
public:
	SmartPtrs() = default;
	void setData(T &d);
	void display();
private:
	std::unique_ptr<T> m_uptr;
	std::shared_ptr<T> m_sptr;
};


template<typename T>
void SmartPtrs<T>::setData(T &d)
{
	m_sptr = std::make_shared<T>(d);
	m_uptr= std::make_unique<T>(d);
}

template<typename T>
void SmartPtrs<T>::display()
{
	std::cout <<"shared::  "<< *m_sptr;
	std::cout <<"unique::  "<< *m_uptr;
}


class Ramin
{
public:
	Ramin(int x, bool b=true, std::vector<int> l=std::vector<int>(1,1))
	{

	}
	/*Ramin(std::initializer_list<int> l(1, 2, 3, 4))
	{
	std::initializer_list<int>
	}*/
};

template<typename T,typename U>
void add(T a, T b, U c)
{
	std::cout << " a+b = " << a + b << c;
}


template<typename T>
void add(T a, T b, T c, T d)
{
	std::cout << " a+b+c+d = " << a + b +c+d;
}
//
//void 
//testParaPack()
//{
//
//}

template <typename T>
double sum(T t) {
	return t;
}


template <typename T, typename... Rest>
double sum(T t, Rest... rest) 
{
	return t + sum(rest...);
}
#endif

int factorial(std::shared_future<int> f)
{
	return f.get() *10;
}

template<typename T>
class ParentClass
{
public:
	ParentClass()
	{
		std::cout << "ParentClass::ParentClass\n";
	}
	void funcParent() 
	{
		std::cout << "ParentClass:: funcParent\n";
	}

	virtual ~ParentClass()
	{
		std::cout << "ParentClass::~ParentClass\n";
	}
};

template<typename T>
class Child :public ParentClass<T>
{
	friend class Parentclass;
public:
	Child()
	{
		std::cout << "Child::Child\n";
	}
	void funcChild()
	{
		std::cout << "Child:: funcChild\n";
	}
	~Child()
	{
		std::cout << "Child::~Child\n";
	}
};





int main()
{
#ifdef RAKESH
////{
//////	std::thread reader(readerThread), writer(writerThread);
//////	reader.join();
//////	writer.join();
//////
//////
//////	constexpr int  res = sqfun<int>(9);
//////	
//////	std::cout << " \n Square of :: " << 9 <<"   "<< res;	
//////
//////	constexpr double res1 = sqfun<double>(9.1);
//////
//////	std::cout << "  \nSquare of :: " << 9.1 << "   " << res1;
//////
//////	dostFunction();
//////
//////	XYZ xvz;
//////	xvz.displayABC();
//////
//////	DataType dt ('a'-'0', 'a');
//////	dt.printAll();
//////
//////
//////
//////	//auto f = std::function(test);
//////	//std::bind(f);
//////
//////	std::cout<<test(9);
//////
//////	//reverseString(const_cast<char *>("hello"));
//////
//////
//////	//char16_t *utf16Char= "çesme";// = new char16_t[10];
//////	//strcpy("çesme", utf16Char);
//////	//memset(utf16Char, "jkjdks", 10);
//////	
////////	std::wcout << utf16Char;
////
////	//std::promise<int> par;
////	//std::shared_future<int> v = par.get_future().share();
////	//std::future<int> ret = std::async(std::launch::async,sq,v);
////
////	//par.set_value(10);
////	//std::cout << ret.get();
////	//
////
////	ClassCpp cc;
////	cc.display(9);
////	cc.display(9,10);
////	cc.display(9,10.9f);
////	const ClassCpp ccc;
////	ccc.display(10);
////
////
////
////
////	Der dc;
////	dc.display(9);
////	dc.display(9, 10);
////	dc.display(9, 10.9f);
////	const Der cdc;
////	cdc.display(10);
////
////
////	ClassCpp *base = new Der();
////	std::cout<<base->sumUp(1, 2, 3);
////	std::cout << base->sumUp(1, 2);
////	delete base;
////
////	std::unique_ptr<ClassCpp> baseptr(new Der);
////	baseptr->display(1);
////	baseptr->sumUp(1, 2);
//
//	/*auto p = std::unique_ptr<int>(new int(0));
//	TestPtrs tp(p);*/
//
//	/*std::unique_ptr<TestPtrs> ptr(new TestPtrs(0));
//	std::unique_ptr<TestPtrs> ptr1;
//
//	
//	std::shared_ptr<TestPtrs> sptr = std::make_shared<TestPtrs>();
//	funcSharedPtr(sptr,0);
//	std::unique_ptr<TestPtrs> uptr(new TestPtrs());
//	funcUniquePtr(std::move(uptr), 0);
//	if (uptr == nullptr)
//	{
//
//	}
//	else
//	{
//
//	}
//
//
//
//	ClassCpp *gp = new GrandChild();
//	std::cout<<gp->sumUp(9, 1, 0);
//
//
//	SmartPtrs<int> obj;
//	int x = 10;
//	obj.setData(x);
//	obj.display();*/
//
//	//add<int,char>(0, 1,'c');
//
//	//add<int,char>(9, 1,'a');
//	//add(9, 1, 11,19);
// //   
//	//
//	//auto res = sum(9, 0, 1, 3, 4, 5, 6, 7);
//
//
//class Dog
//{
//public:
//
//	Dog(int a, int h, std::string b):mAge(a),mHeight(h),mBreed(b)
//	{
//
//
//	}
//
//
//
//	Dog(std::initializer_list<int> l)
//	{
//		for (auto it : l)
//		{
//			
//		}
//	}
//
//	int mAge, mHeight;
//	std::string mBreed;
//};
//
//class CallAbleObj
//{
//public:
//
//	void  operator()(int t)
//	{
//		std::cout << t;
//	}
//
//
//};
//	Dog d = { 12,171,"Kangal" };
//	//std::future<int> fu1 = std::async(std::launch::async, factorial, ff);
//	//std::future<int> fu2 = std::async(std::launch::async, factorial, ff);
//	//std::future<int> fu3 = std::async(std::launch::async, factorial, ff);
//
//	////std::cout << fu.get();
//	////std::cout << fu1.get();
//	////std::cout << fu2.get();
//	////std::cout << fu3.get();
//
//	////// std::shared_ptr<CallAbleObj> cb = std::make_shared<CallAbleObj>();
//	////CallAbleObj cb, cb1;
//	////std::thread t11(cb,10);
//	////t11.join();
//
//
//	//std::promise<int> p1;
//	//std::future<int> data = p1.get_future();
//	////std::future<int> rett
	
#endif
	std::promise<int>p;
	std::shared_future<int> ff = p.get_future();
	std::future<int> fu = std::async(std::launch::async,factorial, ff);
	p.set_value(2);
	
	using namespace std::placeholders;

	auto f = std::bind([=]( int a,int b,int c)
	{
		std::cout << a + b + c;
	}, _1, _3, _2);

	f(1,2,3);
	ParentClass<int> *base = new Child<int>();
	base->funcParent();
	delete base;
	return 0;

}



