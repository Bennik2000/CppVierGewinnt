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
    Player(const std::string &name, const TeamEnum &team, std::shared_ptr<Ui> ui);
    virtual ~Player() = default;

    virtual void play(std::shared_ptr<GameRules> gameRules) = 0;

  protected:
    std::string name;
    TeamEnum team;
    std::shared_ptr<Ui> ui;
};
