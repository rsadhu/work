#include <iostream>
#include <map>

int main(int argc, char *argv[])
{
    // int arr[4] = { 1, 2, 3, 4 }; //{ 8, 5, 6, 7}

    // int n = 4;
    // for (int u = 0; u < n; u++) {
    //     arr[arr[u] % n] = arr[arr[u] % n] + n;
    // }

    // std::cout << "\n";

    // for (auto it : arr) {
    //     std::cout << it << "  ";
    // }

    // std::cout << "\n";

    // for (int u = 0; u < n; u++) {
    //     if (arr[u] > 2 * n)
    //         std::cout << u << " ";
    // }

    std::map<int, int> lu;

    for (int i = 0; i < 10; i++)
    {
        lu[i] = i * 2;
    }

    auto it = lu[3];
    auto it1 = lu[11];

    auto i = lu.find(1);
    auto j = lu.find(11);

    return 0;
}

//#57714840