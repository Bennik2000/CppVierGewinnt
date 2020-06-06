#pragma once
#include "GameBoard.h"
#include <memory>

/**
 * This class has methods to validate and make moves, evaluate a winner. It also
 * holds an instance to a game board object.
 */
class GameRules
{
    GameRules();

    bool isValidMove(int column);
    bool placeToken(int column);

    TeamEnum checkWinner();

    std::shared_ptr<GameBoard> getGameBoard();

  private:
    std::shared_ptr<GameBoard> gameBoard;
};
