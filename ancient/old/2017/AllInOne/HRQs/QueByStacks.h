#pragma once
#include<stack>
template<typename Type=int>
class QueByStacks
{
public:
	bool isEmpty(){ return mDequeStack.empty() && mEnqueStack.empty();}
	void enque (Type data);
	void deque();
	Type front();
private:
	std::stack<Type>mEnqueStack;
	std::stack<Type>mDequeStack;
};

template<typename Type>
void QueByStacks<Type>::enque(Type data)
{
	mEnqueStack.push(data);
}




template<typename Type>
void QueByStacks<Type>::deque()
{
	if (!mDequeStack.empty())
		return mDequeStack.pop();
	else
	{
		while (!mEnqueStack.empty())
		{
			mDequeStack.push(mEnqueStack.top());
			mEnqueStack.pop();
		}
		if (!mDequeStack.empty())
			return mDequeStack.pop();
	}
}

template<typename Type>
Type QueByStacks < Type>::front()
{
	if (mDequeStack.empty())
	{
		while (!mEnqueStack.empty())
		{
			mDequeStack.push(mEnqueStack.top());
			mEnqueStack.pop();
		}
	}

	if (!mDequeStack.empty())
		return mDequeStack.top();
	else
		return -999;	
}