#include <iostream>

class Base
{

protected:
    int m_data = 10;

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

    void print()
    {
        std::cout << " main data is " << m_data << "\n";
    }
};

int main(void)
{
    Der d;
    return 0;
}
