#pragma once
#include "TeamEnum.h"
#include <vector>

/**
 * This class manages the board of the four in a row game. It provides functions to
 * retrieve or set the board data
 */
class GameBoard
{
    GameBoard(int height, int width);

    TeamEnum getTokenAt(int x, int y);
    void setTokenAt(int x, int y);

    int getWidth();
    int getHeight();

  private:
    std::vector<std::vector<TeamEnum>> board;
    int height;
    int width;
};
