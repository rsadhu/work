#include<iostream>
#include<memory>

struct[[deprecated ("deprecated")]] S;

class Base
{
    public:
    Base(){std::cout<<"Base::Base\n";}
    ~Base(){ std::cout<<"Base::~Base\n";}
    int add(int a, int b, int c) { return a+b+c;}
};

class [[deprecated("Wakka wakka this isn't supposed to be used")]] Test 
{
    public:
    void display()
    {
        std::cout<<"sum(1,3,5)"<< mPtr.add(1, 3, 5);
    }
    private:
    std::unique_ptr<Base> mPtr;
};


[[deprecated()]]
int  add(int b, int a)
{
 return a+b;
}

struct sttt
{
    int data;
};

[[deprecated]] typedef sttt s;

int
main (void)
{
   std::cout<<add(1,1);  
   Test t;   
   t.display();
   s a;
   return 0;
}
