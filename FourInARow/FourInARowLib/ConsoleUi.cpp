#include "ConsoleUi.h"
#include "GameBoard.h"
#include "GameRules.h"
#include <iostream>
#include <string>

// Without NOMINMAX, windows.h defines a max() macro
// which conflicts with std::numeric_limits<std::streamsize>::max().
#define NOMINMAX
#include <windows.h>

int ConsoleUi::showMultipleChoice(const std::string &message,
                                  const std::vector<std::string> &answers) const
{
    int result;

    std::cout << message << std::endl;

    for (int i = 0; i < answers.size(); i++)
    {
        std::cout << i + 1 << ": " << answers[i] << std::endl;
    }

    std::cout << "Answer: ";
    std::cin >> result;

    while (std::cin.fail() || result > answers.size() || result < 1)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "The given answer was invalid! Please enter a new answer: ";
        std::cin >> result;
    }

    return result;
}

void ConsoleUi::showCurrentTeam(const TeamEnum &team) const
{
    std::cout << "Current team: Team ";

    std::string teamString;
    switch (team)
    {
    case TeamEnum::None:
        teamString = "None";
        break;
    case TeamEnum::Blue:
        teamString = colorizeStringByTeam("Blue", team);
        break;
    case TeamEnum::Yellow:
        teamString = colorizeStringByTeam("Yellow", team);
        break;
    }

    std::cout << teamString << std::endl;
}

ConsoleUi::~ConsoleUi()
{
}

void ConsoleUi::drawGame(std::shared_ptr<GameBoard> gameBoard, const TeamEnum &currentTeam) const
{
    clearScreen();

    showCurrentTeam(currentTeam);
    std::cout << std::endl;

    std::cout << "      ";
    for (int x = 0; x < gameBoard->getWidth(); x++)
    {
        std::cout << "{ " << x + 1 << " } ";
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

int ConsoleUi::readValidColumn(std::shared_ptr<GameRules> gameRules) const
{
    int column;

    std::cout << "Column: ";
    std::cin >> column;

    column--;

    while (std::cin.fail() || !gameRules->isValidMove(column))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Your column is inavlid, please select another one!" << std::endl;
        std::cout << "Column: ";
        std::cin >> column;
        column--;
    }

    return column;
}

void ConsoleUi::showWinner(const TeamEnum &team) const
{
    std::string teamString;

    switch (team)
    {
    case TeamEnum::Blue:
        teamString = "Blue";
        break;
    case TeamEnum::Yellow:
        teamString = "Yellow";
        break;
    case TeamEnum::None:
        std::cout << "Game ended in a draw!" << std::endl;
        return;
    }
    std::cout << "Team " << teamString << " has won! Congrats!" << std::endl;
}

void ConsoleUi::showMessage(const std::string &message) const
{
    std::cout << message << std::endl;
}

std::string ConsoleUi::tokenToString(const TeamEnum &token) const
{
    return token != TeamEnum::None ? colorizeStringByTeam("O", token) : " ";
}

std::string ConsoleUi::colorizeStringByTeam(const std::string &string, const TeamEnum &team) const
{
    switch (team)
    {
    case TeamEnum::None:
        return string;
    case TeamEnum::Blue:
        return std::string("\x1B[94m") + string + "\033[0m";
    case TeamEnum::Yellow:
        return std::string("\x1B[33m") + string + "\033[0m";
    }
    return std::string();
}

void ConsoleUi::clearScreen() const
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
    {
        return;
    }

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        return;
    }
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count))
    {
        return;
    }

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
    {
        return;
    }

    // Move the cursor home
    SetConsoleCursorPosition(hStdOut, homeCoords);
}
