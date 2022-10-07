#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <iostream>

using graph = std::multimap<std::string, std::string>;

std::set<std::string> u_graph;

void dfs_rec(graph g, std::string start)
{
    // auto range = g[start];
}

void dfs_iter(graph g, std::string start)
{
    std::cout << "\n";
    std::stack<std::string> st;
    st.push(start);
    while (!st.empty())
    {
        std::string node = st.top();
        st.pop();
        std::cout << node << " ";
        auto range = g.equal_range(node);
        for (auto i = range.first; i != range.second; ++i)
        {
            if (u_graph.count(i->second) == 0)
            {
                u_graph.insert(i->second);
                st.push(i->second);
            }
        }
    }
}

void bfs_rec(graph g, std::string start)
{
}

void bfs_iter(graph g, std::string start)
{
    std::cout << "\n";
    std::queue<std::string> q;
    q.push(start);
    while (!q.empty())
    {
        std::string node = q.front();
        u_graph.insert(node);
        q.pop();
        std::cout << node << " ";
        auto range = g.equal_range(node);
        for (auto i = range.first; i != range.second; ++i)
        {
            if (u_graph.count(i->second) == 0)
            {
                u_graph.insert(i->second);
                q.push(i->second);
            }
        }
    }
}

int main(void)
{
    graph g;
    g.insert(std::make_pair("a", "b"));
    g.insert(std::make_pair("a", "c"));
    //    g.insert(std::make_pair("a", "d"));

    g.insert(std::make_pair("b", "d"));

    g.insert(std::make_pair("c", "e"));

    g.insert(std::make_pair("e", "f"));
    g.insert(std::make_pair("f", "h"));

    g.insert(std::make_pair("d", "g"));
    //    g.insert(std::make_pair("d", "e"));

    dfs_rec(g, "a");
    dfs_iter(g, "a");

    std::cout << "\n";

    // for (auto it : u_graph)
    // {
    //     std::cout << it << " ";
    // }

    u_graph.clear();

    bfs_rec(g, "a");
    bfs_iter(g, "a");

    std::cout << "\n";

    // for (auto it : u_graph)
    // {
    //     std::cout << it << " ";
    // }

    return 0;
}