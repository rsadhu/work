#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        std::vector<std::vector<string>> res;
        std::vector<int> l(26, 0);
        std::map<std::vector<int>, std::vector<string>> lookup;
        for (auto s : strs)
        {
            for (auto ch : s)
            {
                l[ch - 'a'] = +1;
            }

            auto &v = lookup[l];
            std::cout << s << "\n";
            v.push_back(s);
        }

        for (auto &[key, value] : lookup)
        {
            res.push_back(value);
        }

        return res;
    }
};

int main(void)
{

    Solution s;

    std::vector<std::string> ana = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.groupAnagrams(ana);
    return 0;
}