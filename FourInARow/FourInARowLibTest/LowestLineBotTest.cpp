#include <gtest/gtest.h>
#include <memory>

#include "../FourInARowLib/LowestLineBot.h"
#include "../FourInARowLib/GameRules.h"

TEST(LowestLineBotTest, LeftmostColumnTest)
{
    LowestLineBot lowestLineBot("Bot", TeamEnum::Blue);
    auto rules = std::make_shared<GameRules>();

    rules->placeToken(0, TeamEnum::Yellow);
    rules->placeToken(1, TeamEnum::Yellow);
    
    lowestLineBot.play(rules);
    
    EXPECT_EQ(rules->getGameBoard()->getTokenAt(2, rules->getGameBoard()->getHeight() - 1), TeamEnum::Blue);
}