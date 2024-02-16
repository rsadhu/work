#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;
class Solution
{
    std::unordered_map<char, int> lookup;

public:
    int max()
    {
        int m = 0;
        for (auto &[key, value] : lookup)
        {
            m = std::max(m, value);
        }
        return m;
    }
    int characterReplacement(string s, int k)
    {

        int l = 0, r = 0, res = 0;
        for (auto ch : s)
        {
            lookup[s[r]]++;
            while ((r - l + 1 - this->max()) > k)
            {
                lookup[s[l]]--;
                l++;
            }
            res = std::max(res, r - l + 1);
            r++;
        }
        return res;
    }

    bool isStringThere(std::unordered_map<char, int> &lookup)
    {
        for (auto &[key, value] : lookup)
        {
            if (value == 0)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {

        std::unordered_map<char, int> lookup;
        for (auto ch : t)
        {
            lookup[ch] = 0;
        }

        int l = 0, r = 0, count = lookup.size();
        std::string result;
        std::map<int, std::string> result_map;
        while (r < s.size())
        {
            lookup[s[r]]++;
            while (isStringThere(lookup))
            {
                result_map[r + 1 - l] = s.substr(l, r + 1);
                if (lookup[s[l]] > 0)
                    lookup[s[l]]--;
                l++;
            }
        }
        return result_map[0];
    }
};

int main(void)
{
    Solution s;
    // s.characterReplacement("ABAB", 2);
    //  s.characterReplacement("AABABBA", 1);
    std::cout << s.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}