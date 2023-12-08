#include "utility.h"

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> res;
    int target = 0;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {

        if (i > 0 && (nums[i] == nums[i - 1]))
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            std::vector<int> r;
            if ((nums[i] + nums[left] + nums[right]) == target) {
                r.push_back(nums[i]);
                r.push_back(nums[left]);
                r.push_back(nums[right]);
                res.push_back(r);
                left++;
                while (nums[left] == nums[left - 1] && left < right) {
                    left++;
                }

            } else if ((nums[i] + nums[left] + nums[right]) > target) {
                right--;
            } else {
                left++;
            }
        }
    }

    return res;
}

int main(void)
{
    std::vector<int> list = { -1, 0, 1, 2, -1, -4 };
    auto l = threeSum(list);

    for (auto it : l) {
        for (auto el : it) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
    return 0;
}