#pragma once
#include "TeamEnum.h"
#include <vector>

/**
 * This class manages the board of the four in a row game. It provides functions to
 * retrieve or set the board data
 */
class GameBoard
{
public:
    GameBoard(int height, int width);

    TeamEnum getTokenAt(int x, int y);
    void setTokenAt(int x, int y, TeamEnum token);

    int getWidth();
    int getHeight();

    bool isValidCoordinate(int x, int y);

  private:
    std::vector<std::vector<TeamEnum>> board;
    int height;
    int width;

    void initBoardVector();
};
