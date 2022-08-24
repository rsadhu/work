#include <iostream>

void foo(int n) noexcept
{
  while (n-- > -1)
  {
    std::cout << " ============= " << 100 / n;
  }
}

int main(void)
{
  foo(10);
  return 0;
}
