#include<iostream>
#include<string>


class Test 
{
 public: 
 Test() 
 {
 	std::cout<<" default Constructor\n"; 
 }
 
 Test(const Test &rhs) 
 {
 	std::cout<<" copy constructor\n";
 }
 
 Test(Test && rhs) 
 {
 	std::cout<<" move constructor\n";;
 }
 
};

template<typename T>
Test wrapper(T &&arg)
{
 return Test(std::forward<T>(arg));
}

int main(void)
{

 auto t =  wrapper(Test{});
 Test tt;
 auto u =  wrapper(tt);
 auto v =  wrapper(std::move(tt));

 using mystrings = std::string;
 mystrings k("Potassium");
 std::cout<<" ========= > "<<k<<" len "<<k.length();

 int xyz = 0;
 decltype ( xyz )  b = 19;
 std::cout<<"\n b ---> "<<b<<"\n";

 decltype (t) aaaa;
 return 0;
}
