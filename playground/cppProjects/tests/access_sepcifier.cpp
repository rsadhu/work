#include <iostream>



class Test
{
  public:
  Test()
{
 std::cout<<" Test::Test\n";
}


void set(int a)
{
 std::cout<<" a : "<<a;
 m_a = a;
}


int m_a;


};


void foo(int i)
{
 static Test a;
 a.set(i);
 
}

int main(void)
{


for (int i =0 ;i < 10;i++)
 foo(i);
   

    return 0; 
}
