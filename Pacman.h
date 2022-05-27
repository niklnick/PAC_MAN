#ifndef PAC_MAN_PACMAN_H
#define PAC_MAN_PACMAN_H


#include "Character.h"
#include "Maze.h"

enum Direction{IDLE = 0, UP = -GRID_WIDTH, RIGHT = 1, DOWN = +GRID_WIDTH, LEFT = -1};

class Pacman : public Character {
    Direction _dir;

public:
    Pacman() = delete;

    explicit Pacman(const unsigned int &);

    void move(maze::Node *);

    void updateInput();

    void update(const RenderTarget &, maze::Node *);

    void render(RenderTarget &, maze::Node *);
};


#endif //PAC_MAN_PACMAN_H
