#include<iostream>


class base
{
    public:
    void test(int a, int b)
    {

    }

    virtual void foo() = 0;
};


class der: public base
{
    public :
    void test(int a, int b)
    {
    }
    
	void foo() 
	{
		
	}	
	
};


void upcasting( base & p)
{
}



int main(void)
{
    base *b = new der;
    b->test(5,6);
    delete b;
    der d;
    upcasting(d);
    return 0;
}


	
