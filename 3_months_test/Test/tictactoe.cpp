// this is the first task

// Create a function that takes an array of char inputs from a Tic Tac Toe game. Inputs will be taken from player1 as "X", player2 as "O", and empty spaces as " ". 
// The program will return the winner or tie results.


 

// ticTacToe([  
//     ["X", "", "O"],  
//     ["O", "X", "O"],  
//     ["O", " ", "X"] ]) 
    
// ➞ "Player 1 wins"

// ticTacToe([  ["X", "O", "O"],  ["O", "X", "O"],  ["X", " ", "O"] ]) ➞ "Player 2 wins"  


// ticTacToe([  ["X", "X", "O"],  ["O", "X", "X"],  ["X", "O", "O"] ]) ➞ "It's a Tie"

#include <vector>
#include <string>
#include <iostream>


std::string 
ticTacToe(std::vector<std::vector<char>> &ttt)
{

for (int row = 0; row < ttt.size() -1 ; row++)
{
    bool won = true;
    int col = 0;
    for (col = 0; col < ttt.size() -1 ; col++)
    {
        if (ttt[row][col] != ttt[row][col+1])
        {
            won = false;
            break;
        }
    }

     if (won)
    {

        if (ttt[row][col] == 'X')
            return "X";
        
    }
    
    won = true;
    col = 0;
    for ( col = 0; col < ttt.size() -1 ; col++)
    {
        if (ttt[col][row] != ttt[col+1][row])
        {
            won = false;
            break;
        }
    }


    if (won)
    {

        if (ttt[row][col] == 'X')
            return "X";
        
    }

    //if (ttt[row][row] == ttt[row+1][row[+1]])
}

}




int main(void)
{
    std::vector<std::vector<char>> ttt = {
        {'X', 'O', 'O'},  
        {'O', 'X', 'O'},  
        {'X', ' ', 'O'} 
        };
    std::cout<<" who won "<< ticTacToe(ttt);
    return 0;
}

