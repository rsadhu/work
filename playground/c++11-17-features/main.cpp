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


void refvaluefunc(int &rhs)
{
	std::cout<< "lvaluefunc:: func\n";
}




void refvaluefunc(const int &rhs)
{
 std::cout<<"constRefValue:: func\n";
}


void refvaluefunc(int &&rhs)
{
	std::cout<< "rvaluefunc:: func\n";
}


void testing(int &&rhs)
{
	std::cout<<" testing:: func   "<<rhs<<"\n";
}

constexpr int funConstExpr(int x )
{
   return x*x;
}


int main(void)
{
 CppFeatureSet cs = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
 cs.workOnArray();

 float xf = 9.0f;
 
 CppFeatureSet c(xf); 
 
 CppFeatureSet sss = create();
 
 test(create());

 int x = 100;

 refvaluefunc(x);

 refvaluefunc(100);
 
 refvaluefunc(1000);

 testing(1000);
 //testing (x);
 constexpr int xc = 10;
 std::cout<< funConstExpr(xc);
 return 0;
}
