#pragma once
#include "TeamEnum.h"
#include <memory>
#include <string>
#include <vector>

class GameBoard;
class GameRules;

/**
 * This interface is an abstraction for the UI of the four in a row game.
 * It provides methods to interact with the user.
 */
class Ui
{
  public:
    virtual ~Ui() = default;

    virtual void drawGame(std::shared_ptr<GameBoard> gameBoard,
                          const TeamEnum &currentTeam) const = 0;
    virtual int readValidColumn(std::shared_ptr<GameRules> gameRules) const = 0;
    virtual void showWinner(const TeamEnum &team) const = 0;
    virtual void showMessage(const std::string &message) const = 0;
    virtual int showMultipleChoice(const std::string &message,
                                   const std::vector<std::string> &answers) const = 0;
};
