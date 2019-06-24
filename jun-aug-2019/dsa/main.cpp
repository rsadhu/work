#include "MyVector.h"
#include "linklist.h"
//#include  <iostream>

void testVector()
{
    MyVector<int> vec = { 1, 2, 3 , 4};

    //TODO: Implement Iterator

    for(int i = 1; i <= 6; i++)
    {
        vec.push(4+i);
    }

    vec.prepend(0);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    vec.insert(9, 100);

    std::cout<<"\n";

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<< "  "  <<vec.at(i);
    }

    std::cout<<"\n  vector popping out:: "<<vec.size()<<"\n";


    for(int i=0;i<vec.size();i++)
    {
        std::cout<<vec.pop()<<" ";
    }


    std::cout<<"\n size is "<< vec.size();
}

void testLinkList()
{
    LinkList<int> list;
    for(int i=1; i <= 10; i++)
        list.push_back(i);

    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";


//    for(int i = 0;i<5;i++)
//        std::cout<<list.pop_front();


//    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";

//    list.display();

//    list.remove_value(9);
//    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
//    list.display();
//    list.remove_value(6);
//    std::cout<<"\nsize of list >>> "<< list.size()<<"\n";
//    list.display();

    list.reverse();
    list.display();

}

int main(void)
{
    //  testVector();
    testLinkList();
    return 0;
}
