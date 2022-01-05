#include <iostream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <ctime>


void shiftonesandzeros(std::vector<int> &rhs)
{
    int i = 0, j = rhs.size()-1;

    while(i <= j)
    {
        if (rhs[i] == 1 && rhs[j] == 0)
        {
            std::swap(rhs[i], rhs[j]);
            i++;
            j--;
        }
        else
        if (rhs[i] == 0)
        {
            i++;
        }
        else
        if (rhs[j] == 1)
        {
            j--;
        }
    }
}



int main(void)
{
    std::vector<int> v =  {0,1,1,0,1,0,1,0,1, 0};

    auto t1 = std::chrono::high_resolution_clock::now ();

    shiftonesandzeros(v);

    auto t2 = std::chrono::high_resolution_clock::now ();

    std::chrono::duration < double,std::milli > ms = t2 - t1;


    printf("%*d", 30, 100);


    return 0;
}