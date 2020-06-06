#pragma once
#include "Player.h"
#include "Ui.h"
#include <memory>
#include <vector>
#include "GameRules.h"

class GameHost
{
    GameHost(std::vector<Player> players, std::shared_ptr<Ui> ui);

    void startGame();

    
private:
    std::vector<Player> players;
    std::shared_ptr<GameRules> gameRules;
    std::shared_ptr<Ui> ui;
};
