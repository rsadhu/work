#include<iostream>
using namespace std;

class B;
class A
{
    public:
    A (B * p):ptr (p)
    {
        cout << " A::B::ptr.. " << ptr;
    }
    void check ()
    {
    // cout << ptr->x;
    ptr->display ();
    }
    private:
    B * ptr;
};


class B:public A
{
    public:
    B ():A (this)
    {
        cout << " B::B :: " << this << endl;
        x = 100;
    }
    void display ()
    {
        cout << "B::display\n";
    }
    private:
//  friend class A;
    int x;
};


int
main (void)
{
    A *a = new B;
    a->check ();
    return 0;
}
