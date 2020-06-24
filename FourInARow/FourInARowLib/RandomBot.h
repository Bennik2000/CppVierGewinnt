#pragma once
#include "Player.h"
#include <random>

class RandomBot : public Player
{
  public:
    RandomBot(std::string name, TeamEnum team);

  public:
    void play(std::shared_ptr<GameRules> rules) override;

  private:
    std::mt19937 randomNumberGenerator;
};
