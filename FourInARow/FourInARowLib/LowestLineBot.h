#pragma once
#include "Player.h"
class LowestLineBot : public Player
{
  public:
    LowestLineBot(std::string name, TeamEnum team);

    void play(std::shared_ptr<GameRules> rules) override;
};
