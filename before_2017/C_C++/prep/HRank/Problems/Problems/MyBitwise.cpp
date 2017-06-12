#include "stdafx.h"
#include "MyBitwise.h"


MyBitwise::MyBitwise(int x) :mData(x)
{
}


MyBitwise::~MyBitwise()
{
}


int  MyBitwise::countBitOne()
{
	int bits(0);
	int d = mData;
	do
	{
		if (d & 1 == 1)
			bits++;
		d = d >> 1;
	} while (d != 0);
	return bits;
}

void MyBitwise::leftCircularRotation(int k)
{	
	int size = sizeof(mData)*8;
	while (k)
	{
		int bit = (mData >> size) & 1;
		mData <<= 1;
		mData |= bit;
		k--;
	}

}

void MyBitwise::rightCircularRoation(int k)
{

}
