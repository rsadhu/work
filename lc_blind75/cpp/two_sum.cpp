#include "common.h"

std::vector<int> two_sum(std::vector<int> &r, int target)
{
    std::unordered_map<int, int> lu;
    auto index = 0;
    for (auto el : r)
    {
        lu[el] = index++;
    }

    index = 0;
    for (auto el : r)
    {
        if (lu.find(target - el) != lu.end())
        {
            return {index, lu[target - el]};
        }
        index++;
    }
    return {-1, -1};
}

int main(void)
{
    std::vector<int> inp = {2, 7, 11, 15};

    auto r = two_sum(inp, 5);
    std::cout << r;
    return 0;
}