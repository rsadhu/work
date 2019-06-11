 #include "MyVector.h"
#include "linklist.h"
#include<iostream>


int main(void)
{
    MyVector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8};
    //TODO: Implement Iterator
//    for(auto it:vec)
//    {
//        std::cout<<" value is "<< it<<std::endl;
//    }

     for(int i = 9; i < 21; i++)
     {
         vec.push(i);
     }

     std::cout<<"\n";
     for(int i = 0; i < vec.size(); i++)
     {
         std::cout<< "  "  <<vec.at(i);
     }

     std::cout<<"\n";
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
    return 0;
}
