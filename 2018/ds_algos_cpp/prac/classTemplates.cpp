#include<iostream>

template<typename T>
class Base
{

};

template<typename U>
class Der: public Base<int>
{
    public:
    template<typename X>
    X dosomething(X arg)
    {
        return arg*arg;
    }
    template<typename X>
    X add(X,X);

    private:
    U m_data;
};

template<typename U>
template<typename X>
X Der<U>::add(X arg1,X arg2)
{
 return arg1+arg2;
}

int main(void)
{
     Base<int>  *bptr= new Der<float> ();
     Der<int> d;
     Der<int> a;
     std::cout<<d.dosomething<float>(10.0f);
     std::cout<< a.add<float>(10.9,10.1);
     double x=1.0;
     float y=1.0;
     std::cout<<(x/2506.0);
     //std::cout<<"\n"<<(y</65536.0);
     return 0;
}
