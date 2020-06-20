#include "pch.h"

#include "GameBoard.h"

using std::vector;

GameBoard::GameBoard(int height, int width)
    : height(height),
      width(width)
{
    initBoardVector();
}

TeamEnum GameBoard::getTokenAt(int x, int y)
{
    if (isValidCoordinate(x, y))
        return board[y][x];

    return TeamEnum::None;
}

void GameBoard::setTokenAt(int x, int y, TeamEnum token)
{
    if (isValidCoordinate(x, y))
        board[y][x] = token;
}

int GameBoard::getWidth()
{
    return width;
}

int GameBoard::getHeight()
{
    return height;
}

bool GameBoard::isValidCoordinate(int x, int y)
{
    bool xValid = x >= 0 && x < width;
    bool yValid = y >= 0 && y < height;

    return xValid && yValid;
}

void GameBoard::initBoardVector()
{
    board.clear();
    board.reserve(height);

    for (int i = 0; i < height; i++)
    {
        vector<TeamEnum> row;
        row.reserve(width);

        for (int j = 0; j < width; j++)
        {
            row.push_back(TeamEnum::None);
        }

        board.push_back(row);
    }
}
