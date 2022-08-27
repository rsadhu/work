#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool my_isalnum(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;
    if (ch >= 'A' && ch <= 'Z')
        return true;
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool isPalindrome(string s)
{

    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (std::toupper(s[i]) == std::toupper(s[j]))
            {
                i++;
                j--;
            }
            else if (!isalnum(s[i]))
            {
                i++;
            }
            else if (!isalnum(s[j]))
            {
                j--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    std::cout << isPalindrome("A man, a plan, a canal: Panama");

    std::cout << "\n";
    std::vector<char> vec = {'a', '!', '_', ' ', ',', ';', '>'};

    for (auto it : vec)
    {
        std::cout << it << "  is alphanumeric   " << my_isalnum(it) << "\n";
    }

    std::cout << "\n";
    return 0;
}