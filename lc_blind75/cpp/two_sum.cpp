#include "common.h"

template <typename T>
std::ostream &
operator<<(std::ostream &o, std::vector<T> &r)
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, std::string> ||
                      std::is_same_v<T, bool>,
                  "std::cout function only supports  container's int,bool, float and std::string types");
    for (auto el : r)
    {
        o << el << " ";
    }
    return o;
}

std::vector<int> two_sum(std::vector<int> &r, int target)
{
    std::unordered_map<int, int> lu;
    auto index = 0;
    for (auto el : r)
    {
        lu[el] = index++;
    }

    index = 0;
    for (auto el : r)
    {
        if (lu.find(target - el) != lu.end())
        {
            return {index, lu[target - el]};
        }
        index++;
    }
    return {-1, -1};
}

int main(void)
{
    std::vector<int> inp = {2, 7, 11, 15};

    auto r = two_sum(inp, 5);
    std::cout << r;
    return 0;
}