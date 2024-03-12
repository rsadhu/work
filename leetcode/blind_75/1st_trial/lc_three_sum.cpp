#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

std::vector<int> sum_of_three_is_zero(std::vector<int> &input, int target = 0)
{
    std::sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        if (i > 0 && input[i] == input[i - 1])
        {
            continue;
        }
        else
        {
            int left = input[i];
            int right = input[input.size() - 1];
            while (left < right)
            {
                if (input[i] + left + right == 0)
                {
                    return {input[i], left, right};
                }
                else if ((input[i] + left + right) < 0)
                {
                    left++;
                }
                else
                {
                    right++;
                }
            }
        }
    }
    return {};
}

std::vector<std::vector<int>> sum_of_three_all_possibilities(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> res;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i > 0 && (nums[i] == nums[i - 1]))
            continue;

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            std::vector<int> r;
            if (nums[i] + nums[left] + nums[right] == target)
            {
                r.push_back(nums[i]);
                r.push_back(nums[left]);
                r.push_back(nums[right]);
                res.push_back(r);
                left++;
                while (nums[left] == nums[left - 1] && left < right)
                    left++;
            }
            else if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return res;
}

void test1()
{
    std::vector<int> input = {0, 1, -3, 3, -2};
    auto res = sum_of_three_is_zero(input);

    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

void test2()
{
    std::vector<int> input = {5, -5, 0, 3, -2};
    auto res = sum_of_three_is_zero(input);
    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

void test3()
{
    std::vector<int> input = {0, 1, -1, 3, -2};
    auto res = sum_of_three_is_zero(input);
    for (auto it : res)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

int main(void)
{
    std::vector<int> input = {0, 1, -3, 3, -2, -3, 9, 5, 6, 34, 4, 8};
    auto res = sum_of_three_all_possibilities(input, 1);
    test1();
    test2();
    test3();
    return 0;
}