// CppAdv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>



static int cnt = 0;

template<typename T>
class Cpp11
{
	std::vector<T> mList;
public:
	Cpp11()
	{
		cnt++;
	}
	Cpp11(std::initializer_list<T>list)
	{
		cnt++;
		for (auto it : list)
		{
			mList.push_back(it);
		}
	}

	void display()
	{
		for (auto it : mList)
		{
			std::cout << " " << it;
		}
	}

	~Cpp11()
	{
		std::cout << cnt--;
	}
};

template<typename T>
class Wrapper
{
	/*Wrapper() = delete;
	Wrapper(const Wrapper &) = delete;
	Wrapper & operator=(const Wrapper &) = delete;*/
	T *mObj = nullptr;
public:
	Wrapper(T* o) :mObj(o){}
	Wrapper * operator & ();
	Wrapper & operator *();
	~Wrapper()
	{
		delete mObj;
	}
};


int main(int arg, char *argv[])
{
	Cpp11<char> obj1 = {'a','b','c','d'};
	obj1.display();

	std::cout << std::endl;

	Cpp11<int> obj2 = { 1,2,3,4,5,6,7,8,9,10 };
	obj2.display();


	Wrapper<Cpp11<int>> obj(new Cpp11<int>());
	return 0;
}

