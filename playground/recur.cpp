#include <iostream>


int
check (int x)
{
#ifdef R
  if (x == 0)
    return 0;
  std::cout << x << " ";
  return check (--x);
  std::cout << "\n" << x << " ";
#elif Q

  if (x != 0)
    {
      std::cout << x-- << " ";
      return x + check (x);
      std::cout << "\n should get called\n";
    }
  std::cout << "\n how many times called\n";
  return x;
#endif

  if (x <= 2)
    return 1;
  return check (x - 2) + check (x - 1);

}

double powFun(double x, int n)
{
  
    if (n == 0)
      return 1;

    return x * powFun (x, --n);
}

double
myPow (double x, int n)
{
    auto res =  powFun(x, n);
    
    
    if (n < 0) 
        return 1.0 / res; 
    return res;
}


int
main (void)
{
  auto t = check (3);
  std::cout << "\nreturn :   " << t << "\n";

  std::cout << myPow (2, 10) << " ";


  std::cout << "\n" << myPow (2, -10) << " ";
  return 0;
}
