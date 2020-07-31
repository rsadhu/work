#include <iostream>

class Base {
public:
    Base(int p)
    {
        std::cout << " Base::Base\n";
    }
};

class Der : public Base {
public:
    Der(int x = 0)
        : Base(x)
    {
        std::cout << " Der:Der\n";
    }
};

int main(void)
{
    Der d(10);
    return 0;
}
