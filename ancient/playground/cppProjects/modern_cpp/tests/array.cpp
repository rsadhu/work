#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  for (auto it : arr)
  {
    std::cout << it << " ";
  }
  std::cout << "\n";
  for (int i = 0; i < arr.size(); i++)
  {
    if (i <= 3)
    {
      auto tmp = arr[i];
      arr[i] = arr[i + 1];
      arr[arr.size() - 1 - i] = tmp;
    }
  }

  for (auto it : arr)
  {
    std::cout << it << " ";
  }
  std::cout << "\n";
  return 0;
}
