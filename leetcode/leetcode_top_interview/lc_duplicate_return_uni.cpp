#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0, j = 1; j < nums.size();)
        {
            while (nums[i] == nums[j])
            {
                j++;
            }
            i = j;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    std::vector<int> l = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution s;
    std::cout << s.removeDuplicates(l);

    l = {1, 1, 2};

    std::cout << s.removeDuplicates(l);
    return 0;
}