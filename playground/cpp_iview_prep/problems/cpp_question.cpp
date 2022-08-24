#include <iostream>

class Computer
{

public:
    Computer()
    {
        std::cout << "\nComputer :: computer\n";
    }
    void test()
    {
        std::cout << " \nComputer::test\n";
    }

    int number = 100;
};

class Test : public virtual Computer
{

    int *m_p = nullptr;

public:
    void display() const
    {
        std::cout << "\nTest::display::const\n";
    }

    void display()
    {
        std::cout << "\nTest::display\n";
    }

    Test() : m_p(new int[10])
    {
        std::cout << "\nTest::Test\n";
    }

    ~Test()
    {
        std::cout << "Test::~Test\n";
    }

    Test(int p)
    {

        std::cout << "Test::int\n";
    }

    Test(double d)
    {

        std::cout << "Test::double\n";
    }

    Test(const Test &arg)
    {
        std::cout << "\nTest::copy called\n";
    }

    Test(Test &&rhs)
    {
        std::cout << "\nTest::move called\n";
        m_p = rhs.m_p;
        rhs.m_p = nullptr;
    }

    void foo2(void)
    {
        std::cout << "\nTest::foo\n";
    }
};

class Real : public virtual Computer
{
public:
    void foo(void)
    {
        std::cout << "\nReal::foo\n";
        this->number = 1000;
        this->test();
    }
};

class AiRobo : public Test, public Real
{
public:
};

class Der : public Test
{
    using Test::Test;

public:
};

Test foo()
{
    Test k;
    return k;
}

void test(const int *p)
{
    //*p = 10;
    p = new int[1];
}

void test1(int *const p)
{
    *p = 100;
    //  p = new int [];
}

int main(void)
{
    const Test t;
    // t.display();

    // const_cast<Test &>(t).display();
    // Test u;
    // u.display();

    Test u = foo();

    Der d(10);

    Der e(10.2);

    AiRobo ar;
    ar.foo();
    return 0;
}