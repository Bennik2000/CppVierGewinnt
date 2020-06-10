#pragma once
#include "Ui.h"

class ConsoleUi : public Ui
{
  public:
    int showMultipleChoice(std::string message, std::vector<std::string> answers) override;


    ~ConsoleUi() override;

    void drawGame() override;
    int readColumn() override;
    void showWinner(TeamEnum team) override;
    void showMessage() override;
};