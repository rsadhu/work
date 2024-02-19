#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        std::unordered_map<int, int> lu;
        for (auto i = 0; i < nums.size(); i++)
        {
            auto n = nums[i];
            lu[target - n] = i;
        }

        for (auto i = 0; i < nums.size(); i++)
        {
            auto n = nums[i];
            if (lu.find(n) != lu.end())
            {
                if (lu[n] != i)
                    return {lu[n], i};
            }
        }

        return {-1, -1};
    }
};

int main(void)
{
    std::vector<std::vector<int>> inputs = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3},
        {-1, -2, -3, -4, -5}};

    std::vector<int> targets = {9, 6, 6, -8};

    Solution s;

    for (int i = 0; i < targets.size() && inputs.size(); i++)
    {
        auto res = s.twoSum(inputs[i], targets[i]);

        for (auto ind : res)
        {
            std::cout << ind << " ";
        }
        std::cout << "\n";
    }

    return 0;
}