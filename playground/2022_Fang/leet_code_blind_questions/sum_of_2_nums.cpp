#include <iostream>
#include <vector>

void found(std::vector<int> &numbers, int start, int end, int target, int &index)
{
    if (start >= 0)
    {
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (target > numbers[mid])
            {
                start = mid + 1;
            }
            else if (target < numbers[mid])
            {
                end = mid - 1;
            }
            else
            {
                index = mid;
                break;
            }
        }
    }
}

std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::vector<int> res;
    for (int i = 0; i < numbers.size(); i++)
    {
        auto second = target - numbers[i];
        int index = -1;
        if (second > numbers[i])
        {
            found(numbers, i + 1, numbers.size(), second, index);
        }
        else
        {
            found(numbers, i - 1, i, second, index);
        }

        if (index != -1)
        {
            res.push_back(i);
            res.push_back(index);
            return res;
        }
    }

    return res;
}

bool HasSumofTwo(std::vector<int> &rhs, int sum)
{
    int begin = 0, end = rhs.size() - 1;

    while (begin <= end)
    {

        if ((rhs[begin] + rhs[end]) < sum)
            begin++;

        else if ((rhs[begin] + rhs[end]) > sum)
            end--;
        else
            return true;
    }

    return false;
}

int main(void)
{
    int sum = 10;
    std::vector<int> rhs = {1, 2, 3, 4, 5, 6};
    std::cout << " \n do vec has " << sum << " " << HasSumofTwo(rhs, sum);

    auto res = twoSum(rhs, 10);
    return 0;
}