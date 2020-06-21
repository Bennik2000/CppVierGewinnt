#pragma once
#include "TeamEnum.h"
#include <string>
#include <vector>
#include <memory>

class GameBoard;

/**
 * This interface is an abstraction for the UI of the four in a row game.
 * It provides methods to interact with the user.
 */
class Ui
{
  public:
    virtual ~Ui() = default;

    virtual void drawGame(std::shared_ptr<GameBoard> gameBoard) const = 0;
    virtual int readColumn(std::shared_ptr<GameBoard> gameBoard) const = 0;
    virtual void showWinner(TeamEnum team) const = 0;
    virtual void showMessage() const = 0;
    virtual int showMultipleChoice(std::string message, std::vector<std::string> answers) const = 0;
};
