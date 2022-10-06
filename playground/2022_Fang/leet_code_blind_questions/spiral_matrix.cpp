#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    std::vector<int> res;

    int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
    int dir = 1;
    while (left <= right && up <= down)
    {

        if (dir == 1)
        {
            // go right
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            dir = 2;
            up++;
        }

        else if (dir == 2)
        {
            // go down
            for (int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            dir = 3;
        }

        else if (dir == 3)
        {
            // go left

            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            dir = 4;
        }

        else if (dir == 4)
        {
            // go up

            for (int i = down; i >= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            dir = 1;
        }
    }
    return res;
}

int main(void)
{
    std::vector<std::vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    auto res = spiralOrder(mat);

    return 0;
}