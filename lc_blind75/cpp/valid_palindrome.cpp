#include "common.h"

bool is_palindrome(std::string s)
{
    int st = 0, end = s.size() - 1;
    while (st <= end)
    {
        if (s[st] != s[end])
            return false;
        st++;
        end--;
    }

    return true;
}

bool is_char(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool valid_palindrome(std::string s)
{
    int st = 0, end = s.size();
    while (st <= end)
    {
        if (!is_char(s[st]))
        {
            st++;
            continue;
        }
        if (!is_char(s[end]))
        {
            end--;
            continue;
        }
        if (std::tolower(s[st]) != std::tolower(s[end]))
            return false;

        st++;
        end--;
    }

    return true;
}

int main(void)
{
    std::string s = "A man, a plan, a canal: Panama";
    std::string t = "MalayalaM";
    std::cout << is_palindrome(t);
    std::cout << "\n"
              << valid_palindrome(s);
    return 0;
}