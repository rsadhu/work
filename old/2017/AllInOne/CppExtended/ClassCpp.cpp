#include "stdafx.h"
#include "ClassCpp.h"



ClassCpp::ClassCpp()
{
	std::cout << "ClassCpp::ClassCpp\n";
}


ClassCpp::~ClassCpp()
{
	std::cout << "ClassCpp::~ClassCpp\n";
}

int ClassCpp::display(int x)
{
	mData = x;
	return mData * mData;
}

int ClassCpp::display(int x)  const
{
	mData = x;
	return mData * mData;
}

int ClassCpp::display(int,float)
{
	return mData * mData;
}

int ClassCpp::display(int, int)
{
	return mData * mData;
}

int ClassCpp::sumUp(int x, int y, int d)
{
	return x + y + d;
}


//-------------------Der Class --------------------------//
int Der::display(int x)
{
	mData = x;
	mPrivData = x;
	return mData * mData;
}

int Der::display(int x)  const
{
	mData = x;
	return mData * mData;
}

int Der::display(int, float)
{
	return mData * mData;
}

int Der::display(int, int)
{
	return mData * mData;
}

int Der::sumUp(int x, int y, int d )
{
	return x + y + d;
}


int GrandChild::sumUp(int x, int y, int z)
{
	std::cout << "GrandChild:: sumUp\n";
	return x + y + z;
}
