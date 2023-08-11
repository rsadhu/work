#include <vector>
#include <iostream>

std::vector<std::vector<int>> findSubLists(std::vector<int> &list, int sum)
{
    std::vector<std::vector<int>> res;
    int l = 0, r = 0, total = 0;
    while (r < list.size())
    {
        if (total == sum)
        {
            std::vector<int> sublist;
            for (int i = l; i < r; i++)
            {
                sublist.push_back(list[i]);
            }
            res.push_back(sublist);
        }
        else if (total < sum)
        {
            total += list[r];
            r++;
        }
        else
        {
            while (l < list.size() && total > sum)
            {
                total -= list[l];
                l++;
            }
        }
    }
    return res;
}

int main(void)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, -8, 10, 2};

    auto lists = findSubLists(data, 9);

    for (auto list : lists)
    {
        for (auto ele : list)
        {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }

    return 0;
}