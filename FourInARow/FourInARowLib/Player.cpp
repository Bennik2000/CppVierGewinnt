#include "pch.h"

#include "Player.h"

Player::Player(const std::string &name, const TeamEnum &team, std::shared_ptr<Ui> ui)
        : name(name)
        , team(team)
        , ui(ui)
{
}
