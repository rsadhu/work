#include <iostream>

class T
{
  int mX;

public:
  T(int x = 0)
  {
    std::cout << "T:x\n";
    mX = x;
  }

  void display(int x) const
  {
    std::cout << "T::display: const::  " << mX << std::endl;
  }

  void display(int x)
  {
    std::cout << "T::display: " << mX << std::endl;
    mX = x;
  }
};

int main(void)
{
  T x;
  const T y;
  x.display(10);
  y.display(20);
  return 0;
}
