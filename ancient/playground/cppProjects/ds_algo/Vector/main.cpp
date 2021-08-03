#include<iostream>

#include"Vector.h"

int main(void)
{
    dsa::Vector<int> s;
    for(int i =0 ;i<100;i++)
        s.push_front(i);

    for(uint i=0;i<s.size();i++)
    {
        std::cout<<" data is "<< s[i]<<"\n";
    }

    for(uint i=0;i<s.size();i++)
    {
     std::cout<<" data is "<< s.at(i)<<"\n";
    }

    return 0;
}
