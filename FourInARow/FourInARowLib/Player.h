#pragma once
#include "GameRules.h"
#include "TeamEnum.h"
#include <string>

/**
 * This class is an abstraction for a player. Override this class to implement
 * bots
 */
class Player
{
  public:
    Player(std::string name, TeamEnum team);
    virtual ~Player() = default;

    virtual void play(std::shared_ptr<GameRules> rules) = 0;
    TeamEnum getToken() const;

  protected:
    std::string name;
    TeamEnum team;
};
