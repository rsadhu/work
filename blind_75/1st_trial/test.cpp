// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <string>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <exception>
#include <vector>

std::vector<std::string> tokenize(std::string &s)
{
    size_t pos = 0;
    std::string token = "";
    std::string delimiter = " ";
    std::vector<std::string> result;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    if (s != "" || s != " ")
        result.push_back(s);
    return result;
}

class OperStack
{
public:
    void push(size_t val);
    size_t pop();
    void add();
    void substract();
    void duplicate();
    size_t result()
    {
        if (!st_.empty())
        {
            return st_.top();
        }
        else
        {
            throw std::runtime_error("stack is empty, pop failed");
        }
    }

    bool checkValue(size_t val)
    {
        auto limit = []() -> size_t
        {
            return std::pow(2, 20) - 1;
        };

        if (val >= 0 && val <= limit())
        {
            return true;
        }
        return false;
    }

private:
    std::stack<size_t> st_;
};

void OperStack::push(size_t val)
{
    if (checkValue(val))
    {
        st_.push(val);
    }
    else
    {
        throw std::runtime_error("out of range");
    }
}

size_t OperStack::pop()
{
    auto val = 0;
    if (!st_.empty())
    {
        val = st_.top();
        st_.pop();
        return val;
    }
    else
    {
        throw std::runtime_error("stack is empty, pop failed");
    }
    return val;
}

void OperStack::add()
{
    size_t val = 0;
    if (!st_.empty())
    {
        size_t operand1 = st_.top();
        st_.pop();
        size_t operand2 = 0;
        if (!st_.empty())
        {
            operand2 = st_.top();
            st_.pop();
        }
        else
        {
            throw std::runtime_error("stack is empty, pop failed");
        }
        val = operand2 + operand1;
        if (!checkValue(val))
        {
            throw std::runtime_error("out of range");
        }
    }
    st_.push(val);
}

void OperStack::substract()
{
    size_t val = 0;
    if (!st_.empty())
    {
        size_t operand1 = st_.top();
        st_.pop();
        size_t operand2 = 0;
        if (!st_.empty())
        {
            operand2 = st_.top();
            st_.pop();
        }
        else
        {
            throw std::runtime_error("stack is empty, pop failed");
        }
        val = operand1 - operand2;
        if (!checkValue(val))
        {
            throw std::runtime_error("out of range");
        }
    }
    st_.push(val);
}

void OperStack::duplicate()
{
    if (!st_.empty())
    {
        auto val = st_.top();
        st_.push(val);
    }
    else
    {
        throw std::runtime_error("stack is empty, duplicate failed");
    }
}

int solution(std::string &S)
{
    // Implement your solution here

    std::vector<std::string> commands = tokenize(S);
    OperStack st;
    try
    {
        for (const auto &cmd : commands)
        {
            if (cmd == "DUP")
            {
                st.duplicate();
            }
            else if (cmd == "POP")
            {
                st.pop();
            }
            else if (cmd == "+")
            {
                st.add();
            }
            else if (cmd == "-")
            {
                st.substract();
            }
            else
            {
                st.push(std::stoul(cmd));
            }
        }
    }
    catch (...)
    {
        return -1;
    }

    try
    {
        return st.result();
    }
    catch (...)
    {
        return -1;
    }

    return 0;
}

int main()
{
    std::vector<std::string> inp = {
        "504857 DUP +"};
    for (auto i : inp)
    {
        std::cout << solution(i) << "\n";
    }
    return 0;
}