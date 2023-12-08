#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::vector<std::vector<int>> res;
        int i = 0, j = 1, len = intervals.size();
        while (j < len)
        {
            auto &prev = intervals[i];
            auto cur = intervals[j];
            if (prev[1] >= cur[0])
            {
                prev[1] = cur[1];
                j++;
                continue;
            }
            res.push_back(prev);
            i = j;
            j++;
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    std::vector<std::vector<int>> input = {{1, 3},
                                           {2, 6},
                                           {8, 10},
                                           {15, 18}};

    auto res = s.merge(input);
    return 0;
}