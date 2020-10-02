#include <iostream>

class Base
{
 public:
 template<typename T>
 void foo(T a )
{
    std::cout<<"Base::foo: "<<a<<"\n";
}
};


class Der:public Base
{
 public:
    using Base::foo;
    void foo(void)
    {
        std::cout<<"Der::foo::void\n";
    }
};


int main(void)
{
 Der d;
 d.foo();
 return 0;
}
