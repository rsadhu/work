#pragma once
class Node
{
public:
	Node(int d) : mData(d), left(0), right(0)
	{
	}

	int mData;
	Node *left, *right;
};

class SLL
{
public:
	SLL();
	virtual ~SLL();

private:
};
