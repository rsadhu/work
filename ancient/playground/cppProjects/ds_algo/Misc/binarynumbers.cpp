#include <iostream>
#include <array>

void dec2bin(int num)
{
   if (num)
   {
      num /= 2;
      dec2bin(num);
   }
   std::cout << num % 2;
}

int main(void)
{
   int n = 10;
   std::array<int, 100> arr;

   for (int i = 1; i < 50; i++)
   {
      std::cout << i << ".";
      dec2bin(i);
      std::cout << "\n";

      while (i)
      {
         arr.push_back(i % 2);
         i = i / 2;
      }
   }

   for (int i = arr.size() - 1; i >= 0; i--)
      std::cout << arr[i];

   return 0;
}
