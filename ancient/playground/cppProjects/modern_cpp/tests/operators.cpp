#include <iostream>
#include <map>

/*
 5 = 0101
 4 = 0100
 9 = 1001
*/

int countSetBits(int m)
{
  int count = 0;
  while (m)
  {
    if (m & 1)
      count++;
    m = m >> 1;
  }
  return count;
}

int main(void)
{
  int n, m;

  std::cout << "enter the values for m and n : \n";

  std::cin >> m;

  int max1 = 0, max2 = 0, maxn1 = 0, maxn2 = -1;
  std::map<int, int> lookup;

  while (m-- > 0)
  {
    int nob = countSetBits(m);
    lookup[m] = nob;
    if (nob > max2)
    {
      if (nob > maxn1)
      {
        max2 = max1;
        maxn2 = maxn1;

        maxn1 = nob;
        max1 = m;
      }
      else if (nob > maxn2)
      {
        maxn2 = nob;
        max2 = m;
      }
    }

    std::cout << " number of bits for  " << m << " = " << nob << "\n";
  }

  std::cout << " first  two biggest numbers are : "
            << "\n1st one\n"
            << max1 << "  " << maxn1 << "\n2nd one \n " << max2 << " " << maxn2 << "\n";

  for (auto it : lookup)
  {
    std::cout << " num " << it.first << " => num of bits" << it.second << "\n";
  }

  return 0;
}
