#include <iostream>
#include <vector>

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

1 <= prices.length <= 105
0 <= prices[i] <= 104

 */

// prices = { 10, 19, 20, 15, 12, 1}
int max_profil(std::vector<int> &prices)
{
    int min = INT_MAX, max = 0;
    for (auto it : prices)
    {
        min = std::min(it, min);
        max = std::max(max, it - min);
    }
    return max;
}

/*
We say that two strings are twins if they have the same number of letters
(case
sensitive). For example:
“lookout” is a twin of “outlook”, but “Lookout” is not a twin of “outlook”
because of
the capital L. Write a function isTwin that returns true if two strings are
twins and
false otherwise.
*/
bool isTwin(std::string a, std::string b)
{
    // write your code here
}

int main(int argc, char argv[][3])
{
    std::vector<int> prices = {10, 19, 20, 15, 12, 1};
    std::cout << max_profil(prices);
    return 0;
}