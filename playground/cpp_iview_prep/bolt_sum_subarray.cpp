#include <iostream>
#include <vector>

std::pair<int, int> subSum(std::vector<int> &arr, int target)
{
    std::pair<int, int> res{-1, -1};
    int sum = arr[0];

    for (size_t i = 0, j = 1; i < j;)
    {
        if (sum == target)
        {
            return {i, j - 1};
        }
        else if (sum < target)
        {
            if (j < arr.size())
            {
                sum += arr[j];
                j++;
            }
            else
            {
                return res;
            }
        }
        else
        {
            sum -= arr[i];
            i++;
        }
    }
    return res;
}

int main(void)
{
    std::vector<std::pair<std::vector<int>, int>> inputs =
        {
            {{1, 2, 3}, 5},
            {{1, 3, 5, 7, 2, 4, 9}, 13},
            {{2, 4, 6, 1, 5}, 12},
            {{1, 2, 3, 4}, 0},
            {{1, 1, 1, 1}, 2},

        };

    for (auto it : inputs)
    {
        auto res = subSum(it.first, it.second);
        std::cout << res.first << " " << res.second << "\n";
    }
    return 0;
}