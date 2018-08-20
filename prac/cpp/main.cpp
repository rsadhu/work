#include<iostream>
#include<memory>

template<typename T>
void foo(T a)
{
    std::cout<< a<<"\n";
}

template<typename T, typename U=float>
void fOver(T a, U  b)
{
    std::cout<< a<<"  " <<b <<"\n";
}


template<typename T>
class Base
{
    public:
        virtual void display(T )=0;

};


class IDer: public Base<int>
{
    public:
    void display(int arg) {
        std::cout<< " Der: int"<<arg<<"\n";
    }
};


class SDer: public Base<std::string>
{
    public:
    void display(std::string  arg) {
        std::cout<<" SDer::string "<<arg<<"\n";
    }
};



int main(int argc, char *argv[])
{
    std::cout<<argv[0];
    foo('a');
    foo(9);
    foo(std::string("test"));
    foo<float>(9.5f);
    foo<double>(9.9);
    foo(0.123);


    fOver(1,0.4);
    fOver(9.9,"String");

    std::unique_ptr<Base<int>> uBptr = std::make_unique<IDer>();
    uBptr->display(9);

/*    std::unique_ptr<Base<std::string>> uBptr_s = std::make_unique<SDer>();
    uBptr_s->display("TEstttt ...");*/


    Base<int> *p = new IDer();
    p->display(9);

    Base<std::string > *s  = new SDer();
    std::string str="Hello";
    s->display(str);

    return 0;
}
