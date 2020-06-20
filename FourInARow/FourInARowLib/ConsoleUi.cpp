#include "pch.h"

#include "ConsoleUi.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

int ConsoleUi::showMultipleChoice(std::string message, std::vector<std::string> answers) const
{
    int result;

    std::cout << message << std::endl;

    for (int i = 0; i < answers.size(); i++) {
        std::cout << i + 1 << ": " << answers[i] << std::endl;
    }

    std::cout << "Answer: ";
    std::cin >> result;

    while (result > answers.size() || result < 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "The given answer was invalid! Please enter a new answer: ";
        std::cin >> result;
    }

    return result;
}

ConsoleUi::~ConsoleUi()
{
}

void ConsoleUi::drawGame(std::shared_ptr<GameBoard> gameBoard) const
{
    for (int x = 0; x < gameBoard->getWidth(); x++)
    {
        std::cout << "{ " << x << " } ";
    }
    std::cout << std::endl;

    for (int y = 0; y < gameBoard->getHeight(); y++)
    {
        std::cout << "{ " << y << " } ";
        for (int x = 0; x < gameBoard->getWidth(); x++)
        {
            std::cout << "[ " << tokenToString(gameBoard->getTokenAt(x, y)) << " ] ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int ConsoleUi::readColumn() const
{
    return 0;
}

void ConsoleUi::showWinner(TeamEnum team) const
{
}

void ConsoleUi::showMessage() const
{
}

std::string ConsoleUi::tokenToString(const TeamEnum &token) const
{
    switch (token)
    {
    case TeamEnum::None:
        return " ";
    case TeamEnum::Blue:
        return "\x1B[34mO\033[0m";
    case TeamEnum::Yellow:
        return "\x1B[33mO\033[0m";
    }
}
