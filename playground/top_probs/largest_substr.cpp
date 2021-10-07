#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int eff_soln(string str)
{
    int n = str.size();
    unordered_map<char, int> freqMap;

    int start = 0, end = 0, maxLen = 0;
    while (end < n) {
        freqMap[str[end]]++;
        if (freqMap[str[end]] == 1) {
            end++;
            maxLen = std::max(maxLen, end - start);
            continue;
        }
        while (freqMap[str[end]] > 1) {
            freqMap[str[start]]--;
            start++;
        }
        end++;
    }
    return maxLen;
}

int main(void)
{

    std::cout << eff_soln("abcabcbb");
    return 0;
}