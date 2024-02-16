#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int sz = nums.size();

        for (int i = 0; i < nums.size();)
        {
            auto index = nums[i];
            i = index + i;
            if (i + index > sz)
            {
                return false;
            }
            else if (i + index < sz)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        return true;
    }
};
// not working
int main(void)
{
    Solution S;
    std::vector<int> i1 = {2, 3, 1, 1, 4};
    std::vector<int> i2 = {3, 2, 1, 0, 4};
    std::cout << S.canJump(i1) << "\n";
    std::cout << S.canJump(i2) << "\n";
    return 0;
}