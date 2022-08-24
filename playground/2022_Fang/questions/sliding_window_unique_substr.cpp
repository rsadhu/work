#include <iostream>
#include <set>
#include <string>
#include <vector>
//#include <unordered_map>
#include <unordered_set>

using namespace std;

int lengthofSs(string s)
{
    int ans = 0;
    unordered_set<char> set;
    int i = 0;
    int j = 0;
    int n = s.size();
    while (i < n && j < n)
    {
        if (set.find(s[j]) == set.end())
        {
            set.insert(s[j++]);
            ans = max(ans, j - i);
        }
        else
            set.erase(s[i++]);
    }
    return ans;
}

int lengthOfLongestSubstring(string s)
{
    return lengthofSs(s);

    std::set<char> check_up;
    std::string window;
    int max = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (check_up.count(s[i]) == 0)
        {
            check_up.insert(s[i]);
            window += s[i];
        }
        else
        {
            max = std::max(max, (int)check_up.size());
            auto pos = window.find(s[i]);
            if (pos != std::string::npos)
            {
                window = window.substr(pos + 1);
                window += s[i];
                check_up.clear();
                std::copy(window.begin(), window.end(), inserter(check_up, check_up.end()));
            }
        }
    }
    return max;
}

int main(void)
{
    std::vector<std::string> inputs = {
        "aab",
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        " "};

    for (auto it : inputs)
    {
        std::cout << "\n the length of the longest sub is " << lengthOfLongestSubstring(it);
    }
    return 0;
}