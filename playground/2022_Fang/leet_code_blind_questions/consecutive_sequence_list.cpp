#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int i = 0, j = 1, len = 1, max = 0;
        while (j < nums.size())
        {
            if ((nums[j] - nums[i]) == 1)
            {
                len++;
            }
            else
            {
                max = std::max(len, max);
                len = 1;
            }
            i++;
            j++;
        }
        return max;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int res = s.longestConsecutive(nums);
    return 0;
}