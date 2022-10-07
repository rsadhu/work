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

std::map<std::pair<std::string, std::string>, int> g_edge_weight;

std::multimap<std::string, std::string> g_path;

std::set<std::string> visited_nodes;

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

    g_edge_weight.insert(std::make_pair(pair, int_val));

    g_path.insert(std::make_pair(first,second));

    return true;
}

bool hasPath(std::string start, std::string end, int max_limit,     std::string &final_str)
{
    std::stack<std::string> st;
    st.push(start);
    int sum = 0;
    bool found = false;
    while( !st.empty())
    {
        auto node = st.top();
        st.pop();
        final_str+=node;
        final_str+="->";
        if (node == end)
        {
            final_str = final_str.substr(0, final_str.length()-2);
            found = true;
            break;
        }

        auto curr_node = std::make_pair(start, node);
        auto weight = g_edge_weight[curr_node];

        sum += weight;
        start = node;

        auto neighbours_list = g_path.equal_range(node);

        for (auto it = neighbours_list.first; it != neighbours_list.second; it++)
        {
            if (visited_nodes.count(it->second) == 0)
            {
                visited_nodes.insert(it->second);
                st.push(it->second);
            }
            else {
              final_str="E2";
              return false;
            }
        }
    }

    if (!found)
        return false;

    return sum <= max_limit;
}

int main_()
{


    do
    {
        std::string value;
        std::cin>> value;
         if (value == "" || value.length() == 0)
        break;
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
            std::string st="A", ed="D";
            int max_limit=10;
            std::string path;
            bool res = hasPath(st, ed, max_limit, path);
            if (res)
                std::cout<<path;
            else {
                if (path.empty())
                    std::cout<<"E3";
                else
                    std::cout<<path;
            }
        }
    }while(true);
    return 0;
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
            std::string st="A", ed="D";
            int max_limit=10;
            std::string path;
            bool res = hasPath(st, ed, max_limit, path);
            std::cout <<" has path"<< res;;
        }
    }
    return 0;
}