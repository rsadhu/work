#pragma once
#include<iostream>
class Der;
class ClassCpp
{
	friend class Der;
public:
	ClassCpp();
	int display(int);
	int display(int) const;
	int display(int,float);
	int display(int, int);
	virtual ~ClassCpp();	
	virtual int sumUp(int, int, int d=0);
protected:
	mutable int mData = 0;
private:
	int mPrivData = 10;
};


class Der :public ClassCpp
{
public:
	~Der()
	{
		std::cout << "Der::~Der\n";
	}

	Der()
	{
		std::cout << "Der::Der\n";
	}

	int display(int);
	int display(int) const;
	int display(int, float);
	int display(int, int);
	virtual int sumUp(int, int, int d = 0);
};

class GrandChild : public Der
{
public:
	~GrandChild()
	{
		std::cout << "GRandChild::~GrandChild\n";
	}

	GrandChild()
	{
		std::cout << "GRandChild::GrandChild\n";
	}

	int sumUp(int, int, int);
};

