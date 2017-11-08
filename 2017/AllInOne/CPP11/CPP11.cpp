// CPP11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include"_template.h"
#include<set>
#include<map>

//template<typename T>
//class LearnCpp11
//{
//	std::vector<T> mVector;
//public:
//	LearnCpp11(T &rhs) :v(rhs)
//	{
//
//	}
//	const T operator *()const { return mVector; }
//	T operator *() { return mVector; }
//	T * operator ->() { return &mVector; }
//	T begin() { return mVector.begin(); }
//	T end() { return mVector.end(); }
//	T operator++() {return mVector++;}
//};

template<typename T>
void print(std::initializer_list<T> &rhs)
{
	for (auto i : rhs)
	{
		std::cout << i << "  ";
	}
}

class BaseTest
{	
public:
	int a = 0;
	virtual void foo() { std::cout << "BaseTest::Foo "  << a << "\n"; }
};

class DerTest 
{
public:
	int a = 1;
	virtual void foo() { std::cout << "DerTest::foo--"<<a<<"\n"; }
};

class DerTest1 :public BaseTest,public DerTest
{
public:
	int a = 2;
	void foo() { std::cout << "DerTest1::foo--" << a << "\n"; }
};


class A
{
public:
	int a = 0;
	void display() {
		std::cout << "A:: a  " << a << "\n";
	}
};

class B:public A
{
public:
	int b = 0;
	void display() {
		std::cout << "B:: b  " << b << "\n";
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	//codilityTest();
	//LearnCpp11<std::initializer_list<int>> l={1,2,3,4,5,6,7};
	/*auto i = { 1,2,3,4,5,6,7 };
	print<int>(i);*/

	//DerTest dt;
	//dt.a = 10;
	//dt.foo();
	//BaseTest *bt = &dt;
	//bt->foo();
	//bt->a = 100;
	//dt.foo();
	//bt->foo();
	/*DerTest1 dt1;
	dt1.foo();
	try
	{
		DerTest &dt = dynamic_cast<DerTest &>(dt1);
		dt.foo();

		BaseTest &bt = dynamic_cast<BaseTest &>(dt1);
		bt.foo();
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
*/

	BaseTest bt;
	DerTest *dt = dynamic_cast<DerTest*>(&bt);
	if (dt)
		dt->foo();

	A *a = new A();
	a->display();

	//delete a;

	B b;
	b.display();

	B *bb = static_cast<B*>(a);
	
	bb->display();

	a = static_cast<A*>(bb);

	delete a;



	return 0;
}

