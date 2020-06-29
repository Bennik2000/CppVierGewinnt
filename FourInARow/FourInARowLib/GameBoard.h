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
    GameBoard(int width, int height);

    TeamEnum getTokenAt(int x, int y) const;
    void setTokenAt(int x, int y, TeamEnum token);

    int getWidth() const;
    int getHeight() const;
    int getSlotDepth(int column) const;

    bool isValidCoordinate(int x, int y) const;

  private:
    std::vector<std::vector<TeamEnum>> board;
    int width;
    int height;
};
