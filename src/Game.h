// Game.h
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

namespace game
{
namespace tic_tac_toe
{

class Game {
public:
    Game();  // Constructor to initialize the game board
    void printBoard();
    bool makeMove(int row, int col, char player);
    bool checkWin(char player);
    bool isBoardFull();

private:
    std::vector<std::vector<char>> board;
    bool checkRows(char player);
    bool checkColumns(char player);
    bool checkDiagonals(char player);
};

} // namespace tic_tac_toe
} // namespace game

#endif // GAME_H
