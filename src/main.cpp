#include "Game.h"
#include <iostream>

using namespace game::tic_tac_toe;

int main() {
    Game game;
    char player = 'X'; // Player X always starts
    int row, col;
    bool validMove;

    while (true) {
        game.printBoard();
        std::cout << "Player " << player << "'s turn. Enter row and column numbers (0-2): ";
        std::cin >> row >> col;

        validMove = game.makeMove(row, col, player);
        if (!validMove) {
            std::cout << "Invalid move, try again.\n";
            continue;
        }

        if (game.checkWin(player)) {
            game.printBoard();
            std::cout << "Player " << player << " wins!\n";
            break;
        }

        if (game.isBoardFull()) {
            game.printBoard();
            std::cout << "It's a tie!\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
