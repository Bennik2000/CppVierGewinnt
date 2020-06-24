#pragma once
#include "TeamEnum.h"
#include <string>
#include <memory>

class Ui;
class GameRules;

/**
 * This class is an abstraction for a player. Override this class to implement
 * a human player or bots
 */
class Player
{
  public:
    Player(const std::string &name, const TeamEnum &team);
    virtual ~Player() = default;

    virtual void play(std::shared_ptr<GameRules> gameRules) = 0;
    TeamEnum getToken() const;

  protected:
    std::string name;
    TeamEnum team;
};
