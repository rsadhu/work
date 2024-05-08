#include "common.h"

vector<int> twoSum(vector<int> &numbers, int target)
{
    int st = 0, end = numbers.size() - 1;

    while (st < end)
    {
        int sum = numbers[st] + numbers[end];
        if (sum == target)
        {
            return {st + 1, end + 1};
        }
        else if (sum < target)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return {-1, -1};
}

int main(void)
{
    std::vector<int> l = {2, 7, 11, 15};
    int target = 9;

    auto rs = twoSum(l, target);
    std::cout << rs;
    return 0;
}