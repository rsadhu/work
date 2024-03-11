#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {

        std::unordered_map<char, int> lookup;
        int i = 0;
        for (auto ch : order)
        {
            lookup[ch] = i++;
        }
        std::string res;
        std::string sub_res;

        for (int i = 0; i < s.size(); i++)
        {
            auto ch = s[i];
            auto index = lookup[ch];
            if (index < lookup[res[0]])
            {
                res.insert(0, 1, ch);
            }
            else if (index > lookup[res[res.size() - 1]])
            {
                res += ch;
            }
            else
            {
                sub_res += ch;
            }
        }
        return res + sub_res;
    }
};

int main(void)
{
    Solution s;
    std::cout << s.customSortString("bad", "abcd");
    return 0;
}