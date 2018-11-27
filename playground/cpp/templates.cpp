#include<iostream>
#include<string>
#include<stdio.h>
namespace 
{
    template<typename T,typename U=int>
    U test1(T a,U b)
    {
        return a+b;
    }


    template<class T,class U>
    int  test2(T &a, U &b)
    {
         return a+b.length();
    }

    template<typename T>
    T adder(T v)
    {
         return v;
    }

    template<typename T,typename... Args>
    T adder(T first, Args...vargs)
    {
         return first + adder(vargs...);
    }

    template<>
    void specFunc()
    {
        std::cout<<"\n specFunc\n";
    }

}

int main(void)
{

    std::cout<<"1. "<<::test1<int> (9,1)<<std::endl;
    std::cout<<"2. "<<::test1(9,11)<<std::endl;
    std::string s("discodance");
    int da=10,db=100;
    std::cout<<"3. "<<::test2<int,std::string>(da,s)<<std::endl;
    std::cout<<"4. "<<::test2(db,s)<<std::endl;
    std::cout<<"5. variaditic templats .."<< adder(1,2,3,4,5,6,7,8,9,10);
    specFunc();
    return 0;
}
