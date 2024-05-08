#include "common.h"

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::unordered_set<char> row[9], col[9], grid;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (row[i].find(board[i][j]) != row[i].end() ||
                    col[j].find(board[i][j]) != col[j].end() //||
                                                             //  grid.find(board[i][j]) != grid.end()
                )
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                //  grid.insert(board[i / 3][j / 3]);
            }
        }
        return true;
    }
};

int main(void)
{

    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    std::cout << s.isValidSudoku(board);
    return 0;
}