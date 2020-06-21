#pragma once
#include "Ui.h"
#include <memory>

class GameBoard;

class ConsoleUi : public Ui
{
  public:
    ~ConsoleUi() override;

    void drawGame(std::shared_ptr<GameBoard> gameBoard) const override;
    int readColumn(std::shared_ptr<GameBoard> gameBoard) const override;
    void showWinner(const TeamEnum &team) const override;
    void showMessage(const std::string &message) const override;
    int showMultipleChoice(const std::string &message, const std::vector<std::string> &answers) const override;

  private:
    std::string tokenToString(const TeamEnum &token) const;
    void clearScreen() const;
};
