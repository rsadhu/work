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
			std::cout << " function_Thread" << std::this_thread::get_id() << "\n";
		}
	}
	catch (std::exception e)
	{
		std::cout << " exc " << e.what();
	}
}


class Test
{
public :
	void setValue(const int x) 
	{
		m_val = x;
	//	m_valc = x;
		m_valm = x;
	}

	void setValue( int x) const 
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

int x;

int & get()
{
	return x;
}

class UInit
{
public:
	UInit(int d, char *c, float f)
	{
		std::cout << " uniform init -1 \n";
		int mInt = d;
		mChar = _strdup(c);
		mFloat = f;
	}

	UInit(std::initializer_list<int> l)
	{
	
	}

	void display()
	{
		std::cout << "\n int" << mInt << "\n char " << mChar << "\n flat " << mFloat;
	}
private:
	int mInt;
	char *mChar;
	float mFloat;
};

int _tmain(int argc, _TCHAR* argv[])
{
	/*std::thread t(function_thread);
	t.join();*/
	const Test ct;
	Test nct1;
	const int x = 9;
	ct.setValue(x);

	get() = 10;
	std::cout << " get:: val " << x;

	const int &xx = 10;

	UInit t = {1,"rakesh",0.04f };
	t.display();
	return 0;
}

