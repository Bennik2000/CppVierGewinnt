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
    int count;

    for (int x = 0; x < rules->getGameBoard()->getWidth(); x++)
    {
        count = 0;

        for (int y = 0; y < rules->getGameBoard()->getHeight(); y++)
        {
            if (rules->getGameBoard()->getTokenAt(x, y) != TeamEnum::None)
            {
                count++;
            }
        }

        if (count < lowestValue)
        {
            lowestValue = count;
            move = x;
        }
    }

    rules->placeToken(move, team);
}
