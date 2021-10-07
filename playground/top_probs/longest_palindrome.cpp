#include <iostream>

#include <string>

std::string brute_force(std::string s)
{
    if (s.size() == 1)
        return s;
    std::string res;

    auto isPalindrome = [](std::string s) {
        int beg = 0, end = s.size() - 1;

        while (beg <= end) {
            if (s[beg++] != s[end--])
                return false;
        }

        return true;
    };

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                auto sub_str = s.substr(i, j - i);
                if (isPalindrome(sub_str)) {
                    if (sub_str.size() > res.size()) {
                        res = sub_str;
                    }
                }
            }
        }
    }

    return res;
}

std::string longestPalindrome(std::string s)
{

    return brute_force(s);
}

int main()
{
    std::cout << longestPalindrome("cbbd");
    return 0;
}