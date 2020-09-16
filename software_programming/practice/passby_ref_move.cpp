#include <vector>
#include<iostream>

class Test
{
    public:
    Test() 
    {
        std::cout<<" Test::Test\n";
    }
    Test (Test &&rhs)
    {
        std::cout<<" Test::move impl\n";
    }
    
    Test (const Test &rhs)
{
    std::cout<<" Test::copy imp\n";
}
};


class Utility
{
 public:
    Utility(std::vector<Test> &&r):m_tests(std::move(r)){}
    std::vector<Test> m_tests;
};

void foo(std::vector<Test > rhs)
{
//std::vector<Test> m =  std::move(rhs);  
}


std::vector<Test>  create()
{
  std::vector<Test> t;
  return std::move(t);
}



int main(void)
{
    std::vector<Test> t(10);
    foo(t);
    Utility uu(create());
    return 0;
}
