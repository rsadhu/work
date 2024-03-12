#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int beg = 0, end = s.size() - 1;
        while (beg <= end)
        {
            if (s[beg] == s[end])
            {
                beg++;
                end--;
            }
            else
            {
                if (toupper(s[beg]) == toupper(s[end]))
                {
                    beg++;
                    end--;
                }
                else if (!isalnum(s[beg]))
                {
                    beg++;
                }
                else if (!isalnum(s[end]))
                {
                    end--;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(void)
{

    std::string test_s = "A man, a plan, a canal: Panama";
    Solution s;
    std::cout << s.isPalindrome(test_s);
    return 0;
}