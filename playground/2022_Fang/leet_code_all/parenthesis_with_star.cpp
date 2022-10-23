
#include <string>
#include <iostream>
#include <stack>

bool checkParenthesis(std::string s)
{
    std::stack<char> st;
    int joker = 0;
    for (auto it : s)
    {
        if (it == '(')
            st.push(it);
        else if (it == ')')
        {
            if (st.empty())
            {
                if (joker == 0)
                {
                    return false;
                }
                else
                {
                    joker--;
                }
            }
            else
            {
                st.pop();
            }
        }
        else
        {
            joker++;
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int main(void)
{
    std::string str = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";

    std::cout << checkParenthesis(str);

    return 0;
}