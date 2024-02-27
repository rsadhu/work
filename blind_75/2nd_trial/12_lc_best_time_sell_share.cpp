#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = INT_MIN;
        int min = INT_MAX;
        for (auto it : prices)
        {
            min = std::min(min, it);
            max = std::max(max, it - min);
        }

        return max;
    }
};

int main(void)
{
    Solution s;
    std::vector<int> l = {7, 1, 5, 3, 6, 4};
    std::cout << s.maxProfit(l);
}