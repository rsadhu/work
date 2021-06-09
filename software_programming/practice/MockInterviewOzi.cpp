//
// Created by rsadhu on 13.04.20.
//
#include <iostream>
#include <vector>


void planks()
{
    std::vector<int> A{ 1, 4, 5, 8};
    std::vector<int> B { 4, 5, 9, 10};
    std::vector<int> C{ 4, 6,7,0,11};
    int cnt = 0;

    for(auto it :C)
    {
        int lb = 0, ub = A.size()-1;
        while( lb <=ub) {
            int mid = (lb + ub) / 2;
            if (it >= A[mid] && it <= B[mid])
            {
                cnt++;
                break;
            }
            else
            if (it < A[mid] || it < B[mid]) {
                ub = mid-1;
            } else if (it > A[mid] || it > B[mid]) {
                lb = mid + 1;
            }
        }
    }
    std::cout<<cnt;
}


int main()
{
    planks();
    return 0;
}