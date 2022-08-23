#include <iostream>
#include <vector>

void heapify(std::vector<int> &arr, int N, int i)
{
    int j = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < N && arr[l] < arr[j])
        j = l;
    if (r < N && arr[r] < arr[j])
        j = r;

    if (j != i)
    {
        std::swap(arr[j], arr[i]);
        heapify(arr, N, j);
    }
}

void heapSort(std::vector<int> &vec)
{
    int N = vec.size();
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
    {
        heapify(vec, N, i);
    }

    for (int i = vec.size(); i >= 0; i--)
    {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

// auto sq(auto val)
// {
//     return val * val;
// }

int main(void)
{
    std::vector<int> arr = {-9, 10, 8, 2, 5, 3, 4, 7, 6};

    heapSort(arr);

    //  std::cout << sq(3) << "\n";
    // std::cout << sq(3.3) << "\n";
    return 0;
}