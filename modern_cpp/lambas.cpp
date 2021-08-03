#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::cout << "\nLamba function calling\n";
    std::vector<int> arr = { 12, 0, 100, -9, 40, 30, 80, 111 };
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a < b ? true : false;
    });

    for (auto it : arr) {
        std::cout << it << " ";
    }
    return 0;
}