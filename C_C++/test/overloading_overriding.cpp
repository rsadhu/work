#include<iostream>
using namespace std;

class test
{
    public:
        test(){ cout<<" test:: test";}
        virtual  void display(void){ cout<<" test::display\n";}
        virtual  void display(int a){ cout<<" test::display::int\n";}
        ~test(){ cout<<"\n test::~test\n";}
};

class der: public test
{
    public:
        der(){ cout<<"\n der:: der\n";}
        void display(void){ cout<<"\n der::display\n";}
        void display(int a){ cout<<"\n der::display::int \n";}
        ~der(){ cout<<"\n der::~der\n";}
};



int main(void)
{
    test *t;
    der d;
    t =  &d;
    t->display();
    t->display(9);
 return 0;
}
