#include "MyVector.h"
#include "linklist.h"
#include<iostream>

void testVector()
{
    MyVector<int> vec = { 1, 2};

    //TODO: Implement Iterator

    for(int i = 1; i <= 6; i++)
    {
        vec.push(i);
    }

    vec.prepend(0);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    vec.insert(10, 100);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    std::cout<<"\n";
}

void testLinkList()
{
    LinkList<int> list;
    // list.
}

int main(void)
{
    testVector();
  //  testLinkList();
    return 0;
}
