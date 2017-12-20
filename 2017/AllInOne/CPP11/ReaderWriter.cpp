#include "stdafx.h"
#include "ReaderWriter.h"


ReaderWriter::ReaderWriter()
{
}


ReaderWriter::~ReaderWriter()
{
}


#ifdef R

namespace
{

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
		virtual void foo() { std::cout << "BaseTest::Foo " << a << "\n"; }
	};

	class DerTest
	{
	public:
		int a = 1;
		virtual void foo() { std::cout << "DerTest::foo--" << a << "\n"; }
	};

	class DerTest1 :public BaseTest, public DerTest
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

	class B :public A
	{
	public:
		int b = 0;
		void display() {
			std::cout << "B:: b  " << b << "\n";
		}
	};


	int mult(std::future<int> &p)
	{
		int fac = 1;
		int v = p.get();
		if (v == 0)
			return fac;
		for (int i = 1; i <= v; i++)
			fac *= i;
		return fac;
	}

	//namespace xyz {
	//	std::mutex mu;
	//	std::condition_variable cond;
	//	bool condtion_bool = false;
	//
	//	void thread1(int &p)
	//	{
	//		std::unique_lock<std::mutex> locker(mu);
	//		p *= 10;
	//		condtion_bool = true;
	//		cond.notify_all();
	//	}
	//}
	//using namespace xyz;
	//if (0)
	//{
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

	//BaseTest bt;
	//DerTest *dt = dynamic_cast<DerTest*>(&bt);
	//if (dt)
	//	dt->foo();

	//A *a = new A();
	//a->display();

	////delete a;

	//B b;
	//b.display();

	//B *bb = static_cast<B*>(a);

	//bb->display();

	//a = static_cast<A*>(bb);

	//delete a;

}

//std::promise<int> p;
//std::future<int> f = p.get_future();
//std::future<int> ret = std::async(std::launch::async,mult, std::ref(f));
//p.set_value(4);
//std::cout << ret.get();

//int val = 10;
//std::thread t(thread1, std::ref(val));

//std::unique_lock<std::mutex> locker(mu);
//cond.wait(locker, [](){return condtion_bool; });
//std::cout << "val now" << val;

}
#endif