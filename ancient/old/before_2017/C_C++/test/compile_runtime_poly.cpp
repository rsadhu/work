#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "\nA::A\n"; }
    virtual ~A() { cout << "\nA::~A\n"; }
    void test(void) { cout << "\n A:: test\n"; }
    virtual void display(void) { cout << " A:: display\n"; }
    virtual void display(int a) { cout << " A:: display::int\n"; }
    virtual void display(int a, int b = 9) { cout << " A:: display::int int=9\n"; }
};

class B : public A
{
public:
    B() { cout << "\nB::B\n"; }
    virtual ~B() { cout << "\nB::~B\n"; }
    void test(void) { cout << "\n B:: test\n"; }
    virtual void display(void) { cout << " B:: display\n"; }
    virtual void display(int a) { cout << " B:: display::int\n"; }
    virtual void display(int a, int b = 9) { cout << " B:: display::int int=9\n"; }
};

int main(void)
{
    A *a = new B;
    a->test();
    a->display();
    //    a->display(10);
    a->display(20, 10);
    delete a;
    return 0;
}
