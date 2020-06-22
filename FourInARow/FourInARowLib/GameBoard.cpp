#include "pch.h"

#include "GameBoard.h"

using std::vector;

GameBoard::GameBoard(int width, int height)
        : width(width)
        , height(height)
        , board(width, vector<TeamEnum>(height, TeamEnum::None))
{
}

TeamEnum GameBoard::getTokenAt(int x, int y) const
{
    if (isValidCoordinate(x, y))
    {
        return board[x][y];
    }
    else
    {
        return TeamEnum::None;
    }
}

void GameBoard::setTokenAt(int x, int y, TeamEnum token)
{
    if (isValidCoordinate(x, y))
    {
        board[x][y] = token;
    }
}

int GameBoard::getWidth() const
{
    return width;
}

int GameBoard::getHeight() const
{
    return height;
}

bool GameBoard::isValidCoordinate(int x, int y) const
{
    bool xValid = x >= 0 && x < width;
    bool yValid = y >= 0 && y < height;

    return xValid && yValid;
}
