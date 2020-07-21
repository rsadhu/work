#include <iostream>

class Test
{
 public:
 explicit Test(int a) 
{ 
    std::cout<< " a:: "<<a;
}
};

int main(void)
{
    
 Test t(10);
 return 0;
}
