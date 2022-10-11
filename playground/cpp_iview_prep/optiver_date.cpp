#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Date
{
    int Day;
    int Year;
    int Month;

    friend bool operator<(const Date &d1, const Date &d2)
    {
        if (d1.Year < d2.Year)
            return true;
        else if (d1.Year > d2.Year)
            return false;
        else
        {
            if (d1.Month < d2.Month)
                return true;
            else if (d1.Month > d2.Month)
                return false;
            else
            {
                if (d1.Day < d2.Day)
                    return true;
                else if (d1.Day > d2.Day)
                    return false;
            }
        }
        return true;
    }

    friend bool operator==(const Date &d1, const Date &d2)
    {
        return (d1.Year == d2.Year && d2.Month == d1.Month && d1.Day == d2.Day);
    }

    friend bool operator!=(const Date d1, const Date d2)
    {
        return !(d1 == d2);
    }

    friend bool operator>(const Date &d1, const Date &d2)
    {
        return !(d1 < d2);
    }
};

/*
 * Complete the function below.
 */

class cmp
{
public:
};

Date ThirdLatest(std::vector<Date> &dates)
{
    auto cmp = [](Date d1, Date d2)
    {
        if (d2 != d1)
        {
            return d1 < d2;
        }

        return false;
    };

    std::set<Date, decltype(cmp)> lu;
    for (auto it : dates)
    {
        lu.insert(it);
    }

    auto it_end = lu.end();
    it_end--;
    it_end--;
    it_end--;
    return *it_end;
}

int main()
{

    std::vector<Date> dates{
        {14, 04, 2001},
        {29, 12, 2061},
        {21, 10, 2019},
        {07, 01, 1973},
        {19, 07, 2014},
        {11, 03, 1992},
        {21, 10, 2019}};

    Date result = ThirdLatest(dates);
    printf("%02d-%02d-%d\n", result.Day, result.Month, result.Year);
    return 0;
}