#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    std::vector<std::vector<int>> res;

    if (intervals.size() == 0 || intervals.size() == 1)
        return intervals;

    std::sort(intervals.begin(), intervals.end());

    int i = 1;
    auto cur = intervals[i - 1];
    auto next = intervals[i];
    bool merged = false;
    while (intervals.size() > i)
    {
        next = intervals[i];
        if (cur[1] >= next[0])
        {
            if (next[1] > cur[1])
                cur[1] = next[1];

            merged = true;
        }
        else
        {
            res.push_back(cur);
            cur = next;
            merged = false;
        }
        i++;
    }
    merged ? res.push_back(cur) : res.push_back(next);

    return res;
}

int main(void)
{

    std::vector<std::vector<int>> list = {{1, 3}, {6, 9}};
    std::vector<int> interval = {2, 5};
    auto res = insert(list, interval);

    for (auto inter : res)
    {
        std::cout << inter[0] << "," << inter[1] << " ";
    }
    std::cout << "\n";

    list = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    interval = {4, 8};
    res = insert(list, interval);

    for (auto inter : res)
    {
        std::cout << inter[0] << "," << inter[1] << " ";
    }
    std::cout << "\n";
    return 0;
}