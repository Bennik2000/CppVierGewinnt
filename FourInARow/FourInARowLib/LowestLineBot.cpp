#include "pch.h"

#include "GameRules.h"
#include "LowestLineBot.h"


LowestLineBot::LowestLineBot(std::string name, TeamEnum team)
        : Player(name, team)
{
}

void LowestLineBot::play(std::shared_ptr<GameRules> rules)
{
    int move = 0;
    int lowestValue = rules->getGameBoard()->getHeight();
    int slotDepth;

    for (int x = 0; x < rules->getGameBoard()->getWidth(); x++)
    {
        slotDepth = rules->getGameBoard()->getSlotDepth(x);

        if (slotDepth < lowestValue)
        {
            lowestValue = slotDepth;
            move = x;
        }
    }

    rules->placeToken(move, team);
}
