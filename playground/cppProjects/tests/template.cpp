#include<iostream>
#include<thread>
#include<mutex>



template < typename T > void
dosomething (T a)
{
  std::cout << " doSomething :: " << a << "\n";
}

template < typename T > 
class Utility
{
public:
  void runSomething (T a);

  template < typename U > 
  void runInsideTemplate (U a);
private:
  T mData;
};


template <typename T> 
void Utility <T> :: runSomething (T a)
{

}

template <typename U> 
void Utility <U> :: runInsideTemplate (U a)
{

}


int
main (void)
{
  dosomething < int >(9);
  dosomething (9.9);
  dosomething (9.0f);
  dosomething ("string");
  dosomething ('c');
  return 0;
}
