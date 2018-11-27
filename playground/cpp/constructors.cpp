
#include<iostream>
#include<string>
#include<vector>

class Test
{
    public:
    int a,b,c;
};

class Abc;
class Abc
{
    public:
    void display();
#ifdef CONSTRUCTOR
    Abc(){}
    Abc(int x) :Abc() { mAge = x; }
    Abc( std::string name ) { Abc(); mName= name; }
    Abc( std::vector<int> &rhs)
    {
        for(auto i: rhs)
        {
            mVec.push_back(i);
        }
        Abc();
    }

    Abc(Test & obj)
    {
        display();
        Abc();
        mTest.a = obj.a;
        mTest.b = obj.b;
        mTest.c = obj.c;
    }
#elif STATICFUN
    static  Abc init() {
        return { 36,"Rakesh Sadhu", {1, 2, 3, 4, 5}, (1, 2, 3), (1, 2, 3, 4) };
    }
#else
    Abc(const std::initializer_list<int> &rhs)
    {
        for(auto it:rhs)
        {
            mVec.push_back(it);
        }
    }
#endif
    int mAge;
    std::string mName;
    int mPlainArr[10];
    Test mTest;
    std::vector<int> mVec;
};


void Abc::display()
{

#ifdef STATICFUN
    std::cout<<"display :: Abc :   >>  "<< mAge<<"\n";
#endif
    for(auto it:mVec)
    {
        std::cout<< it<<" ";
    }
    std::cout<<"\n";
}


class _test
{
    public:
    _test()=default;
    template<typename T>
    _test(typename T){}
    void display(){ std::cout<<" _test::_test\n";}

};

int main(void)
{

#ifdef CONSTRUCTOR
 Abc c(1);
 c.display();Test t={1,2,3};
 Abc d(t);
 d.display();
 std::vector<int> v ={1,2,3,4,5};
 Abc e(v);
 e.display();
#elif STATICFUN
 Abc obj = Abc::init();
 obj.display();
#else
 Abc obj ={1,2,3,4,5,6,7,8,9};
 obj.display();
#endif

 _test _t;
 _t.display();


 return 0;
}
