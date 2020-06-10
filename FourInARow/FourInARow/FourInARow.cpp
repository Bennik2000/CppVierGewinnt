#include "ConsoleUi.h"
#include "GameHost.h"
#include "Player.h"
#include "Ui.h"
#include <memory>

std::shared_ptr<Player> getPlayerByUserChoice(std::shared_ptr<Ui> ui, int player) {
    std::vector<std::string> choices;
    choices.push_back("Human player");
    choices.push_back("Bot player");

    std::string message;

    if (player == 0) {
        message = "What should be the first player?";
    }
    else if (player == 1) {
        message = "What should be the second player?";
    }

    int choice = ui->showMultipleChoice(message, choices);

    if (choice == 1) {
        return nullptr; // TODO: Return human player instance
    }
    if (choice == 1) {
        return nullptr; // TODO: Return bot player instance
    }

    return nullptr;
}

void startGame(std::shared_ptr<Ui> ui) {
    std::vector<std::shared_ptr<Player>> players;

    players.push_back(getPlayerByUserChoice(ui, 0));
    players.push_back(getPlayerByUserChoice(ui, 1));

    std::shared_ptr<GameHost> gameHost = std::make_shared<GameHost>(players, ui);
    gameHost->startGame();
}

int main() {

    auto ui = std::make_shared<ConsoleUi>();

    bool exit = false;

    while (!exit) {
        std::vector<std::string> choices;
        choices.push_back("Start game");
        choices.push_back("Exit game");

        int choice = ui->showMultipleChoice("What would you like to do?", choices);

        if (choice == 1) {
            startGame(ui);
        }
        else if (choice == 2) {
            exit = true;
        }
    }
}
