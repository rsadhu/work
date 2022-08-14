#include <any>
#include <iostream>

// struct B;

struct A {
    int x = 10;
};

struct B : public A {
    int y = 20;
};

void test(struct A a)
{
    std::cout << "\n"
              << a.x << "\n";
}

int main(void)
{
    A a;
    B b;
    std::cout << b.x << " " << b.y << "\n";
    a = b;
    std::cout << a.x << " " << b.y << "\n";

    test(b);
    return 0;
}