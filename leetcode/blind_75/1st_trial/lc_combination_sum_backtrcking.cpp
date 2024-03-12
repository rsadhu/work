#include <vector>
#include <map>

using namespace std;

class Solution
{
    std::map<int, std::vector<int>> lu;

public:
    std::vector<int> canSum(std::vector<int> &candidates, int target)
    {
        if (lu.find(target) != lu.end())
        {
            return lu[target];
        }
        if (target == 0)
        {
            return {};
        }
        if (target < 0)
        {
            return {-1};
        }
        for (auto num : candidates)
        {
            target -= num;
            auto res = canSum(candidates, target);
            if (res.size() == 1 && res[0] == -1)
            {
                continue;
            }
            else
            {
                std::vector<int> r;
                r.insert(r.end(), res.begin(), res.end());
                lu[num] = r;
                return lu[num];
            }
        }
        lu[target] = {};
        return {};
    }

    vector<vector<int>>
    combinationSum(vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> f;
        std::vector<int> res = canSum(candidates, target);
        f.push_back(res);
        return f;
    }
};

// not completed
int main(void)
{
    Solution S;
    std::vector<int> l = {2, 3, 6, 7};
    S.combinationSum(l, 7);
    return 0;
}