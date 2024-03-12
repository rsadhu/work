#include <iostream>
#include <map>

bool are_anagrams_method1(std::string s1, std::string s2)
{
    std::map<char, int> m1, m2;

    for (auto ch : s1)
    {
        m1[ch]++;
    }

    for (auto ch : s2)
    {
        m2[ch]++;
    }

    return m1 == m2;
}

bool are_anagrams_method2(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main(void)
{
    if (are_anagrams_method1("haha", "hah"))
    {
        std::cout << " are anagrams\n";
    }
    else
    {
        std::cout << " are not anagram\n";
    }

    if (are_anagrams_method2("haha", "haah"))
    {
        std::cout << " are anagrams\n";
    }
    else
    {
        std::cout << " are not anagram\n";
    }

    return 0;
}