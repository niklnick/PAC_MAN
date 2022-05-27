#ifndef PAC_MAN_GAME_H
#define PAC_MAN_GAME_H


#include <iostream>

#include "Maze.h"
#include "Pacman.h"
#include "Ghost.h"

class Game {
    VideoMode vM{int(GRID_WIDTH * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH),
                 int(GRID_HEIGHT * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH)};
    RenderWindow _window{vM, "PAC-MAC", Style::Titlebar | Style::Close};
    Event _event{};

    maze::Node _nodeList[GRID_WIDTH * GRID_HEIGHT]{};

    Pacman _pacman{9 + 15 * GRID_WIDTH};

    Ghost _blinky{9 + 8 * GRID_WIDTH, Color::Red};
    Ghost _pinky{8 + 9 * GRID_WIDTH, Color::Magenta};
    Ghost _inky{9 + 9 * GRID_WIDTH, Color::Cyan};
    Ghost _clyde{10 + 9 * GRID_WIDTH, Color{255, 127, 0}};

public:
    Game();

    void pollEvents();

    void update();

    void render();

    [[nodiscard]] bool isRunning() const;
};


#endif //PAC_MAN_GAME_H
