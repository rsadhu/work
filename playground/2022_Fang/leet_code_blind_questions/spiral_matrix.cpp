#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int right_left = 0, up_down = 0;
    std::vector<int> res;
    int cnt = 0;
    bool abs = true;

    while (abs)
    {
        abs = true;
        // go right
        while (right_left < (matrix[0].size() - cnt))
        {
            res.push_back(matrix[up_down][right_left]);
            right_left++;
            abs = true;
        }

        right_left--;
        // go down
        while (++up_down < (matrix.size() - cnt))
        {
            res.push_back(matrix[up_down][right_left]);
            abs = true;
        }
        up_down--;
        // go left
        while (--right_left >= cnt)
        {
            // right_left--;
            res.push_back(matrix[up_down][right_left]);
            abs = true;
        }

        // go up
        right_left++;
        while (--up_down >= cnt)
        {
            abs = true;
            // up_down--;
            res.push_back(matrix[up_down][right_left]);
        }
        up_down++;

        cnt++;
    }
    return res;
}

int main(void)
{
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    auto res = spiralOrder(mat);

    return 0;
}