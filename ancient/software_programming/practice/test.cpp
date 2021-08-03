#include <set>
#include <iostream>

int nthUglyNumber(int n) {
    int j=0;
    std::set<int>l;
    while(l.size() <= n)
    {
        j++;

        if (j % 2 ==0 || j % 3 == 0 || j % 5 ==0)
        {
            l.insert(j);                
        }            

    }       

    return *l.end();
}

int main()
{
    auto n = nthUglyNumber(10);
    std::cout<< n;
    return 0;
}
