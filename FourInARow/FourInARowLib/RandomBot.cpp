#include "RandomBot.h"
#include "GameRules.h"
#include <chrono>

RandomBot::RandomBot(std::string name, TeamEnum team)
        : Player(name, team)
        , randomNumberGenerator(std::chrono::high_resolution_clock::now().time_since_epoch().count())
{

}

void RandomBot::play(std::shared_ptr<GameRules> rules)
{
    bool didPlay = false;

    while (!didPlay)
    {
        int move = randomNumberGenerator() % rules->getGameBoard()->getWidth();

        if (rules->isValidMove(move))
        {
            rules->placeToken(move, team);
            didPlay = true;
        }
    }
}
