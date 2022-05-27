#ifndef PAC_MAN_GAME_H
#define PAC_MAN_GAME_H


#include <iostream>

#include "Maze.h"
#include "Pacman.h"

class Game {
    VideoMode vM{int(GRID_WIDTH * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH),
                 int(GRID_HEIGHT * (NODE_SIZE + NODE_BORDER_WIDTH) + NODE_BORDER_WIDTH)};
    RenderWindow _window{vM, "PAC-MAC", Style::Titlebar | Style::Close};
    Event _event{};

    Maze::Node _nodeList[GRID_WIDTH * GRID_HEIGHT]{};

    float _movementSpeed{4.f}, _radius{16.f};
    Pacman _pacman{_movementSpeed, _radius};

public:
    Game();

    void pollEvents();

    void update();

    void render();

    [[nodiscard]] bool isRunning() const;
};


#endif //PAC_MAN_GAME_H
