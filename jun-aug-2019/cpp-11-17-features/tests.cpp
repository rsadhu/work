#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
#include <functional>

int candles(int candlesNumber, int makeNew) {

    int sum  = candlesNumber;
    int remainder = 0;

    while(candlesNumber > 1)
    {
        sum += candlesNumber / makeNew;

        remainder =  candlesNumber % makeNew;

        candlesNumber = candlesNumber / makeNew  + remainder ;
    }

    return sum;
}


std::string decipher(std::string cipher) {
    std::string res;
    size_t cnt = 0;

    for(size_t i = 0;i < cipher.size();) {
        char ch = cipher[i];
        int sb = 0;
        if(ch != '9') {
            cnt = 3;
        }
        else {
            cnt = 2;
        }

        sb = std::stoi(cipher.substr(i, cnt));
        i+=cnt;
        res+= static_cast<char>(sb);
    }

    return res;
}

bool robotWalk(std::vector<int> a) {
    std::pair<int, int> pos(0,0);
    int d = 0 , i =0;
    for(auto it: a)
    {
        if(d == 0) {
            pos.second += it;
        }
        else if(d == 1) {
            pos.first += it;
        }
        else if(d == 2) {
            pos.second -= it;
        }
        else if(d == 3) {
            pos.first -= it;
        }

        d = ++i %4;
    }

    if(pos.first < 0 || pos.second < 0)
        return false;
    return true;
}

bool checkEqualFrequency(std::vector<int> inputArray) {

    std::map<int, int> lu;

    for(auto it: inputArray)
    {
        lu[it] +=1;
    }

    auto tmp = lu.begin();

    for(auto it =  lu.begin();it!=lu.end();it++)
    {
        if(it->second != tmp->second)
        {
            return false;
        }
    }
    return true;

}

int cal(int n)
{
    if(n > 0)
    {
        int sum = 0;
        std::vector<int> l;
        for(int i =2; i<=n;)
        {
            if(n%i==0) {
                l.push_back(i);
                sum+=i;
                n/=i;
            }
            else {
                i++;
            }
        }
        return sum;
    }
}

int factorSum(int n) {

    int m = n;
    while(1)
    {
        m = cal(n);
        if(m==n)
            break;
        n = m;
    }
}

int deleteDigit(int n) {
    std::string str = std::to_string(n);

    std::string str1;
    int c = 0;
    int min = 10, i=0,j=0;
    for(auto it: str)
    {
        if(it - '0' < min)
        {
            min = it - '0';
            j =  i;
        }
        i++;
    }

    i = 0;
    for(auto it: str)
    {
        if(i==j)
        {
            i++;
            continue;
        }
        str1+=it;
        i++;

    }

    return std::stoi(str1);
}


//foo(bar(baz))blim
std::string reverseInParentheses(std::string inputString)
{
    std::stack<char> st;
    std::string res;

    for(size_t i = 0; i < inputString.size(); i++)
    {
        if(inputString[i] == '(')
        {
            st.push(inputString[i]);
        }
        else if(inputString[i] == ')')
        {
            while(!st.empty())
            {
                if(st.top()=='(')
                    break;
            }
        }
        else
        {
            res+=inputString[i];
        }
    }

    return res;
}


int main(void)
{

    int a=0, b =1;
    return 0;
}
