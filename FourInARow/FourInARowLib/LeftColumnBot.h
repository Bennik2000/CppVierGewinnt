#pragma once

#include "Player.h"

class LeftColumnBot : public Player
{
  public:
    LeftColumnBot(const std::string &name, const TeamEnum &team);

    ~LeftColumnBot() override = default;
    void play(std::shared_ptr<GameRules> gameRules) override;
};
