#include "common.h"

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