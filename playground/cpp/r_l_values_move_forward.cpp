#include<iostream>

class Test
{
 public:
 Test()=default;
 Test(const Test &rhs)
 {

     std::cout<<" Test::copy\n";
 }

 Test(const Test &&rhs)
 {
     std::cout<<" Test::move\n";
 }
};



void foo(int & rhs)
{
 std::cout<<" foo:: lvalue ref\n";
}



void foo(int &&rhs)
{
 std::cout<<" foo:: rvalue ref\n";
}


void foo(const int &rhs)
{
 std::cout<<" const foo:: lvalue ref\n";
}

Test retTest()
{
    Test t;
    return t;
}

void play(Test  &&t)
{
 std::cout<<" Play :: move\n";
}

/*
void play(Test  &t)
{
 std::cout<<" Play :: ref\n";
}*/

/*void play(Test  t)
{
 std::cout<<" Play :: copy\n";
}*/

void testPF( Test )
{

}

template<typename T>
void funcArg(T &&arg)
{
    testPF(std::forward(arg));
}


int main(void)
{
    int x=10;
    foo(x);
    foo(10);
    foo(std::move(x));

    //Test t;
    //play(t);
    play(std::move(retTest()));

    funcArg<Test>(Test());

    return 0;
}
