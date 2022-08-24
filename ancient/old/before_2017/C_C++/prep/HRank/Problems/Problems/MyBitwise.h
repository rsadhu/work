#pragma once
class MyBitwise
{
public:
	MyBitwise(int x);
	~MyBitwise();
	int countBitOne();
	void leftCircularRotation(int k);
	void rightCircularRoation(int k);

private:
	int mData;
};
