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

    int currentPlayerIndex = 0;

    ui->drawGame(gameRules->getGameBoard(), players[currentPlayerIndex]->getToken());
    
    while (true)
    {
        const auto currentPlayer = players[currentPlayerIndex];
        const auto currentPlayerToken = currentPlayer->getToken();
        const auto nextPlayerIndex = (currentPlayerIndex + 1) % players.size();

        currentPlayer->play(gameRules);

        ui->drawGame(gameRules->getGameBoard(), players[nextPlayerIndex]->getToken());

        const bool didPlayerWin = gameRules->checkWinner(currentPlayerToken);

        if (didPlayerWin)
        {
            ui->showWinner(currentPlayerToken);
            break;
        }

        if (gameRules->getGameBoard()->isFull())
        {
            ui->showWinner(TeamEnum::None);
            break;
        }

        currentPlayerIndex = nextPlayerIndex;
    }
}

void GameHost::initializeNewGame()
{
    gameRules = std::make_shared<GameRules>();
}
