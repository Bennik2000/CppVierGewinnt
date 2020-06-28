#include "ConsoleUi.h"
#include "GameHost.h"
#include "HumanPlayer.h"
#include "LeftColumnBot.h"
#include "LowestLineBot.h"
#include "Player.h"
#include "RandomBot.h"
#include "TeamEnum.h"
#include "Ui.h"
#include <memory>




std::shared_ptr<Player> getPlayerByUserChoice(std::shared_ptr<Ui> ui, TeamEnum team)
{
    std::string message;

    if (team == TeamEnum::Yellow)
    {
        message = "What should be the first player?";
    }
    else if (team == TeamEnum::Blue)
    {
        message = "What should be the second player?";
    }

    int choice = ui->showMultipleChoice(message, {"Human player", "Random bot", "Left column bot", "Lowest line bot"});

    if (choice == 1)
    {
        return std::make_shared<HumanPlayer>(
            std::string("Player ") + std::to_string(team), team, ui);
    }

    if (choice == 2)
    {
        return std::make_shared<RandomBot>("Random bot", team);
    }

    if (choice == 3)
    {
        return std::make_shared<LeftColumnBot>("Left column bot", team);
    }
  
      if (choice == 4)
    {
        return std::make_shared<LowestLineBot>("Lowest line bot", team);
    }

    return nullptr;
}

void startGame(std::shared_ptr<Ui> ui)
{
    std::vector<std::shared_ptr<Player>> players;

    players.push_back(getPlayerByUserChoice(ui, TeamEnum::Yellow));
    players.push_back(getPlayerByUserChoice(ui, TeamEnum::Blue));

    std::shared_ptr<GameHost> gameHost = std::make_shared<GameHost>(players, ui);
    gameHost->startGame();
}

int main()
{

    auto ui = std::make_shared<ConsoleUi>();

    bool exit = false;

    while (!exit)
    {
        int choice =
            ui->showMultipleChoice("What would you like to do?", {"Start game", "Exit game"});

        if (choice == 1)
        {
            startGame(ui);
        }
        else
        {
            exit = true;
        }
    }
}
