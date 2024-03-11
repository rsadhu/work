#include <stack>
#include <iostream>

bool is_valid(std::string &str)
{
    std::stack<char> st;

    int i = 0;
    while (!st.empty() || i < str.size())
    {
        char ch = str[i++];
        if (ch == '}' || ch == ']' || ch == ')')
        {
            char pop_ch = st.top();
            st.pop();
            if ((ch == '}' && pop_ch == '{') || (ch == ')' && pop_ch == '(') || (ch == ']' && pop_ch == '['))
                continue;
            else
                return false;
        }
        else
        {
            st.push(ch);
        }
    }
    return true;
}

bool is_valid_rec(std::string &str, char &prev_ch)
{
    if (str.size() == 0 || str == "")
        return true;

    char ch = str[0];
    str = str.substr(1, str.size() - 1);

    if (ch == ')')
    {
        if (prev_ch != '(')
            return false;
    }
    else if (ch == '}')
    {
        if (prev_ch != '{')
            return false;
    }
    else if (ch == ']')
    {
        if (prev_ch != '[')
            return false;
    }
    else
    {
        prev_ch = ch;
        return is_valid_rec(str, prev_ch);
    }

    return true;
}

int main(void)
{
    std::vector<std::string> inputs = {"()", "()[]{}", "(}"};

    // for (auto str : inputs)
    // {
    //     std::cout << str;
    //     is_valid(str) ? std::cout << " is  valid\n" : std::cout << " is invalid\n";
    // }

    char ch;
    for (auto str : inputs)
    {
        std::cout << str;
        ch = str[0];
        is_valid_rec(str, ch) ? std::cout << " is  valid\n" : std::cout << " is invalid\n";
    }

    return 0;
}