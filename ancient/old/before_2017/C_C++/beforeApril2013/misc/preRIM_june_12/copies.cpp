#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base()" << endl; }
    Base(const Base &) { cout << "Base(const Base&)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

Base func(Base b) { return b; }

void test1()
{
    Base a;
    func(a);
}

void test2()
{
    Base a;
    Base b = func(a);
}

int main()
{
    test1();
    test2();
    return 0;
}
