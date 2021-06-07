#include <iostream>
#include <initializer_list>

// c++11 features.
// uniform initialization


 class Animal
 {
     public:
     int m_age{0};

    //  Animal(int age):m_age(age) 
    //  {
    //      std::cout<<"Regular constructor with para\n";
    //  }

    //  Animal(std::initializer_list<int> rhs) noexcept
    //  {
    //      std::cout<<" Initializer_List called\n";
    //      for(auto it: rhs){
    //         m_age =  it;
    //         break;
    //      }
    //  }

 };


void print(int &lvr)
{
    std::cout<<" print:: lvalue ref"<<lvr<<"\n";
}

void print (int &&rvr)
{
    std::cout<<" print:: rvalue ref"<<rvr<<"\n";
}


 int main(void)
 {
     Animal A{34};

     print(10);
     return 0;
 }

