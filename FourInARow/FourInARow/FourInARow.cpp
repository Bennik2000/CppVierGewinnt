#include "ConsoleUi.h"
#include "GameHost.h"
#include "Player.h"
#include "Ui.h"
#include "HumanPlayer.h"
#include <memory>

std::shared_ptr<Player> getPlayerByUserChoice(std::shared_ptr<Ui> ui, int player)
{
    std::string message;

    if (player == 0)
    {
        message = "What should be the first player?";
    }
    else if (player == 1)
    {
        message = "What should be the second player?";
    }

    int choice = ui->showMultipleChoice(message, {"Human player", "Bot player"});

    if (choice == 1)
    {
        return std::make_shared<HumanPlayer>(std::string("Player ") + std::to_string(player), player, ui);
    }
    else
    {
        return nullptr; // TODO: Return bot player instance
    }
}

void startGame(std::shared_ptr<Ui> ui)
{
    std::vector<std::shared_ptr<Player>> players;

    players.push_back(getPlayerByUserChoice(ui, 0));
    players.push_back(getPlayerByUserChoice(ui, 1));

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
