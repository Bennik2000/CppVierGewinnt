#include "pch.h"

#include "GameHost.h"
#include <memory>

GameHost::GameHost(std::vector<std::shared_ptr<Player>> &players, std::shared_ptr<Ui> &ui)
        : players(players)
        , ui(ui)
{
}

void GameHost::startGame()
{
    initializeNewGame();

    ui->drawGame(gameRules->getGameBoard(), players[0]->getToken());

    int currentPlayerIndex = 0;

    while (true)
    {
        const auto currentPlayer = players[currentPlayerIndex];
        const auto currentPlayerToken = currentPlayer->getToken();

        currentPlayer->play(gameRules);

        ui->drawGame(gameRules->getGameBoard(), currentPlayerToken);

        const bool didPlayerWin = gameRules->checkWinner(currentPlayerToken);

        if (didPlayerWin)
        {
            ui->showWinner(currentPlayerToken);
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
}

void GameHost::initializeNewGame()
{
    gameRules = std::make_shared<GameRules>();
}
