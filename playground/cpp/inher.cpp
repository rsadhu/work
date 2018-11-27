#include<iostream>


class IBase
{
    public:
    IBase(){ std::cout<<"IBase::IBase\n";}
    virtual void setData(const int & )=0;
    virtual ~IBase(){std::cout<<"IBase::~IBase\n";}
};

class Der:public IBase
{
 public:
 void setData(const  int &){ std::cout<<" Der::setData\n";}
 ~Der()
 {
      std::cout<<"Der::~Der\n";
 }
};



class Child:public Der
{
    public:
    Child(){ std::cout<<" \n Child::Child\n";}
    void setData(const int &) override
    {
        std::cout<<" Disco Oldu\n";
    }
    ~Child()
    {
        std::cout<<"CHild::~Child\n";
    }
};

int main(void)
{
    IBase *b =  new Child();
    b->setData(9);
    delete b;
    b = new Der();
    b->setData(19);
    delete b;
    return 0;
}
