#include "pch.h"

#include "GameRules.h"

GameRules::GameRules() {
}

bool GameRules::isValidMove(int column) {
    return false;
}

bool GameRules::placeToken(int column) {
    return false;
}

std::shared_ptr<GameBoard> GameRules::getGameBoard() {
    return {};
}

bool GameRules::isValidCoord(int x, int y) {
    if (x >= 0 && y >= 0 && x < gameBoard->getWidth() && y < gameBoard->getHeight()) {
        return true;
    }
    return false;
}

bool GameRules::checkWinner(TeamEnum team) {
    if (checkHorizontalWinner(team)) {
        return true;
    }

    if (checkVerticalWinner(team)) {
        return true;
    }
    if (checkLeftToTopDiagonalWinner(team)) {
        return true;
    }
    if (checkRightToTopDiagonalWinner(team)) {
        return true;
    }

    return false;
}
bool GameRules::checkHorizontalWinner(TeamEnum team) {
    int counter = 0;

    for (int y = 0; y < gameBoard->getHeight(); y++) {
        counter = 0;
        for (int x = 0; x < (gameBoard->getWidth() - 1); x++) {
            if (gameBoard->getTokenAt(x, y) == gameBoard->getTokenAt((x + 1), y) && gameBoard->getTokenAt(x, y) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    return true;
                }
            }
            else {
                counter = 0;
            }
        }
    }

    return false;
}

bool GameRules::checkVerticalWinner(TeamEnum team) {
    int counter = 0;

    for (int x = 0; x < gameBoard->getWidth(); x++) {
        counter = 0;

        for (int y = (gameBoard->getHeight() - 1); y > 0; y--) {
            if (gameBoard->getTokenAt(x, y) == gameBoard->getTokenAt(x, (y - 1)) && gameBoard->getTokenAt(x, y) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    return true;
                }
            }
            else {
                counter = 0;
            }
        }
    }

    return false;
}

bool GameRules::checkLeftToTopDiagonalWinner(TeamEnum team) {
    int counter = 0;
    int diagonalX, diagonalY;

    for (int x = 0; x < (gameBoard->getWidth() - 3); x++) {
        diagonalX = x;
        diagonalY = (gameBoard->getHeight() - 1);

        while (isValidCoord((diagonalX + 1), (diagonalY - 1))) {
            if (gameBoard->getTokenAt(diagonalX, diagonalY) == gameBoard->getTokenAt((diagonalX + 1), (diagonalY - 1)) &&
                gameBoard->getTokenAt(diagonalX, diagonalY) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    return true;
                }
            }
            else {
                counter = 0;
            }

            diagonalX++;
            diagonalY--;
        }
    }

    for (int y = (gameBoard->getHeight() - 2); y > 2; y--) {
        diagonalX = 0;
        diagonalY = y;

        while (isValidCoord((diagonalX + 1), (diagonalY - 1))) {
            if (gameBoard->getTokenAt(diagonalX, diagonalY) == gameBoard->getTokenAt((diagonalX + 1), (diagonalY - 1)) &&
                gameBoard->getTokenAt(diagonalX, diagonalY) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    true;
                }
            }
            else {
                counter = 0;
            }

            diagonalX++;
            diagonalY--;
        }
    }

    return false;
}

bool GameRules::checkRightToTopDiagonalWinner(TeamEnum team) {
    int counter = 0;
    int diagonalX, diagonalY;

    for (int x = (gameBoard->getWidth() - 1); x > 2; x--) {
        diagonalX = x;
        diagonalY = (gameBoard->getHeight() - 1);

        while (isValidCoord((diagonalX - 1), (diagonalY - 1))) {
            if (gameBoard->getTokenAt(diagonalX, diagonalY) == gameBoard->getTokenAt((diagonalX - 1), (diagonalY - 1)) &&
                gameBoard->getTokenAt(diagonalX, diagonalY) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    return true;
                }
            }
            else {
                counter = 0;
            }

            diagonalX--;
            diagonalY--;
        }
    }

    for (int y = (gameBoard->getHeight() - 2); y > 2; y--) {
        diagonalX = gameBoard->getWidth() - 1;
        diagonalY = y;

        while (isValidCoord((diagonalX - 1), (diagonalY - 1))) {
            if (gameBoard->getTokenAt(diagonalX, diagonalY) == gameBoard->getTokenAt((diagonalX - 1), (diagonalY - 1)) &&
                gameBoard->getTokenAt(diagonalX, diagonalY) == team) {
                counter++;
                if (counter == REQUIRED_FOR_WINNING) {
                    return true;
                }
            }
            else {
                counter = 0;
            }

            diagonalX--;
            diagonalY--;
        }
    }

    return false;
}
