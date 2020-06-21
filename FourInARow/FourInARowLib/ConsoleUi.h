#pragma once
#include "Ui.h"
#include <memory>

class GameBoard;

class ConsoleUi : public Ui
{
  public:
    int showMultipleChoice(std::string message, std::vector<std::string> answers) const override;


    ~ConsoleUi() override;

    void drawGame(std::shared_ptr<GameBoard> gameBoard) const override;
    int readColumn(std::shared_ptr<GameBoard> gameBoard) const override;
    void showWinner(TeamEnum team) const override;
    void showMessage() const override;

  private:
    std::string tokenToString(const TeamEnum &token) const;
    void clearScreen() const;
};
