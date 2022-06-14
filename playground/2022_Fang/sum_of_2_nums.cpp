#include <iostream>
#include <vector>

bool HasSumofTwo(std::vector<int> &rhs, int sum)
{
    int begin = 0, end = rhs.size() -1;

    while(begin <= end)
    {

        if ( (rhs[begin] + rhs[end]) <  sum)
            begin++;

        else
        if ( (rhs[begin] + rhs[end]) >  sum)
            end--;
        else
            return true;


    }

    return false;
}



int main(void)
{
    int sum = 10;
    std::vector<int> rhs = { 1, 2, 3, 4, 5, 6 };
    std::cout<<" \n do vec has "<< sum<< " "<< HasSumofTwo(rhs, sum);
    return 0;
}