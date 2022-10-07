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
#include <map>

using namespace std;
using graph = std::multimap<std::pair<std::string, std::string>, int>;
using visited_nodes = std::set<std::string>;

graph g;
visited_nodes v;

bool addToGraph(std::string value)
{

    if (value[0] != '[' && value[value.length() - 1] != ']')
        return false;

    value = value.substr(1);
    value = value.substr(0, value.length() - 1);

    if (value[0] <= 'A' && value[0] >= 'Z')
        return false;

    std::string first(1, value[0]);

    if (value[2] <= 'A' && value[2] >= 'Z')
        return false;

    std::string second(1, value[2]);

    auto value_int = value.substr(4, value.length());

    int int_val = 0;

    try
    {
        int_val = std::stoi(value_int);
    }
    catch (...)
    {
        return false;
    }

    auto pair = std::make_pair(first, second);
    //   std::cout << pair.first << pair.second;
    //  g.insert(pair, int_val);
    return true;
}

int main()
{
    std::vector<std::string> input = {
        "[A,B,3]", "[B,C,5]", "[C,D,2]",
        "A->D,10"};

    for (auto value : input)
    {
        if (value.find("->") == std::string::npos)
        {
            if (!addToGraph(value))
            {
                std::cout << "E1";
                return 0;
            }
        }
        else
        {
        }
    }
    return 0;
}