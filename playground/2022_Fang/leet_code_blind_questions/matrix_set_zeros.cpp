#include <vector>
#include <iostream>

using namespace std;

void setRowCol(std::vector<std::vector<int>> &mat, int i, int j)
{
    int left = j, right = j;
    int up = i, down = i;
    mat[i][j] = 0;

    while (up > 0)
    {
        up--;
        if (mat[up][j] != 0)
            mat[up][j] = 0;
    }

    while (down < mat.size() - 1)
    {
        down++;
        if (mat[down][j] != 0)
            mat[down][j] = 0;
    }

    while (left > 0)
    {
        left--;
        if (mat[i][left] != 0)
            mat[i][left] = 0;
    }

    while (right < mat[i].size() - 1)
    {
        right++;
        if (mat[i][right] != 0)
            mat[i][right] = 0;
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    std::vector<std::pair<int, int>> markup;
    for (int i = 0; i < matrix.size(); i++)
    {
        std::pair<int, int> row_col;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row_col.first = i;
                row_col.second = j;

                markup.push_back(row_col);
            }
        }
    }

    for (auto row_col : markup)
    {
        setRowCol(matrix, row_col.first, row_col.second);
    }
}

int main(void)
{
    vector<vector<int>> vec = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(vec);
    for (auto it : vec)
    {
        for (auto c : it)
        {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    return 0;
}