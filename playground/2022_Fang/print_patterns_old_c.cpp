#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "\nBase::Base\n";
        foo();
    }

    virtual ~Base() { std::cout << "\nBase::~Base\n"; }

    virtual void foo() { std::cout << "\nBase::foo\n"; }
};

class Der : public Base
{
public:
    Der() { std::cout << "\n Der:: Der\n"; }

    ~Der() { std::cout << "\n Der:: ~Der\n"; }

    void foo() { std::cout << "\n Der:: foo\n"; }
};

void test(void)
{
    Base *b = new Der;
    b->foo();
    delete b;
}

void printPatterns()
{

    int sum = 0;
    std::cout << "\n";
    for (int i = 1; i <= 5; i++)
    {
        std::cout << "\n";
        for (int j = 1; j <= 5 - i; j++)
        {
            sum += j;
            std::cout << sum << " ";
        }
    }
    std::cout << "\n";
}

int main(void)
{
    test();

    printPatterns();
};