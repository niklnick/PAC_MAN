#include "Game.h"

Game::Game() {
    _window.setFramerateLimit(60);

    for (auto i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        if (MAZE_LAYOUT[i] == '0') _nodeList[i].wall = false;
        else if (MAZE_LAYOUT[i] == '1') _nodeList[i].wall = true;
    }
}

void Game::pollEvents() {
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
            case Event::Closed:
                _window.close();
                break;
            default:
                break;
            case Event::KeyPressed:
                switch (_event.key.code) {
                    case Keyboard::Escape:
                        _window.close();
                        break;
                    default:
                        break;
                }
        }
    }
}

void Game::update() {
    pollEvents();

    _pacman.update(_window, _nodeList);
}

void Game::render() {
    _window.clear();

    maze::drawMaze(_window, _nodeList);

    _pacman.render(_window, _nodeList);

    _blinky.render(_window, _nodeList);
    _pinky.render(_window, _nodeList);
    _inky.render(_window, _nodeList);
    _clyde.render(_window, _nodeList);

    _window.display();
}

bool Game::isRunning() const {
    return _window.isOpen();
}
