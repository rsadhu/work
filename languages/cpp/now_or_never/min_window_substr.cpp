#include "utility.h"
using namespace std;

string minWindow(string s, string t)
{

    if (t.size() > s.size())
        return "";

    if (t == s)
        return t;

    std::map<int, std::string> str;
    for (int i = 0; i < s.size(); i++) {
        std::string tmp;

        std::multiset<char> lookup(t.begin(), t.end());

        for (int j = i; j < s.size() && lookup.size() > 0; j++) {
            if (lookup.count(s[j]) > 0) {
                lookup.erase(lookup.lower_bound(s[j]));
            }
            tmp += s[j];
        }

        if (lookup.size() == 0) {
            str[tmp.size()] = tmp;
        }
    }

    if (str.size() > 0)
        return str.begin()->second;
    return "";
}

int main(void)
{
    std::string s = "bbaa", t = "aba";
    std::cout << minWindow(s, t) << " \n";
    return 0;
}