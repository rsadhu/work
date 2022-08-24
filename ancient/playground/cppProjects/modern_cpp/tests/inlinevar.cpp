#include <iostream>

class Test
{
    inline static int s_ref = 0;

public:
    Test()
    {
        ++s_ref;
    }

    void display() { std::cout << " Test::display\n"; }
    ~Test() { --s_ref; }
};

int main(void)
{
    Test t[10];
    for (auto it : t)
    {
        it.display();
    }
    return 0;
}
