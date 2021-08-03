#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    std::vector<int> nums = { 3, 2, 4 }; //{2,7,11,15};
    int target = 6;

    std::map<int, int> lookup;

    for (int i = 0; i < nums.size(); i++) {
        lookup[nums[i]] = i;
    }

    std::vector<int> res;
    for (auto i = 0; i < nums.size(); i++) {
        if (lookup.find(target - nums[i]) != lookup.end()) {
            if (i != lookup[target - nums[i]]) {
                res.push_back(i);
                res.push_back(lookup[target - nums[i]]);
                break;
            }
        }
    }

    for (auto it : res) {
        std::cout << it << " ";
    }

    return 0;
}