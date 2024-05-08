#include "common.h"

bool valid_anagram_using_lookup(std::string &s, std::string &t)
{
    std::set<char> lu;

    if (t.size() != s.size())
        return false;

    for (auto ch : s)
    {
        lu.insert(ch);
    }

    for (auto ch : t)
    {
        if (lu.find(ch) == lu.end())
            return false;
    }

    return true;
}

int main(void)
{
    {
        std::string s = "anagram", t = "nagaram";
        std::cout << s << " " << t << " are same -->  " << valid_anagram_using_lookup(s, t);
    }

    std::string s = "rat", t = "cat";
    std::cout << "\n"
              << s << " " << t << " are same -->  " << valid_anagram_using_lookup(s, t);
    return 0;
}