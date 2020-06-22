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
public : 
    GameRules();

    bool isValidMove(int column) const;
    bool placeToken(int column, TeamEnum team);

    bool checkWinner(TeamEnum team) const;

    std::shared_ptr<GameBoard> getGameBoard() const;

  private:
    bool checkHorizontalWinner(TeamEnum team) const;
    bool checkVerticalWinner(TeamEnum team) const;
    bool checkLeftToTopDiagonalWinner(TeamEnum team) const;
    bool checkRightToTopDiagonalWinner(TeamEnum team) const;

    std::shared_ptr<GameBoard> gameBoard;
};
