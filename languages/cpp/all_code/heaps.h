#include <iostream>
#include <vector>
#include <algorithm>

void heapify(std::vector<int> &rhs)
{

}

//	std::vector<int> data = {5,1,-6, 0, 7, 4, 8};

void  createMaxHeap(std::vector<int> &rhs)
{
	for (int i = 0; i < rhs.size(); i++)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < rhs.size() && rhs[i] < rhs[left])
			std::swap(rhs[i], rhs[left]);

		if (right < rhs.size() && rhs[i] < rhs[right])
			std::swap(rhs[i], rhs[right]);
	}
}



void maxHeap(std::vector<int> &rhs)
{

}


