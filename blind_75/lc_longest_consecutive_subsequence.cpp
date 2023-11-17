#include <iostream>
#include <unordered_set>
#include <vector>

int longest_consecutive_sequence(std::vector<int> &input)
{
    std::unordered_set<int> lookup(input.begin(), input.end());
    int longest = 0;
    for (auto ele : input)
    {
        auto iter = lookup.find(ele - 1);
        if (iter == lookup.end())
        {
            int length = 1;
            while (true)
            {
                ele += 1;
                auto iter = lookup.find(ele);
                if (iter != lookup.end())
                    length++;
                else
                    break;
            }
            longest = std::max(length, longest);
        }
    }
    return longest;
}

void test1()
{
    std::vector<int> input = {100, 1, 200, 4, 3, 2};
    auto length = longest_consecutive_sequence(input);
    std::cout << " longest length is --> " << length << "\n";
}

void test2()
{
    std::vector<int> input = {1, 2, 100, 200, 0};
    auto length = longest_consecutive_sequence(input);
    std::cout << " longest length is --> " << length << "\n";
}

int main(void)
{
    test1();
    test2();
    return 0;
}