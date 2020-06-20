#pragma once
#include "Ui.h"

class ConsoleUi : public Ui
{
  public:
    int showMultipleChoice(std::string message, std::vector<std::string> answers) const override;


    ~ConsoleUi() override;

    void drawGame() const override;
    int readColumn() const override;
    void showWinner(TeamEnum team) const override;
    void showMessage() const override;
};