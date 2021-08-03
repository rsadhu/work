#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(const char* str, char c = ' ')
    {
        vector<string> result;

        do {
            const char* begin = str;

            while (*str != c && *str)
                str++;

            result.push_back(string(begin, str));
        } while (0 != *str++);

        return result;
    }

    int p_myAtoi(std::string s, bool& ret)
    {
        int final_num = 0;
        
        int j = -1, sign = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                // if (fail_it)
                //     break;
                j++;
                final_num += (s[i] - '0') * std::pow(10, j);
            } else if (s[i] == '+' || s[i] == '-') {
                if (s[i] == '-')
                    sign = -1;
                break;
            } else {
                ret = true;
                return 0;
            }
        }
        // if (fail_it) {
        //     ret = fail_it;
        //     return 0;
        // }
        if (final_num >= std::pow(2, 32)) {
            return std::pow(2, 32);
        } else if (final_num < (-1 * std::pow(2, 32) - 1)) {
            return -1 * std::pow(2, 32) - 1;
        } else {
            return sign * final_num;
        }
    }

    int myAtoi(std::string s)
    {

        std::vector<std::string> ss = split(s.c_str());
        int x = 0;
        for (auto it : ss) {
            if (it.length() > 0){
            bool ret = false;
            x = p_myAtoi(it, ret);

            if (ret)
                break;
            }
        }
        return x;
    }
};

int main(void)
{
    Solution s;
    s.myAtoi("-91283472332");
    return 0;
}