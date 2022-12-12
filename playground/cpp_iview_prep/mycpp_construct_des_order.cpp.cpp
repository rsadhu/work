#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base\n";
    }

    ~Base()
    {
        std::cout << "~Base\n";
    }
};

class Der : public Base
{
public:
    Der()
    {
        std::cout << "Der\n";
    }

    ~Der()
    {
        std::cout << "~Der\n";
    }
};

int main(void)
{
    Der d;
    return 0;
}
