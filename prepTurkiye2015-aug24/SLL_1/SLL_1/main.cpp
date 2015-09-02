// SLL_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"SLL.h"
#include <iostream>
#include<string>
using namespace std;
 
void foo(int *p)
{
	 p = new int;
	 *p=90;
}

void test()
{
	int q=10;
	foo(&q);
	cout<<q<<endl;
	int *r  = new int;
	*r=200;
	foo(r);
	cout<<*r<<endl;
}

class test
{
public:
	test()
	{
		 p =  new int(9);
	}

	void display(){ cout<<*p<<endl;}
	//void change() { 
	int *p;
};



int _tmain(int argc, _TCHAR* argv[])
{
   //test();
	SLL sl;
	sl<0<1<2<3<4<5<6<7<8<9;
	sl.revDisplay();
	sl.display();
	return 0;
}

