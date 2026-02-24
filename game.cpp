#include "game.h"

#include "mesFonctions.h"

/***********************************************/
/* CODEZ ICI LES MÉTHODES DE LA CLASSE "GAME". */
/***********************************************/
Game::Game() {
    _currentPlayerIndex = 0;
    _gameOver = false;
}

Game::~Game() {
    _currentPlayerIndex = 0;
    _gameOver = true;
}

void Game::play(std::ostream &sortie) {
    while (!_gameOver) {
        draw(sortie);

        while (_grids[_currentPlayerIndex].placeHit(getMouseClick())) {};

        draw(sortie);
        sleepMs(500);
        ignoreMouseClicks();

        if (_grids[_currentPlayerIndex].getNbRemainingShips() > 0) {
            _currentPlayerIndex++;
            if (_currentPlayerIndex >= GAME_NB_PLAYERS)
                _currentPlayerIndex = 0;
        } else {
            _gameOver = true;
        }

    }
    draw(sortie);
}

void Game::draw(std::ostream &output) const {
    clearScreen(output);
    if (_gameOver)
        output << "game over!\n";
    else {
        goToXY(1,1);
        std::cout << "BattleShip, fumo edition : click grid to fiwe";
        goToXY(1,2);
        std::cout << "Player " << _currentPlayerIndex << "'s turn";
        _grids[_currentPlayerIndex].printShipsStatus(output);

    }
}

std::ostream & operator<<(std::ostream &output, const Game &game) {
    game.draw(output);
    return output;
}
