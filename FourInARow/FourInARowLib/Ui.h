#pragma once
#include "TeamEnum.h"
#include <string>
#include <vector>

/**
 * This interface is an abstraction for the UI of the four in a row game.
 * It provides methods to interact with the user.
 */
class Ui
{
  public:
    virtual ~Ui() = default;

  private:
    virtual void drawGame() = 0;
    virtual int readColumn() = 0;
    virtual void showWinner(TeamEnum team) = 0;
    virtual void showMessage() = 0;
    virtual int showMultipleChoice(std::string message, std::vector<std::string> answers) = 0;
};
