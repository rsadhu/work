git #include<iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int connectedRegions(vector<vector<int>> grid, int m, int n)
{

    int max = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::queue<std::pair<int, int>> q;

            if (grid[i][j] == 1)
            {
                q.push(std::make_pair(i, j));
                grid[i][j] = -1;
                int count = 0;
                while (!q.empty())
                {
                    auto top = q.front();
                    auto x = top.first;
                    auto y = top.second;
                    q.pop();
                    count++;

                    if (x + 1 < m)
                    {
                        if (grid[x + 1][y] == 1)
                        {
                            q.push(make_pair(x + 1, y));
                            grid[x + 1][y] = -1;
                        }
                    }
                    if (x - 1 >= 0)
                    {
                        if (grid[x - 1][y] == 1)
                        {
                            q.push(make_pair(x - 1, y));
                            grid[x - 1][y] = -1;
                        }
                    }

                    if (y + 1 < n)
                    {
                        if (grid[x][y + 1] == 1)
                        {
                            q.push(make_pair(x, y + 1));
                            grid[x][y + 1] = -1;
                        }
                    }

                    if (y - 1 >= 0)
                    {
                        if (grid[x][y - 1] == 1)
                        {
                            q.push(make_pair(x, y - 1));
                            grid[x][y - 1] = -1;
                        }
                    }

                    if (x + 1 < m && y + 1 < n)
                    {
                        if (grid[x + 1][y + 1] == 1)
                        {
                            q.push(make_pair(x + 1, y + 1));
                            grid[x + 1][y + 1] = -1;
                        }
                    }

                    if (x - 1 >= 0 && y + 1 < n)
                    {
                        if (grid[x - 1][y + 1] == 1)
                        {
                            q.push(make_pair(x - 1, y + 1));
                            grid[x - 1][y + 1] = -1;
                        }
                    }

                    if (x - 1 >= 0 && y - 1 >= 0)
                    {
                        if (grid[x - 1][y - 1] == 1)
                        {
                            q.push(make_pair(x - 1, y - 1));
                            grid[x - 1][y - 1] = -1;
                        }
                    }

                    if (x + 1 < m && y - 1 >= 0)
                    {
                        if (grid[x + 1][y - 1] == 1)
                        {
                            q.push(make_pair(x + 1, y - 1));
                            grid[x + 1][y - 1] = -1;
                        }
                    }
                }

                max = std::max(count, max);
            }
        }
    }

    return max;
}

int main(void)
{
    std::vector<std::vector<int>> map = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1}};

    std::cout << connectedRegions(map, map.size(), map[0].size());
    return 0;
}