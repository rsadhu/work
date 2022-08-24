#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> arr1{1, 3, 5, 7, 9}, arr2{0, 2, 4, 6, 8}, fin;

  int k = 0, l = 0;

  for (int64_t i = 0; i < arr1.size() + arr2.size(); i++)
  {
    if (i % 2 != 0)
    {
      fin.push_back(arr1[l++]);
    }
    else
    {
      fin.push_back(arr2[k++]);
    }
  }

  for (auto it : fin)
  {
    std::cout << " value is :: " << it << "\n";
  }

  return 0;
}
