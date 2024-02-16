#include <iostream>
#include <set>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

bool contains_duplicate(std::vector<int> &list, int &res)
{
    std::set<int> lu;
    for (auto ele : list)
    {
        if (lu.find(ele) != lu.end())
        {
            res = ele;
            return true;
        }
        lu.insert(ele);
    }
    return false;
}

bool contains_duplicate_without_extra_space(std::vector<int> &list, int &res)
{
    std::sort(list.begin(), list.end());
    int i = 0, j = 1;
    for (; j < list.size(); j++)
    {
        if (list[i] == list[j])
        {
            res = list[i];
            return true;
        }
    }
    return false;
}

int main(void)
{
    std::vector<std::vector<int>> pack =
        {
            {1, 2, 3, 1, 2, 2, 4, 5, 1, 3, 5, 6, 7, 7},
            {1, 2, 3, 4, 0, -1, 2, 3, 4, 4, 4, 4},
            {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};

    int res = -1;

    auto begin = std::chrono::system_clock::now();
    for (auto list : pack)
    {
        if (contains_duplicate_without_extra_space(list, res))
        {
            std::cout << " duplicate is " << res << "\n";
        }
    }
    auto end = std::chrono::system_clock::now();

    std::cout << "1>> time spent is " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin)).count();

    begin = std::chrono::system_clock::now();
    for (auto list : pack)
    {
        if (contains_duplicate(list, res))
        {
            std::cout << " duplicate is " << res << "\n";
        }
    }
    end = std::chrono::system_clock::now();

    std::cout << "2>> time spent is " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin)).count();

    return 0;
}