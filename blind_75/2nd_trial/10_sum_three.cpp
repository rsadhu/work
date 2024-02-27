#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::map<int, int> lu;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto c_tar = nums[i];
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    auto target = -1 * c_tar;
                    if (lu.find(nums[j] - target) == lu.end())
                    {
                        lu[nums[j] - target] = j;
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> threeSum_naive(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::set<std::vector<int>> lu;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                for (int k = 0; k < nums.size(); k++)
                {
                    if (i != j && j != k && i != k)
                    {
                        if (nums[i] + nums[j] + nums[k] == 0)
                        {
                            std::vector<int> r;
                            r.push_back(nums[i]);
                            r.push_back(nums[j]);
                            r.push_back(nums[k]);
                            std::sort(r.begin(), r.end());

                            if (lu.find(r) == lu.end())
                            {
                                res.push_back(r);
                                lu.insert(r);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> l = {1, 0, 1, 2, -1, -4};
    auto ret = s.threeSum_naive(l);
    for (auto each : ret)
    {
        for (auto ele : each)
        {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }
    return 0;
}