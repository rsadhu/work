#include "stdafx.h"
#include "DP_PROBS.h"
#include <iostream>
using namespace std;

DP_PROBS::DP_PROBS()
{
}

DP_PROBS::~DP_PROBS()
{
}

int DP_PROBS::factorialRec(int n)
{
	if (n == 0)
		return 1;
	return n = n * factorialRec(n - 1);
}

void classicFIBO(int n)
{
	int a, b;
	a = 0;
	b = 1;
	while (n-- > 0)
	{
		cout << a << " ";
		b = b + a;
		a = b - a;
	}
}

void DP_PROBS::fiboRec(int n)
{
}

void DP_PROBS::fiboDP(int n)
{
}
