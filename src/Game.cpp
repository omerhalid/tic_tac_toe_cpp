#include "Game.h"

static constexpr int ROWS {3};
static constexpr int COLS {3};

/// The board is now a 3x3 grid filled with spaces
game::tic_tac_toe::Game::Game() : board(ROWS, std::vector<char>(COLS, ' ')) {}

void game::tic_tac_toe::Game::printBoard()
{
    for(int i=0; i<ROWS; ++i)
    {
      for (int j = 0; j < COLS; ++j) 
        {
            std::cout << '|' << board[i][j];
        }  
        std::cout << "|\n";
        /// Don't print divider after the last row
        if (i < ROWS - 1)
        {
            std::cout << "-----\n";
        }
    }
}

bool game::tic_tac_toe::Game::makeMove(int row, int col, char player)
{
    if(board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else{
        return false;
    }
    return true;
}

bool game::tic_tac_toe::Game::checkRows(char player)
{
    // Check rows
    for(int i = 0; i < ROWS; ++i)
    {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }
    return false;
}

bool game::tic_tac_toe::Game::checkColumns(char player)
{
    // Check columns
    for(int j = 0; j < COLS; ++j)
    {
        if (board[0][j] == player && board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            return true;
        }
    }
    return false;
}

bool game::tic_tac_toe::Game::checkDiagonals(char player)
{
    // Check diagonals
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[0][2] == player && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }
    return false;
}

bool game::tic_tac_toe::Game::checkWin(char player)
{
    
    if (checkRows(player))
    {
        return true;
    }
    if (checkColumns(player))
    {
        return true;
    }
    if (checkDiagonals(player))
    {
        return true;
    }

    return false; // No win found
}

bool game::tic_tac_toe::Game::isBoardFull()
{
    for(int i=0; i<ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if (board[i][j] == ' ')
            {
                return false; // If an empty space is found, the board is not full
            }
        } 
    }
    return true; // If no empty spaces are found, the board is full
}