#pragma once
#include<iostream>
using namespace std;

class interface
{
public:
	virtual void display() = 0;
	//virtual ~interface();
};

class RealClass :public interface
{
public:
	void display();
	~RealClass(){

	}

};

class ProxyClass:public interface 
{
	interface *mInt;
public:
	ProxyClass()
	{
		this->mInt = new RealClass;
	}

	void  display();
	~ProxyClass()
	{
		delete mInt;
	}
};

