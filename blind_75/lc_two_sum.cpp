#include <iostream>
#include <vector>
#include <map>

void find_indices(std::vector<int> &input, std::vector<std::pair<int, int>> &output, int target)
{
    for (int i = 0; i < input.size(); i++)
    {
        int ele = input[i];
        auto iter = std::find(input.begin() + i, input.end(), target - ele);
        if (iter != input.end())
        {
            std::pair<int, int> indices{i, iter - input.begin()};
            output.push_back(indices);
        };
    }
}

int main(void)
{
    std::vector<int> input = {1, 2, 3, 6, 4, 5, 7};
    int target = 7;
    std::vector<std::pair<int, int>> output;
    find_indices(input, output, target);
    for (auto &pair : output)
    {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}