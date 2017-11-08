#include "stdafx.h"
#include "CppAdvClass.h"
#include"_template.h"

CppAdvClass::CppAdvClass(int x)
{
}

//CppAdvClass::CppAdvClass(char c)
//{
//
//}


CppAdvClass::~CppAdvClass()
{
}
#define N 10

void sepPosNeg()
{
	int *arr = new int[N] {1, 2, 3, -9, 7, -5, 4, 22, 0, -99};
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}

	delete[]arr;

	for (int i = 0, j = N - 1; i < j;)
	{

	}
}

std::mutex mu;
std::condition_variable cv;
std::vector<int > gvec = { 1,2,3,4,5,6 };
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
	mutable MyType *mData = nullptr;
};

class MutableConst
{
	mutable int mA = 0;
	int mB = 9;
public:
	MutableConst() {}
	//virtual ~MutableConst() = 0;
	void setInt(const int val) const
	{
		mA = val;
		//mB = val;
		//val *= 10;
	}

	void setAnotherInt(int &val) const
	{
		//mB = val;
		val *= 10;
	}


};
class P
{

};

class C :public P
{

};


class T
{

};

bool isDerivedFrom(P *par, C *child)
{
	if (dynamic_cast<P*>(child))
		return true;
	return false;
}

// CarlosNew.cpp : Defines the entry point for the console application.
//


class A
{
public:
	/*int  foo(int a)
	{
	std::cout << " foo::A  ";
	return a*a;
	}*/

	A()
	{
		//A(9);
	}

	A(int b)
	{

	}
	char   foo(char a)
	{
		std::cout << " foo::A-- double ";
		return a*a;
	}
};


class B :public A
{
public:
	int  foo(int a)
	{
		std::cout << " foo::B  ";
		return a + 1;
	}
};


class MyExcption :public std::exception
{
public:
	MyExcption()
	{

	}

	//virtual const char *  what()  const throw (){ return "__default__message"; }

};


class AA
{
public:
	virtual void foo() {}
};

class BB : public A
{
public:
	virtual void foo() {}
};

class CC :public A
{
public:
	virtual void fo() {}
};

class DD : public  A
{
public:
};

int testss()
{
	B b;
	std::cout << b.foo(9) << std::endl;
	std::cout << b.A::foo('c') << std::endl;

	try
	{
		int i = 0;
		AA a;
		BB &b = dynamic_cast<BB&>(a);

		CC c;
		BB &dd = dynamic_cast<BB&>(c);

		DD &d = dynamic_cast<DD&>(b);

	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;

	/*P par;
	C child;
	T tmp;

	cout << isDerivedFrom(&par, &child);*/

	/*std::thread t1(threadFunc1);
	std::thread t2(threadFunc2);*/
	/*	MutableConst m;
	int a = 9;
	m.setAnotherInt(a);
	m.setInt(a);

	MutableConst  const cm;
	cm.setInt(a);
	cm.setAnotherInt(a);*/

	//int myints[] = { 10, 20, 30, 5, 15 };
	//std::vector<int> v(myints, myints + 5);

	//std::make_heap(v.begin(), v.end());
	//std::cout << "initial max heap   : " << v.front() << '\n';

	//std::pop_heap(v.begin(), v.end());
	//v.pop_back();
	//std::cout << "max heap after pop : " << v.front() << '\n';

	//v.push_back(99);
	//std::push_heap(v.begin(), v.end());
	//std::cout << "max heap after push: " << v.front() << '\n';

	//std::sort_heap(v.begin(), v.end());

	//std::cout << "final sorted range :";
	//for (unsigned i = 0; i<v.size(); i++)
	//	std::cout << ' ' << v[i];

	//std::cout << '\n';

	testss();
	class MyType
	{
	public:
		int key = -1;
		MyType(int f = 0) :key(f)
		{

		}
		bool operator <(const MyType &rhs) const
		{
			if (key < rhs.key)
				return true;
			return false;
		}
	};

	std::set<MyType> s;
	for (int i = 0; i < 100; i++)
	{
		MyType t(i);
		s.insert(t);
	}

	/*for (int i = 40; i < 140; i++)
	{
	MyType t(i);
	s.insert(t,[t](const auto& lhs)const  {return key < lhs.key; });
	}*/

}

int
codilityTest()
{
	std::vector<int> v = { 2 };
	std::map<int, int>map;
	for (auto it : v)
		map[it] += 1;
	if (map.begin()->first < 1)
		return 1;
	if (map.begin()->first > 1)
		return 1;
	int i = map.begin()->first;
	for (auto it : map)
	{
		if (it.first != i)
		{
			return i;
		}
		i++;
	}

	return map.rbegin()->first + 1;;
}
