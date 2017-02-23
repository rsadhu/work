#include<iostream>

template<typename T>
T adder(T x,T y)
{
 return x+y;
}



int main(void)
{
 std::cout<<  adder(9,1)<<" \n";
 return 0;
}
