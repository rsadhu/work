#include<iostream>
#include"cppfeatures.h"

using namespace utl;

CppFeatureSet create()
{
    CppFeatureSet obj;
    return obj;
}




void test(CppFeatureSet buglu)
{

}

template<typename DataType>
void passByvalue(DataType t)
{
 (void) t;
}

template<typename DataType>
DataType returnByValue()
{
 return DataType();
}


template<typename DataType>
void refvaluefunc(DataType &rhs)
{
    std::cout<< "lvaluefunc:: func "<<rhs<<"\n";
}



template<typename DataType>
void refvaluefunc(const DataType &rhs)
{
    std::cout<<"constRefValue:: func "<<rhs<<"\n";
}


template<typename DataType>
void refvaluefunc(DataType &&rhs)
{
    std::cout<< "rvaluefunc:: func "<<rhs<<"\n";
}


void testing(int &&rhs)
{
    std::cout<<" testing:: func   "<<rhs<<"\n";
}

constexpr int funConstExpr(int x )
{
    return x*x;
}

class Test{
public:
    Test()
    {
        std::cout<<"\nTest::Test"<<"\n";
    }

    Test(const Test &rhs)
    {
        std::cout<<"\nTest::Copy Constructor\n";
    }

    Test & operator = (const Test &rhs)
    {
        std::cout<<"\nTest::assignment oeprator\n";
        return *this;
    }

    Test & operator = (Test &&rhs)
    {
        std::cout<<"\nTest::assignment oeprator\n";
        return *this;
    }



    Test(Test &&rhs)
    {
        std::cout<<"\nTest::move\n";
    }
    ~Test()
    {
        std::cout<<"\nDestructor:: ~Test"<<"\n";
    }

    void foo()
    {
        std::cout<<" Test::foo\n";
    }
};



int main(void)
{
//    CppFeatureSet cs = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    cs.workOnArray();

//    float xf = 9.0f;

//    CppFeatureSet c(xf);

//    CppFeatureSet sss = create();

//    test(create());

//    int x = 100;

//    refvaluefunc(x);

//    refvaluefunc(100);

//    refvaluefunc(1000);
//    refvaluefunc(int(10));

//    refvaluefunc(std::string("==== Hello ====="));
//    testing(1000);
//    //testing (x);
//    constexpr int xc = 10;
//    std::cout<< funConstExpr(xc);

    Test t;
    Test u = t;
    Test v(t);
    Test nn;
    nn = std::move(t);

    auto lambda = []() -> Test{ return Test();};
    lambda().foo();

    auto dosomething = [](Test t)
    {
     (void) t;
      std::cout<<" called dosomething\n"; t.foo();
    };

    std::cout<<" call dosomething\n";
    dosomething(lambda());

    std::cout<<"\n===== DISCO=====\n";

    passByvalue(std::move(t));
    auto res = returnByValue<Test>();

    std::cout<<"\n===== DANCE=====\n";

    auto dec2bin = [] (const std::string  &dec ) {

        int res = 0;
        for (char ch : dec) {
            res = res << 1;
            if ( ch == '1')
                res+=1;
        }
        return res;
    };

    std::cout<<"\ndec 2 bin === >> "<< dec2bin("111111111")<<"\n";

    return 0;
}
