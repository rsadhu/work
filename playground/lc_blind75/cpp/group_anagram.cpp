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

std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> &list)
{
    std::vector<std::vector<std::string>> r;

    std::map<std::string, std::vector<std::string>> lu;
    for (auto str : list)
    {
        auto tmp = str;
        std::sort(tmp.begin(), tmp.end());
        lu[tmp].push_back(str);
    }

    for (auto &[key, val] : lu)
    {
        r.push_back(val);
    }
    return r;
}

int main(void)
{
    std::vector<std::string> list = {"eat",
                                     "tea",
                                     "tan",
                                     "ate",
                                     "nat",
                                     "bat"};

    std::cout << list;
    std::cout << std::string("\n");

    for (auto sub_list : group_anagrams(list))
    {
        std::cout << sub_list;
        std::cout << std::string("\n");
    }
    return 0;
}