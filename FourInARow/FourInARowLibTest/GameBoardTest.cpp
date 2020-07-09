#include <gtest/gtest.h>

#include "../FourInARowLib/GameBoard.h"
#include "../FourInARowLib/TeamEnum.h"

TEST(GameBoardTest, GameBoardEmptyOnInitTest) {
    GameBoard board(3, 4);

    for (int x = 0; x < board.getWidth(); x++)
    {
        for (int y = 0; y < board.getHeight(); y++)
        {
            EXPECT_EQ(board.getTokenAt(x, y), TeamEnum::None) << "Board at position " << x << ", " << y << " not empty!" << std::endl;
        }
    }
}

TEST(GameBoardTest, SetTokenAtGetTokenAtTest)
{
    GameBoard board(1, 1);
    board.setTokenAt(0, 0, TeamEnum::Blue);
    EXPECT_EQ(board.getTokenAt(0, 0), TeamEnum::Blue);
}

TEST(GameBoardTest, GetTokenAtFailTest)
{
    GameBoard board(1, 1);
    EXPECT_EQ(board.getTokenAt(2, 2), TeamEnum::None);
}

TEST(GameBoardTest, GetSlotDepthTest)
{
    GameBoard board(1, 5);
    board.setTokenAt(0, 0, TeamEnum::Blue);
    board.setTokenAt(0, 1, TeamEnum::Blue);
    board.setTokenAt(0, 2, TeamEnum::Blue);

    EXPECT_EQ(board.getSlotDepth(0), 3);
}

TEST(GameBoardTest, GetSlotDepthInvalidSlotTest)
{
    GameBoard board(1, 5);

    EXPECT_EQ(board.getSlotDepth(2), -1);
}

TEST(GameBoardTest, IsValidCoordinateValidTest)
{
    GameBoard board(1, 1);

    EXPECT_EQ(board.isValidCoordinate(0, 0), true);
}

TEST(GameBoardTest, IsInvalidCoordinateInvalidTest)
{
    GameBoard board(1, 1);

    EXPECT_EQ(board.isValidCoordinate(3, 3), false);
}

TEST(GameBoardTest, IsFullTest)
{
    GameBoard board(1, 1);
    board.setTokenAt(0, 0, TeamEnum::Blue);

    EXPECT_EQ(board.isFull(), true);
}

TEST(GameBoardTest, IsFullOnEmptyBoardTest)
{
    GameBoard board(1, 1);

    EXPECT_EQ(board.isFull(), false);
}