#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "\nBase::Base\n";
        impl();
    }
    virtual ~Base() { std::cout << "\nBase :: ~Base\n"; }

    virtual void impl() { std::cout << "\nvirtual Base::impl\n"; }

    virtual void foo() = 0;
};

class Der : public Base
{
public:
    Der()
    {
        std::cout << "\nDer::Der\n";
        impl();
        Base::impl();
    }
    void foo()
    {
        std::cout << "\nDer::foo\n";
        impl();
    }

    void impl() { std::cout << "\nvirtual Der::impl\n"; }

    int &retRef() { return x; }

    void display()
    {
        std::cout << " \n value of x is " << this->x << " \n";
    }

    int x = 10;
};

class Test
{
public:
    void foo(int p)
    {
        std::cout << "\n Test::foo  " << p << "\n";
    }

    void foo(int p) const
    {
        std::cout << "\n Test::foo::const   " << p << "\n";
    }

    // void foo(const int p)
    // {
    //     std::cout << "\n Test::const ::foo  " << p << "\n";
    // }
};

int main(void)
{
    //    Der d;

    Base *b = new Der;

    b->foo();
    // b->impl();

    Der d;
    d.display();
    d.retRef() = 100;
    d.display();

    delete b;

    Test ttt;
    const Test uuuu;
    ttt.foo(10);

    uuuu.foo(10);
    return 0;
}