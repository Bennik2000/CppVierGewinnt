#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
  public:
    HumanPlayer(const std::string &name, const TeamEnum &team, std::shared_ptr<Ui> ui);
    ~HumanPlayer() override;

    void play(std::shared_ptr<GameRules> gameRules) override;

  private:
    std::shared_ptr<Ui> ui;
};
