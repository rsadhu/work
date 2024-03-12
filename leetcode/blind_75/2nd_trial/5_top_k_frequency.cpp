#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        std::map<int, int> lu;
        for (auto it : nums)
        {
            lu[it]++;
        }

        std::vector<std::vector<int>> checkup(nums.size() + 1);
        for (auto &[key, value] : lu)
        {
            auto &ref = checkup[value];
            ref.push_back(key);
        }

        std::vector<int> res;
        for (int i = checkup.size() - 1; k != 0 && i >= 0; i--)
        {
            if (checkup[i].size() != 0)
            {
                for (auto it : checkup[i])
                {
                    if (k != 0)
                    {
                        k--;
                        res.push_back(it);
                    }
                }
            }
        }

        return res;
    }
};
int main()
{
    Solution s;

    std::vector<int> l = {1, 1, 1, 2, 2, 3};
    int tar = 2;
    auto r = s.topKFrequent(l, tar);

    for (auto it : r)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";

    std::vector<int> l1{1};
    tar = 1;
    r = s.topKFrequent(l1, tar);
    for (auto it : r)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";

    std::vector<int> l2{1, 2};
    tar = 2;
    r = s.topKFrequent(l2, tar);
    for (auto it : r)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
    return 0;
}