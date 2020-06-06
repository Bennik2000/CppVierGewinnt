#pragma once
#include "GameRules.h"
#include "Player.h"
#include "Ui.h"
#include <memory>
#include <vector>

/*
 * The game host manages the players, the rules and the game procedure
 */
class GameHost
{
    GameHost(std::vector<Player> players, std::shared_ptr<Ui> ui);

    void startGame();

  private:
    std::vector<Player> players;
    std::shared_ptr<GameRules> gameRules;
    std::shared_ptr<Ui> ui;
};
