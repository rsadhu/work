// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>
#include<vector>
using namespace std;

int solution(vector<int> & A) {
	int n = A.size();
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] == A[i + 1])
			result = result + 1;
	}
	int r = 1;
	for (int i = 0; i < n; i++) {
		int count = 0;
		if (i > 0) {
			if (A[i - 1] != A[i])
				count = count + 1;
			else
				count = count - 1;
		}
		if (i < n - 1) {
			if (A[i + 1] != A[i])
				count = count + 1;
			else
				count = count - 1;
		}
		r = std::max(r, count);
	}
	return result + r;
}

#include<cmath>

double areaCircle(int x1, int y1, int r1, int x2, int y2, int r2) {
	// write your code in C++14 (g++ 6.2.0)
	double  d = std::hypot(x2 - x1, y2 - y1);
	if (d < (r1 + r2))
	{
		double a = std::pow(r1, 2);
		double b = std::pow(r2, 2);
		double x = (a - b + d*d) / (2 * d);
		double z = x*x;
		double y = std::sqrt(a - z);
		if (d<std::abs(r2 - r1))
		{
			return 3.141592653 *std::min(a, b);
		}
		return a* std::asin(y / r1) + b*std::asin(y / r2) - y* (x + std::sqrt(z + b - a));
	}
	return 0.0;
}

//#include<climits>
//int recCountVisible(tree *root, int maxVal)
//{
//	if (!root)
//		return 0;
//	int tmp = std::max(maxVal, root->x);
//	if (root->x >= maxVal)
//	{
//		return 1 + recCountVisible(root->l, tmp) + recCountVisible(root->r, tmp);
//	}
//	else
//	{
//		return recCountVisible(root->l, tmp) + recCountVisible(root->r, tmp);
//	}
//}

int main()
{
	//vector<int> v = { 1, 1, 0, 1, 0, 0 ,0,1,1,0,0};
	//int d= solution(v);
	double a = areaCircle(2, 2, 3, 5, 5, 3);
    return 0;
}

