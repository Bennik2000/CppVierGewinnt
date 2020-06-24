#include "pch.h"

#include "Player.h"

Player::Player(std::string name, TeamEnum team)
        : name(name)
        , team(team)
{
}

TeamEnum Player::getToken() const
{
    return team;
}
