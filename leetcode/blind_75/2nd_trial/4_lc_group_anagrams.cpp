#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        if (strs.size() == 0)
            return {};

        std::map<std::string, std::vector<std::string>> lu;
        std::vector<std::vector<string>> res_s;

        for (auto str : strs)
        {
            auto tmp = str;
            std::sort(tmp.begin(), tmp.end());
            lu[tmp].push_back(str);
        }

        for (auto &[key, value] : lu)
        {
            res_s.push_back(value);
        }
        return res_s;
    }
};

int main(void)
{
    std::vector<std::string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution s;

    auto res = s.groupAnagrams(v);
    for (auto v : res)
    {
        for (auto r : v)
        {
            std::cout << r << " ";
        }
        std::cout << "\n";
    }

    return 0;
}