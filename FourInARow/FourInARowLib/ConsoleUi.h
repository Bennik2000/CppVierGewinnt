#pragma once
#include "Ui.h"

class ConsoleUi : public Ui
{
  public:
    int showMultipleChoice(std::string message, std::vector<std::string> answers) override;
};