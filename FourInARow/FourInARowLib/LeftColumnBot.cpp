#include "GameRules.h"
#include "LeftColumnBot.h"

LeftColumnBot::LeftColumnBot(const std::string &name, const TeamEnum &team)
        : Player(name, team)
{
}

void LeftColumnBot::play(std::shared_ptr<GameRules> gameRules)
{
    for (int i = 0; i < gameRules->getGameBoard()->getWidth(); i++)
    {
        if (gameRules->isValidMove(i))
        {
            gameRules->placeToken(i, team);
            return;
        }
    }
}
