#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    bool traverse(vector<vector<char>> grid, int row, int col, std::set<std::string> &visited)
    {
        if (row > grid.size() - 1 || col > grid[0].size() - 1 || row < 0 || col < 0)
            return false;

        if (grid[row][col] == '0')
            return false;

        auto node = std::to_string(row) + "," + std::to_string(col);

        if (visited.count(node) != 0)
            return false;

        visited.insert(node);

        traverse(grid, row + 1, col, visited);
        traverse(grid, row - 1, col, visited);
        traverse(grid, row, col + 1, visited);
        traverse(grid, row, col - 1, visited);

        return true;
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int counter = 0;
        std::set<std::string> visited;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (traverse(grid, i, j, visited))
                    counter++;
            }
        }

        return counter;
    }
};

int main(void)
{
    Solution s;
    vector<vector<char>> grp =
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};

    auto cnt = s.numIslands(grp);
    std::cout << cnt;
    return 0;
}