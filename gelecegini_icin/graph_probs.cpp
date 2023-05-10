#include <iostream>
#include <map>
#include <list>
#include <queue>

bool hasPath_dfs(auto graph, auto start, auto end)
{
    if (start == end)
        return true;

    for (auto node : graph[start])
    {
        if (hasPath_dfs(graph, node, end))
            return true;
    }

    return false;
}

bool hasPath_bfs(auto graph, auto start, auto end)
{
    std::queue<char> q;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        if (start == end)
            return true;

        q.pop();
        for (auto node : graph[start])
        {
            q.push(node);
        }
    }
    return false;
}

int main(void)
{
    std::map<char, std::list<char>> graph_adj =
        {
            {'a', {'b', 'c'}},
            {'b', {'d'}},
            {'c', {'e'}},
            {'d', {'f'}},
        };

    auto start = 'a', end = 'c';
    bool res = hasPath_dfs(graph_adj, start, end);

    std::cout << " \nDFS\n";
    if (res == true)
    {
        std::cout << " there is a path between " << start << " & " << end << "\n";
    }
    else
    {
        std::cout << " there is no path between " << start << " & " << end << "\n";
    }

    res = hasPath_bfs(graph_adj, start, end);

    std::cout << " \nBFS\n";

    if (res == true)
    {
        std::cout << " there is a path between " << start << " & " << end << "\n";
    }
    else
    {
        std::cout << " there is no path between " << start << " & " << end << "\n";
    }

    return 0;
}