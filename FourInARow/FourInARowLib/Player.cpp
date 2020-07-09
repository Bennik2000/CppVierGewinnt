#include "Player.h"

Player::Player(const std::string &name, const TeamEnum &team)
        : name(name)
        , team(team)
{
}

TeamEnum Player::getToken() const
{
    return team;
}
