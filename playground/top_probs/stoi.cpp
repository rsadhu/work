#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while (*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

int p_myAtoi(std::string s, bool &ret)
{
    int final_num = 0;
    //  bool fail_it = false;
    bool over_flow = false;
    int j = -1, sign = 1;
    int i = s.size() - 1;
    for (; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            long int tmp_sum = (final_num + (s[i] - '0') * std::pow(10, j);
            if ( tmp_sum >= (std::pow(2, 32))) {
                over_flow = true;
                continue;
            }

            j++;
            final_num += (s[i] - '0') * std::pow(10, j);
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '-')
                sign = -1;
            break;
        }
        else
        {
            ret = true;
            return 0;
        }
    }

    if (over_flow)
    {
        return sign * (std::pow(2, 32 - 1) - 1);
    }
    else
    {
        return sign * final_num;
    }
}

int myAtoi(std::string s)
{

    std::vector<std::string> ss = split(s.c_str());
    int x = 0;
    for (auto it : ss)
    {
        if (it.length() > 0)
        {
            bool ret = false;
            x = p_myAtoi(it, ret);

            if (ret)
                break;
        }
        if (x != 0)
            return x;
    }
    return x;
}

int main(void)
{
    std::cout << "\n string to integer :: " << myAtoi("21474836460") << "\n";
    return 0;
}