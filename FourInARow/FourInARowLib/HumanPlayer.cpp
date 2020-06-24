#include "pch.h"
#include "HumanPlayer.h"
#include "GameRules.h"
#include "Ui.h"

HumanPlayer::HumanPlayer(const std::string &name, const TeamEnum &team, std::shared_ptr<Ui> ui)
        : Player(name, team)
        , ui(ui)
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::play(std::shared_ptr<GameRules> gameRules)
{
    int column = ui->readValidColumn(gameRules);
    gameRules->placeToken(column, team);
}
