#include<iostream>
#include<iomanip>
#include<string>

template < typename T = int >T
funcArth (T a, T b)
{
  return a + b;
}



template < typename T = int >
class Test
{
public:
  explicit Test ():mMem ()
  {
  }
  explicit Test (T arg):mMem (arg)
  {
  }

  void display ();

  template < typename U > 
  void printThis (U);

private:
  T mMem;
};


template < typename T > 
void Test < T >::display ()
{
  //std::cout<<" \n Test::display" <<std::fixed << std::setprecision(3)<< mMem<< "\n";
  std::cout << " \n Test::display" << mMem << "\n";
}


template < typename T >
template < typename U > 
void Test < T >::printThis (U arg)
{
  std::cout << "\nTest::printThis " << arg << "\n";
}


int
main (void)
{
  std::cout << "   " << funcArth (4, 4) << "\n";
  std::cout << "   " << funcArth (0.4, 4.1) << "\n";
  std::cout << "   " << funcArth (std::string ("abc"),
				  std::string ("def")) << "\n";

  Test < float >aa=9.9f;
  aa.display ();
  aa.printThis ("hello this is me");
  return 0;
}
