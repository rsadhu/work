#include <iostream>
#include <string>
#include <vector>



struct comp
{
  char z;
  int x;
  char y;
//  std::string str;
};

using Data = struct comp;


Data
setData (Data  &d)
{
  Data t;
  t = d;
//memset (d,t, sizeof(d));
  return t;
}



class Base
{
    public:
        Base()
        {
            std::cout<<"\nBase::Base\n";
        }

        Base(const Base &rhs)
        {
            std::cout<<"\nBase::copy\n";
        }

        Base (Base &&rhs)
        {
            std::cout<<"\n Base::move\n";;
        }
    virtual void foo(int a)
    {
         std::cout<<"Base : "<<a<<"\n";
    }

    virtual ~Base()
    {
        std::cout<<"\n~Base\n";
    }

};

class Der : public Base
{
    public:

        void foo(int a)
        {
            std::cout<<"Der"<<a<<"\n";
        }

        ~Der()
        {
            std::cout<<"\n ~Der\n";
        }
};


Base copy()
{
    return Base();
}



int
main (void)
{

  Data tt;
  tt.x =1;
  tt.y='b';
  tt.z= 'a';
  auto xx = setData (tt);
  std::cout << xx.x << "\n";
  std::cout << xx.y << "\n";
  std::cout << xx.z << "\n";

  std::cout<<"char-> "<<sizeof(char)<<"\n";
  std::cout<<"int-> "<<sizeof(int)<<"\n";
  std::cout<<"double-> "<<sizeof(double)<<"\n";
  std::cout<<"float-> "<<sizeof(float)<<"\n";
  std::cout<<"string-> "<<sizeof(std::string)<<"\n";

  std::cout<<"\nsize is"<<sizeof(tt);


  Base b = copy();

  return 0;
}
