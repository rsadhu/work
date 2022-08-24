#include <cmath>
#include <iostream>
#include <vector>

uint32_t reverseBits(uint32_t n)
{

    std::vector<int> arr;

    while (n)
    {
        arr.push_back(n % 10);
        n /= 10;
    }

    auto ret = 0;
    int cnt = 0;
    for (auto it = arr.rbegin(); it != arr.rend(); it++)
    {
        if (*it == 1)
            ret += std::pow(2, cnt);
        cnt++;
    }

    return ret;
}

std::string reverseWords(std::string s)
{

    std::string str;
    std::string tmp = "";
    for (auto it : s)
    {
        if (it == ' ')
        {
            if (tmp.length() != 0)
            {
                std::reverse(tmp.begin(), tmp.end());
                str += tmp;
                tmp = "";
            }
            else
            {
                str += " ";
            }
        }
        else
        {
            tmp += it;
        }
    }

    return str;
}

int main(int argc, char *argv[])
{
    // std::cout<<reverseBits(00000010100101000001111010011100);

    std::cout << reverseWords("Let's take LeetCode contest");
    return 0;
}