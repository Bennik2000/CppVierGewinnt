#include "pch.h"

#include "GameRules.h"

GameRules::GameRules() {
}

bool GameRules::isValidMove(int column)
{
    return false;
}

bool GameRules::placeToken(int column)
{
    return false;
}

TeamEnum GameRules::checkWinner()
{
    return {};
}

std::shared_ptr<GameBoard> GameRules::getGameBoard()
{
    return {};
}
