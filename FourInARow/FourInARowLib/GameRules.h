#pragma once
#include "GameBoard.h"
#include <memory>
#define REQUIRED_FOR_WINNING 3 // All matching pairs (not Elements!) are counted -->  4 in a row --> 3 || 5 in a row --> 4 ||...

/**
 * This class has methods to validate and make moves, evaluate a winner. It also
 * holds an instance to a game board object.
 */
class GameRules
{
    GameRules();

    bool isValidMove(int column);
    bool placeToken(int column);

    bool checkWinner(TeamEnum team);

    std::shared_ptr<GameBoard> getGameBoard();

  private:
    bool isValidCoord(int x, int y);

    bool checkHorizontalWinner(TeamEnum team);
    bool checkVerticalWinner(TeamEnum team);
    bool checkLeftToTopDiagonalWinner(TeamEnum team);
    bool checkRightToTopDiagonalWinner(TeamEnum team);

    std::shared_ptr<GameBoard> gameBoard;
};
