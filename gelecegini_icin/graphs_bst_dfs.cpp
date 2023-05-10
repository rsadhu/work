#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <list>

void print_bfs(auto graph, auto start_node)
{
    std::cout << "\n";
    std::queue<char> q;

    q.push(start_node);

    while (!q.empty())
    {
        std::cout << q.front() << " ";
        for (auto it : graph[q.front()])
        {
            q.push(it);
        }
        q.pop();
    }
}

void print_dfs(auto graph, auto node)
{
    std::cout << "\n";
    std::stack<char> q;
    q.push(node);

    while (!q.empty())
    {
        node = q.top();
        std::cout << node << " ";
        q.pop();

        auto list = graph[node];

        for (auto it : list)
        {
            q.push(it);
        }
    }
}

void print_dfs_rec(auto graph, auto start_node)
{
    std::cout << start_node << " ";

    auto list = graph[start_node];
    for (auto it : list)
    {
        print_dfs_rec(graph, it);
    }
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

    auto start_node = 'a';

    std::cout << "\nbfs_iter=>";

    print_bfs(graph_adj, start_node);

    std::cout << "\ndfs_iter=>";
    print_dfs(graph_adj, start_node);

    std::cout << "\ndfs_rec=>\n";

    print_dfs_rec(graph_adj, start_node);

    return 0;
}