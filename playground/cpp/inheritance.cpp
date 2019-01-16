#include<iostream>


class base
{
    public:
    void test(int a, int b)
    {

    }
};


class der: public base
{
    public :
    void test(int a, int b)
    {
    }
};




int main(void)
{
    base *b = new der;
    b->test(5,6);
    delete b;
    return 0;
}
